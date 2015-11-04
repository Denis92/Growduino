#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    curRel = 0;
    fName = "";

    ui->setupUi(this);
    ui->radioButtonR0->setChecked(true);

    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(clickLoad()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(clickSave()));
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(clickSaveAs()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(clickExit()));

    connect(ui->onButton, SIGNAL(clicked()), this, SLOT(clickOn()));
    connect(ui->offButton, SIGNAL(clicked()), this, SLOT(clickOff()));
    connect(ui->watButton, SIGNAL(clicked()), this, SLOT(clickWat()));
    connect(ui->getPortValueButton, SIGNAL(clicked()), this, SLOT(clickGetValue()));
    connect(ui->setTimeButton, SIGNAL(clicked()), this, SLOT(clickSetTime()));
    connect(ui->getTimeButton, SIGNAL(clicked()), this, SLOT(clickGetTime()));
    connect(ui->deleteEventButton, SIGNAL(clicked()), this, SLOT(clickDeleteEvent()));
    connect(ui->deleteSensButton, SIGNAL(clicked()), this, SLOT(clickDeleteSens()));
    connect(ui->configButton, SIGNAL(clicked()), this, SLOT(clickConfig()));
    connect(ui->tabWidget, SIGNAL(tabBarClicked(int)), this, SLOT(refreshPortList()));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(clickExit()));

    connect(ui->radioButtonR0, SIGNAL(clicked()), this, SLOT(changeRel()));
    connect(ui->radioButtonR1, SIGNAL(clicked()), this, SLOT(changeRel()));
    connect(ui->radioButtonR2, SIGNAL(clicked()), this, SLOT(changeRel()));
    connect(ui->radioButtonR3, SIGNAL(clicked()), this, SLOT(changeRel()));
    connect(ui->radioButtonR4, SIGNAL(clicked()), this, SLOT(changeRel()));
    connect(ui->radioButtonR5, SIGNAL(clicked()), this, SLOT(changeRel()));
    connect(ui->radioButtonR6, SIGNAL(clicked()), this, SLOT(changeRel()));
    connect(ui->radioButtonR7, SIGNAL(clicked()), this, SLOT(changeRel()));

    ui->portIDBox->addItem("0", 0);
    ui->portIDBox->addItem("1", 1);
    ui->portIDBox->addItem("2", 2);
    ui->portIDBox->addItem("3", 3);
    ui->portIDBox->addItem("4", 4);
    ui->portIDBox->addItem("5", 5);

    dev = new Growduino;
    connect(dev, SIGNAL(readyRead()), this, SLOT(dataAvailable()));
    ui->rateBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->rateBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->rateBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->rateBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);

    refreshPortList();

    calc = new WaterCalc(this);
    connect(ui->actionWatering_Calculater, SIGNAL(triggered()), calc, SLOT(show()));

    eventForm = new AddEventForm(this);
    connect (eventForm, SIGNAL(clickAdd()), this, SLOT(clickAddEvent()));
    connect(ui->addEventButton, SIGNAL(clicked()), eventForm, SLOT(show()));

    sensForm = new AddSensForm(this);
    connect(ui->addSensButton, SIGNAL(clicked()), sensForm, SLOT(show()));
    connect(sensForm, SIGNAL(clickAdd()), this, SLOT(clickAddSens()));
}

MainWindow::~MainWindow()
{
    delete calc;
    delete dev;
    delete ui;
}

/*void MainWindow::clickSend()
{
    QString string = ui->lineEdit->text();
    if(string.isEmpty() == true) return;
    std::string std_string = string.toStdString();
    char* buf = new char[std_string.length() + 1];
    strcpy(buf, std_string.c_str());
    dev->write(buf);
    delete buf;
    consoleMessage(string);
}*/

void MainWindow::clickOn(){
    if (dev->initPort(ui->portNameBox->currentText(),
                      ui->rateBox->currentText().toInt())){
        dev->relOn(curRel);
        QString msg;
        msg.setNum(curRel);
        msg = "Relay " + msg;
        msg += " is ON";
        consoleMessage(msg);
    }else{
        consoleMessage("Connect error");
    }
}

void MainWindow::clickOff(){
    if (dev->initPort(ui->portNameBox->currentText(),
                      ui->rateBox->currentText().toInt())){
        dev->relOff(curRel);
        QString msg;
        msg.setNum(curRel);
        msg = "Relay " + msg;
        msg += " is OFF";
        consoleMessage(msg);
    }else{
        consoleMessage("Connect error");
    }
}

void MainWindow::clickWat(){
    if (dev->initPort(ui->portNameBox->currentText(),
                      ui->rateBox->currentText().toInt())){
        dev->relWat(curRel);
        QString msg;
        msg.setNum(curRel);
        msg = "Relay " + msg;
        msg += " begin WATERING";
        consoleMessage(msg);
    }else{
        consoleMessage("Connect error");
    }
}

void MainWindow::clickGetValue(){
    if (dev->initPort(ui->portNameBox->currentText(),
                      ui->rateBox->currentText().toInt())){
        QString msg = "Current value (port ";
        msg += ui->portIDBox->currentText();
        msg += "): ";
        consoleMessage(msg);
        dev->getPortValue(ui->portIDBox->currentIndex());
    }else{
        consoleMessage("Connect error");
    }
}

void MainWindow::clickGetTime(){
    if (dev->initPort(ui->portNameBox->currentText(),
                      ui->rateBox->currentText().toInt())){
        consoleMessage("Growduino time: ");
        dev->printTime();
    }else{
        consoleMessage("Connect error");
    }
}

void MainWindow::clickSetTime(){
    if (dev->initPort(ui->portNameBox->currentText(),
                      ui->rateBox->currentText().toInt())){
        dev->setTime();
        consoleMessage("Growduino time update");
    }else{
        consoleMessage("Connect error");
    }
}

void MainWindow::clickConfig(){
    if (dev->initPort(ui->portNameBox->currentText(),
                      ui->rateBox->currentText().toInt())){
        dev->configDevice();
        consoleMessage("Growduino config complete");
    }else{
        consoleMessage("Connect error");
    }
}

void MainWindow::clickAddEvent(){
    dev->addEvent(curRel,
                     eventForm->getH(),
                     eventForm->getM(),
                      eventForm->getS(),
                      Growduino::IntToAct(eventForm->getActType()));
        showRelEvents();
}

void MainWindow::clickDeleteEvent(){
    if(ui->eventListWidget->currentIndex().row() < 0) return;
    dev->deleteEvent(curRel, ui->eventListWidget->currentIndex().row());
    showRelEvents();
}

void MainWindow::clickAddSens(){
   dev->addSens(curRel,
                sensForm->getPortID(),
                sensForm->getVal(),
                sensForm->getFlag(),
                Growduino::IntToAct(sensForm->getActType()));
   showRelSens();

}

void MainWindow::clickDeleteSens(){
    if(ui->sensListWidget->currentIndex().row() < 0) return;
    dev->deleteSens(curRel, ui->sensListWidget->currentIndex().row());
    showRelSens();
}

void MainWindow::clickLoad(){
    QString tmpName = QFileDialog::getOpenFileName(this, "Open...", "", "*");
    if(tmpName.isEmpty()) return;
    fName = tmpName;
    dev->load(fName);
    showRelConfig();
    consoleMessage("Load complete");
}

void MainWindow::clickSaveAs(){
    QString tmpName = QFileDialog::getSaveFileName(this, "Save...", "", "*");
    if(tmpName.isEmpty()) return;
    fName = tmpName;
    if(!dev->save(fName)){
        consoleMessage("Don`t open file");
        return;
    }
    consoleMessage("Save complete");
}

void MainWindow::clickSave(){
    if(fName.length() < 1){
        fName = QFileDialog::getSaveFileName(this, "Save...", "", "*");
        if(fName.isEmpty()) return;
    }
    if(!dev->save(fName)){
        consoleMessage("Don`t open file");
        return;
    }
    consoleMessage("Save complete");
}

void MainWindow::clickWaterCalc(){
    calc->show();
}

void MainWindow::clickExit(){
    calc->close();
    this->close();
}

void MainWindow::refreshPortList(){
    ui->portNameBox->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->portNameBox->addItem(info.portName());
    }
}

void MainWindow::showRelConfig(){
    showRelEvents();
    showRelSens();
}

void MainWindow::showRelEvents(){
    ui->eventListWidget->clear();
    for(int i = 0; i < dev->getEventNum(curRel); i++){
        RelEvent event = dev->getEvent(curRel, i);
        QString str = "";
        if(event.time.hour() < 10) str+= "0";
        str += QString::number(event.time.hour());
        str += ":";
        if(event.time.minute() < 10) str+= "0";
        str += QString::number(event.time.minute());
        str += ":";
        if(event.time.second() < 10) str+= "0";
        str += QString::number(event.time.second());
        str += " | ";
        switch(event.action){
            case ON:
                str += "ON";
                break;
            case OFF:
                str += "OFF";
                break;
        }
        ui->eventListWidget->addItem(str);
    }
}

void MainWindow::showRelSens(){
    ui->sensListWidget->clear();
    for(int i = 0; i < dev->getSensNum(curRel); i++){
        RelSens sens = dev->getSens(curRel, i);
        QString str = "";
        str += QString::number(sens.portID);
        str += " | ";
        if(sens.flag) str+= "<";
        else str+= ">";
        str += QString::number(sens.bVal);
        str += " | ";
        switch(sens.action){
            case ON:
                str += "ON";
                break;
            case OFF:
                str += "OFF";
                break;
        }
        ui->sensListWidget->addItem(str);
    }
}

void MainWindow::changeRel(){
    if (ui->radioButtonR0->isChecked()){
        curRel = 0;
    }
    if (ui->radioButtonR1->isChecked()){
        curRel = 1;
    }
    if (ui->radioButtonR2->isChecked()){
        curRel = 2;
    }
    if (ui->radioButtonR3->isChecked()){
        curRel = 3;
    }
    if (ui->radioButtonR4->isChecked()){
        curRel = 4;
    }
    if (ui->radioButtonR5->isChecked()){
        curRel = 5;
    }
    if (ui->radioButtonR6->isChecked()){
        curRel = 6;
    }
    if (ui->radioButtonR7->isChecked()){
        curRel = 7;
    }
    showRelConfig();
    return;
}

void MainWindow::dataAvailable(){
    consoleWrite(dev->readAll());
}

void MainWindow::consoleMessage(QString str){
    ui->consolBrowser->append(str);
}

void MainWindow::consoleWrite(QString str){
    ui->consolBrowser->insertPlainText(str);

}


