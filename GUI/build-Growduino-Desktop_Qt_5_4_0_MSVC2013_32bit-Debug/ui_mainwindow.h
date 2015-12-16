/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionWatering_Calculater;
    QWidget *centralWidget;
    QTextBrowser *consolBrowser;
    QGraphicsView *topLogoView;
    QTabWidget *tabWidget;
    QWidget *tabConnect;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPort;
    QComboBox *portNameBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelRate;
    QComboBox *rateBox;
    QWidget *tabRelControl;
    QGroupBox *relControlBox;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *onButton;
    QPushButton *offButton;
    QPushButton *watButton;
    QGroupBox *portValueBox;
    QPushButton *getPortValueButton;
    QComboBox *portIDBox;
    QWidget *tabTime;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *setTimeButton;
    QPushButton *getTimeButton;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *configButton;
    QPushButton *exitButton;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *relayBox;
    QRadioButton *radioButtonR0;
    QRadioButton *radioButtonR1;
    QRadioButton *radioButtonR3;
    QRadioButton *radioButtonR2;
    QRadioButton *radioButtonR4;
    QRadioButton *radioButtonR5;
    QRadioButton *radioButtonR6;
    QRadioButton *radioButtonR7;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QListWidget *eventListWidget;
    QLabel *label_4;
    QListWidget *sensListWidget;
    QPushButton *addEventButton;
    QPushButton *deleteEventButton;
    QPushButton *addSensButton;
    QPushButton *deleteSensButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(561, 335);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(561, 335));
        MainWindow->setMaximumSize(QSize(561, 335));
        MainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionWatering_Calculater = new QAction(MainWindow);
        actionWatering_Calculater->setObjectName(QStringLiteral("actionWatering_Calculater"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        consolBrowser = new QTextBrowser(centralWidget);
        consolBrowser->setObjectName(QStringLiteral("consolBrowser"));
        consolBrowser->setGeometry(QRect(290, 210, 261, 91));
        topLogoView = new QGraphicsView(centralWidget);
        topLogoView->setObjectName(QStringLiteral("topLogoView"));
        topLogoView->setGeometry(QRect(20, 10, 249, 39));
        topLogoView->setStyleSheet(QStringLiteral("background-image:url(:/image/img/logo.png)"));
        topLogoView->setFrameShape(QFrame::NoFrame);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(290, 10, 261, 191));
        tabConnect = new QWidget();
        tabConnect->setObjectName(QStringLiteral("tabConnect"));
        tabConnect->setEnabled(true);
        verticalLayoutWidget = new QWidget(tabConnect);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 30, 171, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelPort = new QLabel(verticalLayoutWidget);
        labelPort->setObjectName(QStringLiteral("labelPort"));

        horizontalLayout->addWidget(labelPort);

        portNameBox = new QComboBox(verticalLayoutWidget);
        portNameBox->setObjectName(QStringLiteral("portNameBox"));

        horizontalLayout->addWidget(portNameBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelRate = new QLabel(verticalLayoutWidget);
        labelRate->setObjectName(QStringLiteral("labelRate"));

        horizontalLayout_2->addWidget(labelRate);

        rateBox = new QComboBox(verticalLayoutWidget);
        rateBox->setObjectName(QStringLiteral("rateBox"));

        horizontalLayout_2->addWidget(rateBox);


        verticalLayout->addLayout(horizontalLayout_2);

        tabWidget->addTab(tabConnect, QString());
        tabRelControl = new QWidget();
        tabRelControl->setObjectName(QStringLiteral("tabRelControl"));
        tabRelControl->setEnabled(true);
        relControlBox = new QGroupBox(tabRelControl);
        relControlBox->setObjectName(QStringLiteral("relControlBox"));
        relControlBox->setGeometry(QRect(10, 10, 131, 141));
        verticalLayoutWidget_4 = new QWidget(relControlBox);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 20, 111, 111));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        onButton = new QPushButton(verticalLayoutWidget_4);
        onButton->setObjectName(QStringLiteral("onButton"));

        verticalLayout_4->addWidget(onButton);

        offButton = new QPushButton(verticalLayoutWidget_4);
        offButton->setObjectName(QStringLiteral("offButton"));

        verticalLayout_4->addWidget(offButton);

        watButton = new QPushButton(verticalLayoutWidget_4);
        watButton->setObjectName(QStringLiteral("watButton"));

        verticalLayout_4->addWidget(watButton);

        portValueBox = new QGroupBox(tabRelControl);
        portValueBox->setObjectName(QStringLiteral("portValueBox"));
        portValueBox->setGeometry(QRect(150, 9, 101, 141));
        getPortValueButton = new QPushButton(portValueBox);
        getPortValueButton->setObjectName(QStringLiteral("getPortValueButton"));
        getPortValueButton->setGeometry(QRect(10, 70, 81, 23));
        portIDBox = new QComboBox(portValueBox);
        portIDBox->setObjectName(QStringLiteral("portIDBox"));
        portIDBox->setGeometry(QRect(10, 40, 81, 22));
        tabWidget->addTab(tabRelControl, QString());
        tabTime = new QWidget();
        tabTime->setObjectName(QStringLiteral("tabTime"));
        verticalLayoutWidget_2 = new QWidget(tabTime);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(50, 40, 160, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        setTimeButton = new QPushButton(verticalLayoutWidget_2);
        setTimeButton->setObjectName(QStringLiteral("setTimeButton"));

        verticalLayout_2->addWidget(setTimeButton);

        getTimeButton = new QPushButton(verticalLayoutWidget_2);
        getTimeButton->setObjectName(QStringLiteral("getTimeButton"));

        verticalLayout_2->addWidget(getTimeButton);

        tabWidget->addTab(tabTime, QString());
        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(40, 270, 168, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        configButton = new QPushButton(horizontalLayoutWidget_3);
        configButton->setObjectName(QStringLiteral("configButton"));
        configButton->setStyleSheet(QLatin1String("color: White;\n"
"\n"
"border: 1px solid #505050;\n"
"border-radius: 3px;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #65ce6d, stop: 0.5 #20aa20, stop: 0.51 #20aa20, stop: 1 #006600);\n"
"min-width: 70px;\n"
"min-height: 19px;\n"
""));

        horizontalLayout_3->addWidget(configButton);

        exitButton = new QPushButton(horizontalLayoutWidget_3);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        horizontalLayout_3->addWidget(exitButton);

        horizontalLayoutWidget_4 = new QWidget(centralWidget);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 60, 201, 201));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        relayBox = new QGroupBox(horizontalLayoutWidget_4);
        relayBox->setObjectName(QStringLiteral("relayBox"));
        relayBox->setEnabled(true);
        relayBox->setMinimumSize(QSize(80, 0));
        radioButtonR0 = new QRadioButton(relayBox);
        radioButtonR0->setObjectName(QStringLiteral("radioButtonR0"));
        radioButtonR0->setGeometry(QRect(10, 20, 82, 17));
        radioButtonR1 = new QRadioButton(relayBox);
        radioButtonR1->setObjectName(QStringLiteral("radioButtonR1"));
        radioButtonR1->setGeometry(QRect(10, 40, 82, 17));
        radioButtonR3 = new QRadioButton(relayBox);
        radioButtonR3->setObjectName(QStringLiteral("radioButtonR3"));
        radioButtonR3->setGeometry(QRect(10, 80, 82, 17));
        radioButtonR2 = new QRadioButton(relayBox);
        radioButtonR2->setObjectName(QStringLiteral("radioButtonR2"));
        radioButtonR2->setGeometry(QRect(10, 60, 82, 17));
        radioButtonR4 = new QRadioButton(relayBox);
        radioButtonR4->setObjectName(QStringLiteral("radioButtonR4"));
        radioButtonR4->setGeometry(QRect(10, 100, 82, 17));
        radioButtonR5 = new QRadioButton(relayBox);
        radioButtonR5->setObjectName(QStringLiteral("radioButtonR5"));
        radioButtonR5->setGeometry(QRect(10, 120, 82, 17));
        radioButtonR6 = new QRadioButton(relayBox);
        radioButtonR6->setObjectName(QStringLiteral("radioButtonR6"));
        radioButtonR6->setGeometry(QRect(10, 140, 82, 17));
        radioButtonR7 = new QRadioButton(relayBox);
        radioButtonR7->setObjectName(QStringLiteral("radioButtonR7"));
        radioButtonR7->setGeometry(QRect(10, 160, 82, 17));

        horizontalLayout_4->addWidget(relayBox);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(horizontalLayoutWidget_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        eventListWidget = new QListWidget(horizontalLayoutWidget_4);
        eventListWidget->setObjectName(QStringLiteral("eventListWidget"));

        verticalLayout_3->addWidget(eventListWidget);

        label_4 = new QLabel(horizontalLayoutWidget_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        sensListWidget = new QListWidget(horizontalLayoutWidget_4);
        sensListWidget->setObjectName(QStringLiteral("sensListWidget"));

        verticalLayout_3->addWidget(sensListWidget);


        horizontalLayout_4->addLayout(verticalLayout_3);

        addEventButton = new QPushButton(centralWidget);
        addEventButton->setObjectName(QStringLiteral("addEventButton"));
        addEventButton->setGeometry(QRect(220, 80, 61, 23));
        deleteEventButton = new QPushButton(centralWidget);
        deleteEventButton->setObjectName(QStringLiteral("deleteEventButton"));
        deleteEventButton->setGeometry(QRect(220, 110, 61, 23));
        addSensButton = new QPushButton(centralWidget);
        addSensButton->setObjectName(QStringLiteral("addSensButton"));
        addSensButton->setGeometry(QRect(220, 190, 61, 23));
        deleteSensButton = new QPushButton(centralWidget);
        deleteSensButton->setObjectName(QStringLiteral("deleteSensButton"));
        deleteSensButton->setGeometry(QRect(220, 220, 61, 23));
        MainWindow->setCentralWidget(centralWidget);
        tabWidget->raise();
        consolBrowser->raise();
        topLogoView->raise();
        horizontalLayoutWidget_3->raise();
        horizontalLayoutWidget_4->raise();
        addEventButton->raise();
        deleteEventButton->raise();
        addSensButton->raise();
        deleteSensButton->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 561, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuTools->addAction(actionWatering_Calculater);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Growduino", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionWatering_Calculater->setText(QApplication::translate("MainWindow", "Watering Calculater", 0));
        labelPort->setText(QApplication::translate("MainWindow", "Port:", 0));
        labelRate->setText(QApplication::translate("MainWindow", "Rate:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabConnect), QApplication::translate("MainWindow", "Connect", 0));
        relControlBox->setTitle(QApplication::translate("MainWindow", "Relay Control", 0));
        onButton->setText(QApplication::translate("MainWindow", "ON", 0));
        offButton->setText(QApplication::translate("MainWindow", "OFF", 0));
        watButton->setText(QApplication::translate("MainWindow", "WATERING", 0));
        portValueBox->setTitle(QApplication::translate("MainWindow", "Get Port Value", 0));
        getPortValueButton->setText(QApplication::translate("MainWindow", "Get", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabRelControl), QApplication::translate("MainWindow", "Control", 0));
        setTimeButton->setText(QApplication::translate("MainWindow", "Set Growduino time", 0));
        getTimeButton->setText(QApplication::translate("MainWindow", "Get Growduino time", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabTime), QApplication::translate("MainWindow", "Time", 0));
        configButton->setText(QApplication::translate("MainWindow", "Grow!", 0));
        exitButton->setText(QApplication::translate("MainWindow", "Exit", 0));
        relayBox->setTitle(QApplication::translate("MainWindow", "Select relay:", 0));
        radioButtonR0->setText(QApplication::translate("MainWindow", "Relay 0", 0));
        radioButtonR1->setText(QApplication::translate("MainWindow", "Relay 1", 0));
        radioButtonR3->setText(QApplication::translate("MainWindow", "Relay 3", 0));
        radioButtonR2->setText(QApplication::translate("MainWindow", "Relay 2", 0));
        radioButtonR4->setText(QApplication::translate("MainWindow", "Relay 4", 0));
        radioButtonR5->setText(QApplication::translate("MainWindow", "Relay 5", 0));
        radioButtonR6->setText(QApplication::translate("MainWindow", "Relay 6", 0));
        radioButtonR7->setText(QApplication::translate("MainWindow", "Relay 7", 0));
        label_3->setText(QApplication::translate("MainWindow", "Relay events:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Relay sensitivity:", 0));
        addEventButton->setText(QApplication::translate("MainWindow", "Add", 0));
        deleteEventButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        addSensButton->setText(QApplication::translate("MainWindow", "Add", 0));
        deleteSensButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
