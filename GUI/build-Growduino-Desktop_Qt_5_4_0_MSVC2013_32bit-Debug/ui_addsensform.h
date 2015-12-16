/********************************************************************************
** Form generated from reading UI file 'addsensform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSENSFORM_H
#define UI_ADDSENSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddSensForm
{
public:
    QPushButton *addButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelPort;
    QLabel *labelVal;
    QLineEdit *valEdit;
    QLineEdit *portEdit;
    QLabel *labelFlag;
    QCheckBox *flagBox;
    QLabel *labelAct;
    QComboBox *actTypeBox;

    void setupUi(QDialog *AddSensForm)
    {
        if (AddSensForm->objectName().isEmpty())
            AddSensForm->setObjectName(QStringLiteral("AddSensForm"));
        AddSensForm->resize(225, 121);
        addButton = new QPushButton(AddSensForm);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(140, 70, 75, 23));
        formLayoutWidget = new QWidget(AddSensForm);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 121, 99));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelPort = new QLabel(formLayoutWidget);
        labelPort->setObjectName(QStringLiteral("labelPort"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelPort);

        labelVal = new QLabel(formLayoutWidget);
        labelVal->setObjectName(QStringLiteral("labelVal"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelVal);

        valEdit = new QLineEdit(formLayoutWidget);
        valEdit->setObjectName(QStringLiteral("valEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, valEdit);

        portEdit = new QLineEdit(formLayoutWidget);
        portEdit->setObjectName(QStringLiteral("portEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, portEdit);

        labelFlag = new QLabel(formLayoutWidget);
        labelFlag->setObjectName(QStringLiteral("labelFlag"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelFlag);

        flagBox = new QCheckBox(formLayoutWidget);
        flagBox->setObjectName(QStringLiteral("flagBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, flagBox);

        labelAct = new QLabel(formLayoutWidget);
        labelAct->setObjectName(QStringLiteral("labelAct"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelAct);

        actTypeBox = new QComboBox(formLayoutWidget);
        actTypeBox->setObjectName(QStringLiteral("actTypeBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, actTypeBox);


        retranslateUi(AddSensForm);

        QMetaObject::connectSlotsByName(AddSensForm);
    } // setupUi

    void retranslateUi(QDialog *AddSensForm)
    {
        AddSensForm->setWindowTitle(QApplication::translate("AddSensForm", "New Sens", 0));
        addButton->setText(QApplication::translate("AddSensForm", "Add", 0));
        labelPort->setText(QApplication::translate("AddSensForm", "Port: ", 0));
        labelVal->setText(QApplication::translate("AddSensForm", "Value: ", 0));
        labelFlag->setText(QApplication::translate("AddSensForm", "Flag: ", 0));
        flagBox->setText(QString());
        labelAct->setText(QApplication::translate("AddSensForm", "Action: ", 0));
    } // retranslateUi

};

namespace Ui {
    class AddSensForm: public Ui_AddSensForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSENSFORM_H
