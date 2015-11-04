#ifndef ADDEVENTFORM_H
#define ADDEVENTFORM_H

#include <QDialog>

namespace Ui {
class AddEventForm;
}

class AddEventForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddEventForm(QWidget *parent = 0);
    ~AddEventForm();

    int getH();
    int getM();
    int getS();
    int getActType();

private:
    Ui::AddEventForm *ui;

signals:
    void clickAdd();
};

#endif // ADDEVENTFORM_H
