/********************************************************************************
** Form generated from reading UI file 'sudokuGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKUGUI_H
#define UI_SUDOKUGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sudokuGUIClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *panelLayout;
    QVBoxLayout *optionsLayout;
    QRadioButton *simpleOption;
    QRadioButton *normalOption;
    QRadioButton *hardOption;
    QPushButton *startButton;
    QWidget *gridLayoutWidget;
    QGridLayout *sudokuLayout;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *recordLayout;
    QLabel *timelabel;
    QLCDNumber *timeLcd;
    QLabel *recordLabel;
    QLabel *recordNum;
    QLabel *InformLabel;
    QLabel *InformNumber;
    QPushButton *submitButton;
    QWidget *gridLayoutWidget_2;
    QGridLayout *toolLayout;
    QPushButton *informButton;
    QPushButton *stopButton;
    QPushButton *backButton;
    QPushButton *quitButton;
    QWidget *gridLayoutWidget_3;
    QGridLayout *quitLayout;
    QPushButton *quitSureButton;
    QLabel *quitLabel;
    QPushButton *quitCancelButton;
    QWidget *gridLayoutWidget_5;
    QGridLayout *submitLayout;
    QPushButton *awayButton;
    QPushButton *againButton;
    QLabel *SubmitLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *optionButtons;

    void setupUi(QMainWindow *sudokuGUIClass)
    {
        if (sudokuGUIClass->objectName().isEmpty())
            sudokuGUIClass->setObjectName(QStringLiteral("sudokuGUIClass"));
        sudokuGUIClass->resize(600, 427);
        sudokuGUIClass->setCursor(QCursor(Qt::ArrowCursor));
        sudokuGUIClass->setStyleSheet(QLatin1String("background-color: rgb(235, 247, 255);\n"
""));
        centralWidget = new QWidget(sudokuGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(230, 100, 139, 181));
        panelLayout = new QVBoxLayout(verticalLayoutWidget_2);
        panelLayout->setSpacing(10);
        panelLayout->setContentsMargins(11, 11, 11, 11);
        panelLayout->setObjectName(QStringLiteral("panelLayout"));
        panelLayout->setContentsMargins(0, 0, 0, 0);
        optionsLayout = new QVBoxLayout();
        optionsLayout->setSpacing(10);
        optionsLayout->setObjectName(QStringLiteral("optionsLayout"));
        optionsLayout->setContentsMargins(45, -1, 45, -1);
        simpleOption = new QRadioButton(verticalLayoutWidget_2);
        optionButtons = new QButtonGroup(sudokuGUIClass);
        optionButtons->setObjectName(QStringLiteral("optionButtons"));
        optionButtons->addButton(simpleOption);
        simpleOption->setObjectName(QStringLiteral("simpleOption"));

        optionsLayout->addWidget(simpleOption);

        normalOption = new QRadioButton(verticalLayoutWidget_2);
        optionButtons->addButton(normalOption);
        normalOption->setObjectName(QStringLiteral("normalOption"));
        normalOption->setStyleSheet(QStringLiteral("font: 75 9pt \"Agency FB\";"));

        optionsLayout->addWidget(normalOption);

        hardOption = new QRadioButton(verticalLayoutWidget_2);
        optionButtons->addButton(hardOption);
        hardOption->setObjectName(QStringLiteral("hardOption"));
        hardOption->setStyleSheet(QStringLiteral("font: 75 9pt \"Microsoft YaHei UI\";"));

        optionsLayout->addWidget(hardOption);


        panelLayout->addLayout(optionsLayout);

        startButton = new QPushButton(verticalLayoutWidget_2);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setCursor(QCursor(Qt::OpenHandCursor));
        startButton->setStyleSheet(QLatin1String("background-color: rgb(133, 182, 255);\n"
"font: 75 9pt \"Microsoft YaHei UI\";"));

        panelLayout->addWidget(startButton);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 10, 411, 351));
        sudokuLayout = new QGridLayout(gridLayoutWidget);
        sudokuLayout->setSpacing(6);
        sudokuLayout->setContentsMargins(11, 11, 11, 11);
        sudokuLayout->setObjectName(QStringLiteral("sudokuLayout"));
        sudokuLayout->setVerticalSpacing(6);
        sudokuLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(450, 20, 131, 231));
        recordLayout = new QVBoxLayout(verticalLayoutWidget_3);
        recordLayout->setSpacing(6);
        recordLayout->setContentsMargins(11, 11, 11, 11);
        recordLayout->setObjectName(QStringLiteral("recordLayout"));
        recordLayout->setContentsMargins(0, 0, 0, 0);
        timelabel = new QLabel(verticalLayoutWidget_3);
        timelabel->setObjectName(QStringLiteral("timelabel"));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        timelabel->setFont(font);

        recordLayout->addWidget(timelabel);

        timeLcd = new QLCDNumber(verticalLayoutWidget_3);
        timeLcd->setObjectName(QStringLiteral("timeLcd"));

        recordLayout->addWidget(timeLcd);

        recordLabel = new QLabel(verticalLayoutWidget_3);
        recordLabel->setObjectName(QStringLiteral("recordLabel"));
        recordLabel->setFont(font);

        recordLayout->addWidget(recordLabel);

        recordNum = new QLabel(verticalLayoutWidget_3);
        recordNum->setObjectName(QStringLiteral("recordNum"));
        QFont font1;
        font1.setFamily(QStringLiteral("Cambria"));
        font1.setPointSize(10);
        recordNum->setFont(font1);

        recordLayout->addWidget(recordNum);

        InformLabel = new QLabel(verticalLayoutWidget_3);
        InformLabel->setObjectName(QStringLiteral("InformLabel"));
        InformLabel->setFont(font);

        recordLayout->addWidget(InformLabel);

        InformNumber = new QLabel(verticalLayoutWidget_3);
        InformNumber->setObjectName(QStringLiteral("InformNumber"));
        InformNumber->setFont(font1);

        recordLayout->addWidget(InformNumber);

        submitButton = new QPushButton(centralWidget);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setGeometry(QRect(470, 260, 91, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font2.setBold(true);
        font2.setWeight(75);
        submitButton->setFont(font2);
        submitButton->setCursor(QCursor(Qt::OpenHandCursor));
        submitButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 178, 90);"));
        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(450, 300, 131, 58));
        toolLayout = new QGridLayout(gridLayoutWidget_2);
        toolLayout->setSpacing(6);
        toolLayout->setContentsMargins(11, 11, 11, 11);
        toolLayout->setObjectName(QStringLiteral("toolLayout"));
        toolLayout->setContentsMargins(0, 0, 0, 0);
        informButton = new QPushButton(gridLayoutWidget_2);
        informButton->setObjectName(QStringLiteral("informButton"));
        informButton->setFont(font2);
        informButton->setCursor(QCursor(Qt::OpenHandCursor));
        informButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 236, 158);"));

        toolLayout->addWidget(informButton, 0, 0, 1, 1);

        stopButton = new QPushButton(gridLayoutWidget_2);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setFont(font2);
        stopButton->setCursor(QCursor(Qt::OpenHandCursor));
        stopButton->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));

        toolLayout->addWidget(stopButton, 0, 1, 1, 1);

        backButton = new QPushButton(gridLayoutWidget_2);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setFont(font2);
        backButton->setCursor(QCursor(Qt::OpenHandCursor));
        backButton->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));

        toolLayout->addWidget(backButton, 1, 0, 1, 1);

        quitButton = new QPushButton(gridLayoutWidget_2);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setFont(font2);
        quitButton->setCursor(QCursor(Qt::OpenHandCursor));
        quitButton->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 255);"));

        toolLayout->addWidget(quitButton, 1, 1, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(190, 120, 239, 111));
        quitLayout = new QGridLayout(gridLayoutWidget_3);
        quitLayout->setSpacing(6);
        quitLayout->setContentsMargins(11, 11, 11, 11);
        quitLayout->setObjectName(QStringLiteral("quitLayout"));
        quitLayout->setContentsMargins(0, 0, 0, 0);
        quitSureButton = new QPushButton(gridLayoutWidget_3);
        quitSureButton->setObjectName(QStringLiteral("quitSureButton"));
        quitSureButton->setFont(font2);
        quitSureButton->setCursor(QCursor(Qt::OpenHandCursor));
        quitSureButton->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));

        quitLayout->addWidget(quitSureButton, 1, 0, 1, 1);

        quitLabel = new QLabel(gridLayoutWidget_3);
        quitLabel->setObjectName(QStringLiteral("quitLabel"));
        quitLabel->setStyleSheet(QLatin1String("font: 75 12pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(220, 220, 165);"));

        quitLayout->addWidget(quitLabel, 0, 0, 1, 2);

        quitCancelButton = new QPushButton(gridLayoutWidget_3);
        quitCancelButton->setObjectName(QStringLiteral("quitCancelButton"));
        quitCancelButton->setFont(font2);

        quitLayout->addWidget(quitCancelButton, 1, 1, 1, 1);

        gridLayoutWidget_5 = new QWidget(centralWidget);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(190, 120, 241, 111));
        submitLayout = new QGridLayout(gridLayoutWidget_5);
        submitLayout->setSpacing(6);
        submitLayout->setContentsMargins(11, 11, 11, 11);
        submitLayout->setObjectName(QStringLiteral("submitLayout"));
        submitLayout->setContentsMargins(0, 0, 0, 0);
        awayButton = new QPushButton(gridLayoutWidget_5);
        awayButton->setObjectName(QStringLiteral("awayButton"));
        awayButton->setFont(font2);

        submitLayout->addWidget(awayButton, 1, 1, 1, 1);

        againButton = new QPushButton(gridLayoutWidget_5);
        againButton->setObjectName(QStringLiteral("againButton"));
        againButton->setFont(font2);
        againButton->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));

        submitLayout->addWidget(againButton, 1, 0, 1, 1);

        SubmitLabel = new QLabel(gridLayoutWidget_5);
        SubmitLabel->setObjectName(QStringLiteral("SubmitLabel"));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        SubmitLabel->setFont(font3);
        SubmitLabel->setStyleSheet(QStringLiteral("background-color: rgb(220, 220, 165);"));

        submitLayout->addWidget(SubmitLabel, 0, 0, 1, 2);

        sudokuGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(sudokuGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        sudokuGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(sudokuGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        sudokuGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(sudokuGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        sudokuGUIClass->setStatusBar(statusBar);

        retranslateUi(sudokuGUIClass);

        QMetaObject::connectSlotsByName(sudokuGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *sudokuGUIClass)
    {
        sudokuGUIClass->setWindowTitle(QApplication::translate("sudokuGUIClass", "sudokuGUI", Q_NULLPTR));
        simpleOption->setText(QApplication::translate("sudokuGUIClass", "\347\256\200\345\215\225", Q_NULLPTR));
        normalOption->setText(QApplication::translate("sudokuGUIClass", "\345\205\245\351\227\250", Q_NULLPTR));
        hardOption->setText(QApplication::translate("sudokuGUIClass", "\345\233\260\351\232\276", Q_NULLPTR));
        startButton->setText(QApplication::translate("sudokuGUIClass", "\345\274\200\345\247\213", Q_NULLPTR));
        timelabel->setText(QApplication::translate("sudokuGUIClass", "\345\275\223\345\211\215\347\224\250\346\227\266\357\274\232", Q_NULLPTR));
        recordLabel->setText(QApplication::translate("sudokuGUIClass", "\346\234\200\347\237\255\347\224\250\346\227\266\357\274\232", Q_NULLPTR));
        recordNum->setText(QApplication::translate("sudokuGUIClass", "121423", Q_NULLPTR));
        InformLabel->setText(QApplication::translate("sudokuGUIClass", "\346\217\220\347\244\272\357\274\232", Q_NULLPTR));
        InformNumber->setText(QString());
        submitButton->setText(QApplication::translate("sudokuGUIClass", "\346\217\220\344\272\244", Q_NULLPTR));
        informButton->setText(QApplication::translate("sudokuGUIClass", "\346\217\220\347\244\272", Q_NULLPTR));
        stopButton->setText(QApplication::translate("sudokuGUIClass", "\346\232\202\345\201\234", Q_NULLPTR));
        backButton->setText(QApplication::translate("sudokuGUIClass", "\350\277\224\345\233\236", Q_NULLPTR));
        quitButton->setText(QApplication::translate("sudokuGUIClass", "\351\200\200\345\207\272", Q_NULLPTR));
        quitSureButton->setText(QApplication::translate("sudokuGUIClass", "\347\241\256\345\256\232", Q_NULLPTR));
        quitLabel->setText(QApplication::translate("sudokuGUIClass", "              \347\241\256\350\256\244\351\200\200\345\207\272\357\274\237", Q_NULLPTR));
        quitCancelButton->setText(QApplication::translate("sudokuGUIClass", "\345\217\226\346\266\210", Q_NULLPTR));
        awayButton->setText(QApplication::translate("sudokuGUIClass", "\344\270\215\347\216\251\344\272\206", Q_NULLPTR));
        againButton->setText(QApplication::translate("sudokuGUIClass", "\345\206\215\346\235\245\344\270\200\345\261\200", Q_NULLPTR));
        SubmitLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class sudokuGUIClass: public Ui_sudokuGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKUGUI_H
