/********************************************************************************
** Form generated from reading UI file 'addeventform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEVENTFORM_H
#define UI_ADDEVENTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddEventForm
{
public:
    QPushButton *addButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelTime;
    QTimeEdit *timeEdit;
    QLabel *labelAct;
    QComboBox *actTypeBox;

    void setupUi(QDialog *AddEventForm)
    {
        if (AddEventForm->objectName().isEmpty())
            AddEventForm->setObjectName(QStringLiteral("AddEventForm"));
        AddEventForm->resize(220, 70);
        AddEventForm->setMinimumSize(QSize(220, 70));
        AddEventForm->setMaximumSize(QSize(220, 70));
        addButton = new QPushButton(AddEventForm);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(140, 30, 71, 23));
        formLayoutWidget = new QWidget(AddEventForm);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 121, 51));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelTime = new QLabel(formLayoutWidget);
        labelTime->setObjectName(QStringLiteral("labelTime"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelTime);

        timeEdit = new QTimeEdit(formLayoutWidget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, timeEdit);

        labelAct = new QLabel(formLayoutWidget);
        labelAct->setObjectName(QStringLiteral("labelAct"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelAct);

        actTypeBox = new QComboBox(formLayoutWidget);
        actTypeBox->setObjectName(QStringLiteral("actTypeBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, actTypeBox);


        retranslateUi(AddEventForm);

        QMetaObject::connectSlotsByName(AddEventForm);
    } // setupUi

    void retranslateUi(QDialog *AddEventForm)
    {
        AddEventForm->setWindowTitle(QApplication::translate("AddEventForm", "New Event", 0));
        addButton->setText(QApplication::translate("AddEventForm", "Add", 0));
        labelTime->setText(QApplication::translate("AddEventForm", "Time: ", 0));
        timeEdit->setDisplayFormat(QApplication::translate("AddEventForm", "HH:mm:ss", 0));
        labelAct->setText(QApplication::translate("AddEventForm", "Action: ", 0));
    } // retranslateUi

};

namespace Ui {
    class AddEventForm: public Ui_AddEventForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEVENTFORM_H
