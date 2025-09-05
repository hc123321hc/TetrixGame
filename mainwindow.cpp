#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMouseEvent>
#include"tetrixboard.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);//无边框，无法移动
    setAttribute(Qt::WA_TranslucentBackground,true);
    ui->frame->setNextPieceLabel(ui->labelNextPiece);
    connect(ui->btnStart,&QPushButton::clicked,ui->frame,&TetrixBoard::start);
    connect(ui->btnStop,&QPushButton::clicked,ui->frame,&TetrixBoard::puase);
    connect(ui->btnRestart,&QPushButton::clicked,ui->frame,&TetrixBoard::restart);
    connect(ui->frame,&TetrixBoard::scoreChanged,
            ui->lcdScore,qOverload<int>(&QLCDNumber::display));
    connect(ui->frame,&TetrixBoard::levelChanged,
            ui->lcdSpeed,qOverload<int>(&QLCDNumber::display));
    connect(ui->frame,&TetrixBoard::linesRemovedChanged,
            ui->lcdRemoved,qOverload<int>(&QLCDNumber::display));
    ui->btnStart->setFocusPolicy(Qt::NoFocus);
    ui->btnStop->setFocusPolicy(Qt::NoFocus);
    ui->btnExit->setFocusPolicy(Qt::NoFocus);
    ui->btnRestart->setFocusPolicy(Qt::NoFocus);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint mousePos=event->globalPosition().toPoint();//鼠标相对于整个屏幕
    QPoint topLeft=geometry().topLeft();//窗口相对于整个屏幕
    winPos=mousePos-topLeft;
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    winPos=QPoint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint mousePos=event->globalPosition().toPoint();//鼠标相对于整个屏幕
    QPoint endPos=mousePos-winPos;
    move(endPos);

}

void MainWindow::on_btnStop_clicked()
{
    if(ui->btnStop->text()=="暂停")
        ui->btnStop->setText("恢复");
    else
        ui->btnStop->setText("暂停");
}



