#include "addsensform.h"
#include "ui_addsensform.h"

AddSensForm::AddSensForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSensForm)
{
    ui->setupUi(this);

    ui->actTypeBox->addItem("ON", 1);
    ui->actTypeBox->addItem("OFF", 0);

    connect(ui->addButton, SIGNAL(clicked()), this, SIGNAL(clickAdd()));
}

AddSensForm::~AddSensForm()
{
    delete ui;
}

int AddSensForm::getPortID(){
    return ui->portEdit->text().toInt();
}

int AddSensForm::getVal(){
    return ui->valEdit->text().toInt();
}
int AddSensForm::getFlag(){ //переделать
    switch(ui->flagBox->isChecked()){
    case true:
        return 1;
        break;
    case false:
        return 0;
        break;
    }
}

int AddSensForm::getActType(){
    return ui->actTypeBox->itemData(ui->actTypeBox->currentIndex()).toInt();
}
