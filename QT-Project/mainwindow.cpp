#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QApplication>
#include<string>


static int count=0;
static int shutdownTime=120;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ChangeTime()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_released()
{
    timer->stop();
    int time=shutdownTime-count;

    std::string windowsCommand("shutdown -s -t ");
    std::string unixCommand("shutdown -h +");

    windowsCommand+=std::to_string(time);
    unixCommand+=std::to_string(int(time/60)+1);

    try
    {
      system(windowsCommand.c_str());
    }
    catch(...)
    {
    }
    try
    {
      system(unixCommand.c_str());
    }
    catch(...)
    {
    }
    exit(100);
}

void MainWindow::ChangeTime()
{
    count++;

    if(count>=shutdownTime)
    {
        timer->stop();
        on_pushButton_2_released();
    }

    ui->countdown->setText(QString::number(shutdownTime-count));
}

void MainWindow::on_pushButton_released()
{

}
