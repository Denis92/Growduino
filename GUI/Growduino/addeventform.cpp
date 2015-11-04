#include "addeventform.h"
#include "ui_addeventform.h"

AddEventForm::AddEventForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEventForm)
{
    ui->setupUi(this);
    ui->actTypeBox->addItem("ON", 1);
    ui->actTypeBox->addItem("OFF", 0);

    connect (ui->addButton, SIGNAL(clicked()), this, SIGNAL (clickAdd()));
}

AddEventForm::~AddEventForm()
{
    delete ui;
}

int AddEventForm::getH(){
    return ui->timeEdit->time().hour();
}

int AddEventForm::getM(){
    return ui->timeEdit->time().minute();
}

int AddEventForm::getS(){
    return ui->timeEdit->time().second();
}

int AddEventForm::getActType(){
    return ui->actTypeBox->itemData(ui->actTypeBox->currentIndex()).toInt();
}
