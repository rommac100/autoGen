#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QEventLoop>
#include <motor2.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    deviceCombo = ui->deviceCombo;
    deviceList = ui->deviceList;
    initializeDeviceCombo();
    generateAuto = GenerateAuto();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeDeviceCombo()
{
    deviceCombo->addItem("Motor");
    deviceCombo->addItem("Servo");
    deviceCombo->addItem("Sensor");
}

void MainWindow::on_MotorConfigDestroyed()
{

}

void MainWindow::on_addDevBut_clicked()
{
    QString deviceInfo = "temp";
    QEventLoop eventLoop;
    Motor2 motor2;
    switch (currentDeviceType)
    {
    case Servo:
        generateAuto.add_to_servos(currentDeviceSelect.toStdString());
        break;
    case MotorE:
        motorConfigWin = new MotorConfigW(this);
        motorConfigWin->exec();
        //connect(this, SIGNAL(destroyed()), & eventLoop, SLOT(on_MotorConfigDestroyed()));
        //Motor2 motor2;
        motor2 = Motor2(motorConfigWin->getMotorName().toStdString(),motorConfigWin->getInversion(),motorConfigWin->getDriveMotor());
        generateAuto.add_to_motors(motor2);
        deviceInfo = motorConfigWin->getMotorName()+"Motor-"+"Drive-"+QString::number(motorConfigWin->getDriveMotor())+"-Invert-"+QString::number(motorConfigWin->getInversion());
        break;
    case Sensor:
        generateAuto.add_to_sensors(currentDeviceSelect.toStdString());
        break;
    default:
        std::cout<<"ERROR:::: DONT KNOW WHAT TYPE THIS IS."<<std::endl;
        break;
    }
    deviceList->addItem(deviceInfo);
}

void MainWindow::on_deviceCombo_activated(int index)
{
    currentDeviceSelect = deviceCombo->currentText();
    switch (index)
    {
    case 0:
        currentDeviceType = MotorE;
        break;
    case 1:
        currentDeviceType = Servo;
        break;
    case 2:
        currentDeviceType = Sensor;
        break;
    default:
        currentDeviceType = MotorE;
        break;
    }
}

void MainWindow::on_outputCBtn_clicked()
{
    std::cout<<"testing export"<<endl;
   generateAuto.outputCode();
}
