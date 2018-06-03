#include "motorconfigw.h"
#include "ui_motorconfigw.h"
#include <iostream>

MotorConfigW::MotorConfigW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MotorConfigW)
{
    ui->setupUi(this);
    invertMotBol= false;
    driveMotBol = false;
    motorName = "temp";
    motorNameEdit = ui->motorNamEdit;
}

MotorConfigW::~MotorConfigW()
{
    delete ui;
}

void MotorConfigW::on_saveSetBtn_clicked()
{
    this->close();
}

QString MotorConfigW::getMotorName()
{
    return motorName;
}

bool MotorConfigW::getInversion()
{
    return invertMotBol;
}

bool MotorConfigW::getDriveMotor()
{
    return driveMotBol;
}

void MotorConfigW::on_driveMotBol_toggled(bool checked)
{
    driveMotBol = checked;
}

void MotorConfigW::on_invertMotBol_toggled(bool checked)
{
    invertMotBol = checked;
}

void MotorConfigW::on_motorNamEdit_editingFinished()
{
    //std::cout<<motorNameEdit->text().toStdString()<<std::endl;
    motorName = motorNameEdit->displayText();
}
