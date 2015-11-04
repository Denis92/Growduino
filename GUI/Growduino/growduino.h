#ifndef GROWDUINO_H
#define GROWDUINO_H

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

#define MAX_RELAY 8
#define MAX_EVENT 12
#define MAX_SENS 5

#include <QObject>
#include <QtSerialPort/QtSerialPort>
#include <QTime>
#include <QDebug>

typedef enum {OFF, ON} RelAction;

struct RelEvent{
    QTime time;
    RelAction action;

};

struct RelSens{
  int portID;
  int bVal;
  bool flag;
  RelAction action;
};

class Growduino : public QSerialPort
{
    Q_OBJECT

private:
//    int curRel;
    RelEvent relSheduler[MAX_RELAY][MAX_EVENT];
    int relEventNum[MAX_RELAY];
    RelSens relSensList[MAX_RELAY][MAX_SENS];
    int relSensNum[MAX_RELAY];
public:
    explicit Growduino(QObject *parent = 0);
    ~Growduino();

    int setTime();
    int printTime();
    void relOn(int);
    void relOff(int);
    void relWat(int);
    int configDevice();
    int getPortValue(int);
    bool initPort(QString);
    bool initPort(QString, int);
    void deleteAll();
    bool load(QString);
    bool save(QString);

    int addEvent(int, int, int, int, RelAction);
    int deleteEvent(int, int);
    RelEvent getEvent(int, int);
    int getEventNum(int);
    void sortEvents(int);

    int addSens(int, int, int, bool, RelAction);
    int deleteSens(int, int);
    RelSens getSens(int, int);
     int getSensNum(int);

    static RelAction IntToAct(int);
    static int ActToInt(RelAction);

//signals:

//public slots:


};

#endif // GROWDUINO_H
