#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtBluetooth>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    agent = new QBluetoothDeviceDiscoveryAgent; // create an object in ctors
    connect(agent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
    agent->start();
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_find_clicked()
{
//    ui->listWidget->show();
    ui->listWidget->clear();
    agent->stop();
    agent->start();
}

void MainWindow::on_on_clicked()
{
    socket->write("1");
    qDebug() << "ON";
}

void MainWindow::on_off_clicked()
{
    socket->write("0");
     qDebug() << "OFF";
}

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    //ui->listWidget->addItem(device.address().toString());
    ui->listWidget->addItem(device.address().toString() + " " + device.name());
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    string = item->text();
    qDebug() << "string1 = " << string;
    string = string.split(" ").at(0); //get the 1st word in string
    qDebug() << "string2 = " << string;
    ui->listWidget->addItem(string);
    static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
    socket->connectToService(QBluetoothAddress(string), QBluetoothUuid(serviceUuid), QIODevice::ReadWrite);
}
