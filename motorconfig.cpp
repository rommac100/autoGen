#include "motorconfig.h"
#include "ui_motorconfig.h"

MotorConfig::MotorConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MotorConfig)
{
    ui->setupUi(this);
    motorName = "motor";
}

MotorConfig::~MotorConfig()
{
    delete ui;
}

void MotorConfig::on_saveSetBtn_clicked()
{
    this->close();
}

QString MotorConfig::getMotorName()
{
    return motorName;
}

bool MotorConfig::getInversion()
{
    return invertMotBol;
}

bool MotorConfig::getDriveMotor()
{
    return driveMotBol;
}

void MotorConfig::on_driveMotBol_toggled(bool checked)
{
    driveMotBol = checked;
}

void MotorConfig::on_invertMotBol_toggled(bool checked)
{
    invertMotBol = checked;
}

void MotorConfig::on_motorNamEdit_returnPressed()
{
   motorName = motorNameEdit->displayText();
}
