#include "growduino.h"

Growduino::Growduino(QObject *parent) : QSerialPort(parent)
{
    deleteAll();
}

Growduino::~Growduino()
{
    this->close();
}

void Growduino::deleteAll()
{
    for(int i = 0; i < MAX_RELAY; i++){
        relEventNum[i] = 0;
        relSensNum[i] = 0;
    }
}

bool Growduino::initPort(QString name){
    this->close();
    this->setPortName(name);
    this->setBaudRate(9600);
    return this->open(QIODevice::ReadWrite);
}

bool Growduino::initPort(QString name, int rate){
    this->close();
    this->setPortName(name);
    this->setBaudRate(rate);
    return this->open(QIODevice::ReadWrite);
}

int Growduino::setTime(){
    this->putChar(CMD_SET_TIME);
    this->putChar(QTime::currentTime().hour());
    this->putChar(QTime::currentTime().minute());
    this->putChar(QTime::currentTime().second());
    return 0;
}

int Growduino::printTime(){
    this->putChar(CMD_PRINT_TIME);
    return 0;
}

int Growduino::configDevice(){
    this->putChar(CMD_CONFIG_DEV);
    for (int rel = 0; rel < MAX_RELAY; rel++){
        this->putChar(relEventNum[rel]);
        for(int i = 0; i < relEventNum[rel]; i++){
            RelEvent event = relSheduler[rel][i];
            this->putChar(ActToInt(event.action));
            this->putChar(event.time.hour());
            this->putChar(event.time.minute());
            this->putChar(event.time.second());
        }
        this->putChar(relSensNum[rel]);
        for(int i = 0; i < relSensNum[rel]; i++){
            RelSens sens = relSensList[rel][i];
            this->putChar(sens.portID);

            int tmp = sens.bVal;
            int buf = tmp%10;
            this->putChar(buf);
            tmp = tmp/10;
            buf = tmp%10;
            this->putChar(buf);
            tmp = tmp/10;
            buf = tmp%10;
            this->putChar(buf);
            tmp = tmp/10;
            buf = tmp%10;
            this->putChar(buf);

            this->putChar(sens.flag);
            this->putChar(sens.action);
        }
    }
    this->putChar(0xff);
    return 0;
}

void Growduino::relOn(int n){
    this->putChar(CMD_REL_ON);
    this->putChar(n);
}

void Growduino::relOff(int n){
     this->putChar(CMD_REL_OFF);
     this->putChar(n);
}

void Growduino::relWat(int n){
     this->putChar(CMD_REL_WAT);
     this->putChar(n);
}

int Growduino::getPortValue(int n){
    this->putChar(CMD_PORT_VALUE);
    this->putChar(n);
    return 0;
}

int Growduino::getEventNum(int rel){
    return relEventNum[rel];
}

int Growduino::addEvent(int rel, int h, int m, int s, RelAction act){
    if(relEventNum[rel] >= MAX_EVENT) return -1;
    relSheduler[rel][relEventNum[rel]].time.setHMS(h, m, s, 0);
    relSheduler[rel][relEventNum[rel]].action = act;
    relEventNum[rel]++;
    this->sortEvents(rel);
    return 0;
}

int Growduino::deleteEvent(int rel, int eventIndex){
    if(relEventNum[rel] == 0) return 1;
    for (int i = eventIndex; i < relEventNum[rel]-1; i++){
       relSheduler[rel][i] = relSheduler[rel][i+1];
    }
    relEventNum[rel]--;
    return 0;
}

RelEvent Growduino::getEvent(int rel, int eventIndex){
    return relSheduler[rel][eventIndex];
}

void Growduino::sortEvents(int rel){
    RelEvent event;
    for(int i = 0; i < relEventNum[rel]; i++){
        for(int j = i; j < relEventNum[rel]; j++){
            if(relSheduler[rel][i].time > relSheduler[rel][j].time){
              event = relSheduler[rel][i];
              relSheduler[rel][i] = relSheduler[rel][j];
              relSheduler[rel][j] = event;
            }
        }
    }
}

int Growduino::getSensNum(int rel){
    return relSensNum[rel];
}

int Growduino::addSens(int rel, int portID, int bVal, bool flag, RelAction act){
    if(relSensNum[rel] >= MAX_SENS) return -1;
    int sensID = relSensNum[rel];
    relSensList[rel][sensID].portID = portID;
    relSensList[rel][sensID].bVal = bVal;
    relSensList[rel][sensID].flag = flag;
    relSensList[rel][sensID].action = act;
    relSensNum[rel]++;
    return 0;
}

int Growduino::deleteSens(int rel, int index){
    if(relSensNum[rel] == 0) return 1;
    for (int i = index; i < relSensNum[rel]-1; i++){
       relSensList[rel][i] = relSensList[rel][i+1];
    }
    relSensNum[rel]--;
    return 0;
}

RelSens Growduino::getSens(int rel, int sensIndex){
    return relSensList[rel][sensIndex];
}

int Growduino::ActToInt(RelAction act){
    switch(act){
    case OFF: return 0;
    case ON: return 1;
    }
}

RelAction Growduino::IntToAct(int act){
    switch(act){
    case 0: return OFF;
    case 1: return ON;
    }
}

bool Growduino::save(QString fname){
    QFile file(fname);
    //----save events
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        return false;
    }
    for(int rel = 0; rel < MAX_RELAY; rel++){
        file.putChar(getEventNum(rel));
        for(int eID = 0; eID < getEventNum(rel); eID++){
            RelEvent event = getEvent(rel, eID);
            file.putChar(event.time.hour());
            file.putChar(event.time.minute());
            file.putChar(event.time.second());
            file.putChar(ActToInt(event.action));
        }
    }
    //------save sens
    for(int rel = 0; rel < MAX_RELAY; rel++){
        file.putChar(getSensNum(rel));
        for(int sID = 0; sID < getSensNum(rel); sID++){
            RelSens sens = getSens(rel, sID);
            file.putChar(sens.portID);

            QByteArray bbuf;
            bbuf.setNum(sens.bVal, 10);
            file.write(bbuf, sizeof(int));
            //file.putChar(sens.bVal);// DEBUG max = 127

            file.putChar(sens.flag);
            file.putChar(sens.action);
        }
    }
    file.close();
    return true;
}

bool Growduino::load(QString fname){
    QFile file(fname);
    deleteAll();
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return false;
    }
    //---load event
    for(int rel = 0; rel < MAX_RELAY; rel++){
        char *buf = new char;
        file.getChar(buf);
        int eNum = *buf;
        for(int eID = 0; eID < eNum; eID++){
            file.getChar(buf);
            int  h = *buf;
            file.getChar(buf);
            int m = *buf;
            file.getChar(buf);
            int s = *buf;
            file.getChar(buf);
            RelAction act = IntToAct(*buf);
            addEvent(rel, h, m, s, act);
        }
    }
    //----load sens
    for(int rel = 0; rel < MAX_RELAY; rel++){
        char *buf = new char;
        file.getChar(buf);
        int sNum = *buf;
        for(int sID = 0; sID < sNum; sID++){
            file.getChar(buf);
            int  portID = *buf;

            QByteArray bbuf;
            bbuf = file.read(sizeof(int));
            //file.getChar(buf);
            int bVal = bbuf.toInt();

            file.getChar(buf);
            bool flag = *buf;
            file.getChar(buf);
            RelAction act = IntToAct(*buf);
            addSens(rel, portID, bVal, flag, act);
        }
    }
    file.close();
    return true;
}


