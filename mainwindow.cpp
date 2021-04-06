#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(420,300);

    QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings",QSettings::NativeFormat);
    QString proxyServer=settings.value("ProxyServer","").toString();
    qDebug()<<" 已经设置的代理 ："<<proxyServer;
    QStringList dats=proxyServer.split(":");
    ui->lineEditIp->setText(dats[0]);
    ui->lineEditPort->setText(dats[1]);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonStart_clicked()
{

     QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings",QSettings::NativeFormat);
     QString ipandport=ui->lineEditIp->text()+":"+ui->lineEditPort->text();
     qDebug()<<"ip and port:"<<ipandport;

     settings.setValue("ProxyServer",ipandport);
     settings.setValue("ProxyEnable",1);

}

void MainWindow::on_buttonStop_clicked()
{

    QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings",QSettings::NativeFormat);
    settings.setValue("ProxyEnable",0);
}
