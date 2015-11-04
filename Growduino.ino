/*
????????
- relayState in EEPROM ???
????????
 */
 
#define REG_SELECT 9
#define IRQ_PIN 2
#define SDA_PIN 7
#define SCL_PIN 8

//------- UART COMMANDS -------
#define CMD_SET_TIME    0x01
#define CMD_PRINT_TIME  0x02
#define CMD_ADD_EVENT   0x03
#define CMD_REL_ON      0x04
#define CMD_REL_OFF     0x05
#define CMD_REL_WAT     0x06
#define CMD_TEST_LINK   0x07
#define CMD_SET_DEFAULT	0x08
#define CMD_CONFIG_DEV	0x09
#define CMD_PORT_VALUE  0x0a
#define DEBUG_1	    0xff
//-----------------------------
#define MAX_RELAY 8
#define MAX_EVENT 12
#define SENS_PORTS_NUM 1
#define MAX_SENS_PORT 4
#define PROB_NUM 3
#define PROB_DELAY_TIME 5
 
#include <Time.h>
#include <TimeAlarms.h>
#include <DS1307.h>
#include <SPI.h> // DEBUG
#include <EEPROM.h>

DS1307 rtc (SDA_PIN, SCL_PIN);

typedef enum {OFF, ON} RelAction;

typedef struct{
    int portID;
    bool binary; //true = bin, false = analog
    bool active;
    int val;	//analog value
    int relID;
    bool flag;	//true(analog): ACTIVE when >val; true(bin): ACTIVE when = flag
    RelAction actState;
} SensConfig;

typedef struct{
   SensConfig ports[MAX_SENS_PORT];
   int portsNum;
} SensList;

SensList sensPortsList;
byte relState;

// the setup function runs once when you press reset or power the board
void setup() {
  
  relState = 0x00;  
  SPI.begin();
  pinMode(REG_SELECT, OUTPUT);
  digitalWrite(REG_SELECT, LOW);
  SPI.transfer(0);
  digitalWrite(REG_SELECT, HIGH);

  rtc.setSQWRate(SQW_RATE_1);
  rtc.enableSQW(true);
  //delay(10);
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  attachInterrupt(0, irq0, RISING);
  setSyncProvider(curUnixTime);
  setSyncInterval(2);
  interrupts();

  sensPortsList.portsNum = 0;
  loadConfig();
  Alarm.timerRepeat(5, servicePorts);
}

void testTimer(){
   Serial.println("TIMER!");
}

//--------------------- LOOP ----------------------------
void loop() {  
  byte cmd;
  if(Serial.available() > 0){
    cmd = Serial.read();
    cmdProc(cmd);
  }
  delay(500);
  
}
//------------------------IRQ-----------------------------
 void irq0(){
   noInterrupts();
   Alarm.serviceAlarms();
   interrupts();
 }
//---------------------------------------------------------

 void cmdProc(byte cmd){
   int h, m, s;
   int mode, relN;
   
   switch (cmd){
      case CMD_TEST_LINK:
        cmd = Serial.read();
        Serial.write(cmd);
        break;
     
      case CMD_REL_ON:
        while(Serial.available() < 1){}
        cmd = Serial.read();
        relOn(cmd);  
        break;
        
      case CMD_REL_OFF:
        while(Serial.available() < 1){}
        cmd = Serial.read();
        relOff(cmd); 
        break;
        
      case CMD_REL_WAT:
        while(Serial.available() < 1){}
        cmd = Serial.read();
        relWat(cmd);
        break;
	
      case CMD_PORT_VALUE:
	while(Serial.available() < 1){}
        cmd = Serial.read();
	Serial.print(analogRead(cmd));
	break;
         
      case CMD_PRINT_TIME:
         Serial.print(rtc.getTimeStr(FORMAT_LONG));
         break;
         
      case CMD_SET_TIME:
        h = Serial.read();
        m = Serial.read();
        s = Serial.read();
        setRTCtime(h, m, s);
        break;
        
       case CMD_ADD_EVENT:
         mode = Serial.read();
         relN = Serial.read();
         h = Serial.read();
         m = Serial.read();
         s = Serial.read();
         addEvent(mode, relN, h, m, s);
         break;
	 
	case CMD_SET_DEFAULT:
	 setDefaultConfig();
	 loadConfig();
	 break;
	 
	case CMD_CONFIG_DEV:
	 configDevice();
	 loadConfig();
	 break;
        
      case DEBUG_1:

        break;
                 
      default: 
         Serial.println("Command error");
   }
 }
 
 void addSens( int portID, bool binary, int val, 
	       int relID, bool flag, int actState){
	int i = sensPortsList.portsNum;
	if(i < MAX_SENS_PORT){
	      sensPortsList.ports[i].active = false;
	      sensPortsList.ports[i].portID = portID;
	      sensPortsList.ports[i].binary = binary;
	      sensPortsList.ports[i].val = val;
	      sensPortsList.ports[i].relID = relID;
	      sensPortsList.ports[i].flag = flag;
	      switch(actState){
	      case 0:
		  sensPortsList.ports[i].actState = OFF;
		  break;
	      case 1:
		  sensPortsList.ports[i].actState = ON;
		  break;
	      }
	      sensPortsList.portsNum++;
	}
 }
  
 void servicePorts(){
   for(int i = 0; i < sensPortsList.portsNum; i++){
      int val = 0;
      if(sensPortsList.ports[i].binary == false){
      //---- proc analog in----------
	 for(int j = 0; j < PROB_NUM; j++){
	    val += analogRead(sensPortsList.ports[i].portID);
	    delay(PROB_DELAY_TIME);
	 }
	 val = val/PROB_NUM;
		 
	 if(((sensPortsList.ports[i].flag == false) and (sensPortsList.ports[i].val < val)) or
	    ((sensPortsList.ports[i].flag == true) and (sensPortsList.ports[i].val > val))){
	    setRelState(sensPortsList.ports[i].relID, sensPortsList.ports[i].actState);
	    sensPortsList.ports[i].active = true;	    
	 }else{
	    RelAction normalState;
	    if(sensPortsList.ports[i].active == true){
	       switch (sensPortsList.ports[i].actState){
	       case OFF:
		  normalState = ON;
		  break;
	       case ON:
		  normalState = OFF;
		  break;
	       }
	       setRelState(sensPortsList.ports[i].relID, normalState);
	       sensPortsList.ports[i].active = false;
	    }
	 }
      }else{
      //---- proc bin port ------
      }
   }
 }
 
 //unsigned long curUnixTime(){
 time_t curUnixTime(){
   tmElements_t tm;
   Time t;
   t = rtc.getTime();
   tm.Hour 	= t.hour;
   tm.Minute 	= t.min;
   tm.Second 	= t.sec;
   tm.Wday 	= t.dow;
   tm.Day 	= t.date;
   tm.Month 	= t.mon;
   tm.Year 	= t.year - 1970;
   return makeTime(tm);
 }
   
 int setRTCtime(int h, int m, int s){
   rtc.setTime(h, m, s); 
   return 0; 
 }
 
 void setRelState(int rel, int act){
   switch(act){
      case 0:
	 relOff(rel);
	 break;
      case 1:
	 relOn(rel);
	 break;
   }
 }
 
  void relOn (int num){
    bitSet(relState, num);
    digitalWrite(REG_SELECT, LOW);
    SPI.transfer(relState);
    digitalWrite(REG_SELECT, HIGH);
 }
 
 void relOff (int num){
    bitClear(relState, num);
    digitalWrite(REG_SELECT, LOW);
    SPI.transfer(relState);
    digitalWrite(REG_SELECT, HIGH);
 }
 
 void relWat(int num){
   int t = 5;
    switch(num){
      case 0:
        rel0_on();
        Alarm.timerOnce(t, rel0_off);
        return;
      case 1:
        rel1_on();
        Alarm.timerOnce(t, rel1_off);
        return;
      case 2:
        rel2_on();
        Alarm.timerOnce(t, rel2_off);
        return;
      case 3:
        rel3_on();
        Alarm.timerOnce(t, rel3_off);
        return;
    } 
 }
 
 void setDefaultConfig(){
      for(int i = 0; i < MAX_RELAY; i++){
	 EEPROM.write(i, 0x00);
      }
 }
 
 void loadConfig(){
      int addr = 0;
      for(int rel = 0; rel < MAX_RELAY; rel++){
	 int eventNum =  EEPROM.read(addr++);
	 if(eventNum > MAX_EVENT) return;
	 for(int i = 0; i < eventNum; i++){
	    int mode =  EEPROM.read(addr++);
	    int h =  EEPROM.read(addr++);
	    int m =  EEPROM.read(addr++);
	    int s =  EEPROM.read(addr++);
	    addEvent(mode, rel, h, m, s);
	 }
	 int sensNum = EEPROM.read(addr++);
	 for(int i = 0; i < sensNum; i++){
	    int portID = EEPROM.read(addr++);
	    
	    int bVal = EEPROM.read(addr++);
	    bVal += EEPROM.read(addr++) * 10;
	    bVal += EEPROM.read(addr++) * 100;
	    bVal += EEPROM.read(addr++) * 1000;
	    
	    bool flag = EEPROM.read(addr++);
	    int act =  EEPROM.read(addr++);
	    addSens(portID, false, bVal, rel, flag, act);
	 }
      }
 }
  
 void configDevice(){
      int addr = 0;
      while(true){
	 if(Serial.available() > 0){;
	    byte cmd = Serial.read();
	    if(cmd == 0xff) return;
	    EEPROM.write(addr++, cmd);  
	 }
      }
      //loadConfig(); //DEBUG
 }
  
 void rel0_on(){relOn(0);}
 void rel0_off(){relOff(0);}
 
 void rel1_on(){relOn(1);}
 void rel1_off(){relOff(1);}
 
 void rel2_on(){relOn(2);}
 void rel2_off(){relOff(2);}
 
 void rel3_on(){relOn(3);}
 void rel3_off(){relOff(3);}
 
 void rel4_on(){relOn(4);}
 void rel4_off(){relOff(4);}
 
 void rel5_on(){relOn(5);}
 void rel5_off(){relOff(5);}
 
 void rel6_on(){relOn(6);}
 void rel6_off(){relOff(6);}
 
 void rel7_on(){relOn(7);}
 void rel7_off(){relOff(7);}
 
 void addEvent(int mode, int relN, int h, int m, int s){
    switch(mode){
    case 0:
       switch(relN){
       case 0:
         Alarm.alarmRepeat(h, m, s, rel0_off); 
         break;
       case 1:
         Alarm.alarmRepeat(h, m, s, rel1_off); 
         break;
       case 2:
         Alarm.alarmRepeat(h, m, s, rel2_off); 
         break;
       case 3:
         Alarm.alarmRepeat(h, m, s, rel3_off); 
         break;
       case 4:
         Alarm.alarmRepeat(h, m, s, rel4_off); 
         break;
       case 5:
         Alarm.alarmRepeat(h, m, s, rel5_off); 
         break;
       case 6:
         Alarm.alarmRepeat(h, m, s, rel6_off); 
         break;
       case 7:
         Alarm.alarmRepeat(h, m, s, rel7_off); 
         break;
        } 
	return;
      case 1:
       switch(relN){
       case 0:
         Alarm.alarmRepeat(h, m, s, rel0_on); 
         break;
       case 1:
         Alarm.alarmRepeat(h, m, s, rel1_on); 
         break;
       case 2:
         Alarm.alarmRepeat(h, m, s, rel2_on); 
         break;
       case 3:
         Alarm.alarmRepeat(h, m, s, rel3_on); 
         break;
       case 4:
         Alarm.alarmRepeat(h, m, s, rel4_on); 
         break;
       case 5:
         Alarm.alarmRepeat(h, m, s, rel5_on); 
         break;
       case 6:
         Alarm.alarmRepeat(h, m, s, rel6_on); 
         break;
       case 7:
         Alarm.alarmRepeat(h, m, s, rel7_on); 
         break;
        } 
	return;
    }
 }
