/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <tetrixboard.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frameBg;
    QGridLayout *gridLayout;
    QLCDNumber *lcdScore;
    QLCDNumber *lcdSpeed;
    QLabel *labelNextPiece;
    QPushButton *btnExit;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *btnStop;
    QLabel *label;
    TetrixBoard *frame;
    QLCDNumber *lcdRemoved;
    QPushButton *btnStart;
    QPushButton *btnRestart;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(729, 587);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/tetrixIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("*{\n"
"	border-style:double;\n"
"	border-width:4px;\n"
"	border-color: rgb(41, 165, 19);\n"
"	color: rgb(255, 255, 255);\n"
"	font: 700 14pt \"Microsoft YaHei UI\";\n"
"	border-radius:10px;\n"
"	padding:4px;\n"
"	min-height:40px;\n"
"}\n"
"QFrame#frameBg{	\n"
"	background-color: rgb(49, 128, 255);\n"
"}\n"
"QLabel{\n"
"	border-width:0px;\n"
"}\n"
"QLabel#labelNextPiece{\n"
"border-width:2px;\n"
"}\n"
"QFrame#frame{\n"
"	background-image: url(:/images/tetrixbg.png);\n"
"     padding:4px;\n"
"}\n"
"QPushButton{\n"
"border-width:1px;\n"
"}\n"
"QPushButton:hover{\n"
"	font: 700 16pt \"Microsoft YaHei UI\";\n"
"}\n"
"QPushButton:pressed{\n"
"	padding-left:6px;\n"
"	padding-top:6px;\n"
"	font: 700 14pt \"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        frameBg = new QFrame(centralwidget);
        frameBg->setObjectName("frameBg");
        frameBg->setFrameShape(QFrame::Shape::StyledPanel);
        frameBg->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(frameBg);
        gridLayout->setObjectName("gridLayout");
        lcdScore = new QLCDNumber(frameBg);
        lcdScore->setObjectName("lcdScore");

        gridLayout->addWidget(lcdScore, 1, 2, 1, 1);

        lcdSpeed = new QLCDNumber(frameBg);
        lcdSpeed->setObjectName("lcdSpeed");

        gridLayout->addWidget(lcdSpeed, 3, 2, 1, 1);

        labelNextPiece = new QLabel(frameBg);
        labelNextPiece->setObjectName("labelNextPiece");
        labelNextPiece->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(labelNextPiece, 1, 0, 2, 1);

        btnExit = new QPushButton(frameBg);
        btnExit->setObjectName("btnExit");

        gridLayout->addWidget(btnExit, 8, 0, 1, 1);

        label_3 = new QLabel(frameBg);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout->addWidget(label_3, 2, 2, 1, 1);

        label_4 = new QLabel(frameBg);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout->addWidget(label_4, 4, 2, 1, 1);

        label_2 = new QLabel(frameBg);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        btnStop = new QPushButton(frameBg);
        btnStop->setObjectName("btnStop");

        gridLayout->addWidget(btnStop, 5, 0, 1, 1);

        label = new QLabel(frameBg);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        frame = new TetrixBoard(frameBg);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(300, 56));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);

        gridLayout->addWidget(frame, 0, 1, 9, 1);

        lcdRemoved = new QLCDNumber(frameBg);
        lcdRemoved->setObjectName("lcdRemoved");

        gridLayout->addWidget(lcdRemoved, 5, 2, 1, 1);

        btnStart = new QPushButton(frameBg);
        btnStart->setObjectName("btnStart");

        gridLayout->addWidget(btnStart, 4, 0, 1, 1);

        btnRestart = new QPushButton(frameBg);
        btnRestart->setObjectName("btnRestart");

        gridLayout->addWidget(btnRestart, 6, 0, 1, 1);


        verticalLayout->addWidget(frameBg);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(btnExit, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelNextPiece->setText(QString());
        btnExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\344\273\245\346\266\210\351\231\244\350\241\214\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\210\206\346\225\260", nullptr));
        btnStop->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        btnRestart->setText(QCoreApplication::translate("MainWindow", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
