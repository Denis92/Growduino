#ifndef ADDSENSFORM_H
#define ADDSENSFORM_H

#include <QDialog>

namespace Ui {
class AddSensForm;
}

class AddSensForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddSensForm(QWidget *parent = 0);
    ~AddSensForm();

    int getPortID();
    int getVal();
    int getFlag();
    int getActType();

private:
    Ui::AddSensForm *ui;

 signals:
    void clickAdd();
};

#endif // ADDSENSFORM_H
