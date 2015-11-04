#include "watercalc.h"

WaterCalc::WaterCalc(QWidget *parent) :
    QDialog(parent)
{
    this->setFixedSize(QSize(150, 100));
    this->setWindowTitle("Water Calc");

    label1 = new QLabel(this);
    label1->setText("Pump Perf.: ");
    label1->setGeometry(QRect(10, 5, 55, 20));

    pumpPerf = new QLineEdit(this);
    pumpPerf->setGeometry(QRect(70, 5, 40, 20));

    label2 = new QLabel(this);
    label2->setText("L/H");
    label2->setGeometry(QRect(120, 5, 55, 20));

    label3 = new QLabel(this);
    label3->setText("Water Vol.: ");
    label3->setGeometry(QRect(10, 30, 55, 20));

    waterVol = new QLineEdit(this);
    waterVol->setGeometry(QRect(70, 30, 40, 20));

    label4 = new QLabel(this);
    label4->setText("L");
    label4->setGeometry(QRect(120, 30, 55, 20));

    label5 = new QLabel(this);
    label5->setText("Wat. Time:");
    label5->setGeometry(QRect(10, 55, 55, 20));

    waterTime = new QLineEdit(this);
    waterTime->setGeometry(QRect(70, 55, 40, 20));
    waterTime->setReadOnly(true);

    label6 = new QLabel(this);
    label6->setText("sec");
    label6->setGeometry(QRect(120, 55, 55, 20));

    calcButton = new QPushButton(this);
    calcButton->setText("Calculate");
    calcButton->setGeometry(QRect(20, 80, 55, 20));
    connect(calcButton, SIGNAL(clicked()), this, SLOT(clickCalc()));

    closeButton = new QPushButton(this);
    closeButton->setText("Close");
    closeButton->setGeometry(QRect(80, 80, 50, 20));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(hide()));
}

void WaterCalc::clickCalc(){
    float v1 = pumpPerf->displayText().toFloat();
    float v2 = waterVol->displayText().toFloat();
    float v3 = (3600*v2)/v1;
    QString str = QString::number(v3, 'g', 4);
    waterTime->setText(str);
}
