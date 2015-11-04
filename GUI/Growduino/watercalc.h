#ifndef WATERCALC_H
#define WATERCALC_H

#include <QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

class WaterCalc : public QDialog
{
    Q_OBJECT

private:
    QPushButton *closeButton;
    QPushButton *calcButton;
    QLineEdit *pumpPerf;
    QLineEdit *waterVol;
    QLineEdit *waterTime;
    QLabel *label1,
           *label2,
           *label3,
           *label4,
           *label5,
           *label6,
           *label7,
           *label8,
           *label9;



public:
    explicit WaterCalc(QWidget *parent = 0);

signals:

public slots:
    void clickCalc();

};

#endif // WATERCALC_H
