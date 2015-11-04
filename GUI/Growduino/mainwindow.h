#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QtGlobal>
#include <QFileDialog>
#include <QDebug>

#include "growduino.h"
#include "watercalc.h"
#include "addeventform.h"
#include "addsensform.h"


QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void consoleMessage(QString);
    void consoleWrite(QString);
    ~MainWindow();    

private:
    Ui::MainWindow *ui;

    WaterCalc *calc;
    AddEventForm *eventForm;
    AddSensForm *sensForm;

    Growduino *dev;
    int curRel;
    QString fName;
    void showRelEvents();
    void showRelSens();
    void showRelConfig();

public slots:
    void clickOn();
    void clickOff();
    void clickWat();
    void clickGetValue();
    void clickGetTime();
    void clickSetTime();
    void clickConfig();
    void clickAddEvent();
    void clickDeleteEvent();
    void clickAddSens();
    void clickDeleteSens();
    void clickSave();
    void clickSaveAs();
    void clickLoad();
    void clickWaterCalc();
    void clickExit();
    void changeRel();
    void dataAvailable();
    void refreshPortList();
};

#endif // MAINWINDOW_H
