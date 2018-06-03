#include "motor2.h"

Motor2::Motor2()
{

}

Motor2::Motor2(std::string motNameArg, bool invertArg, bool driveMotArg)
{
    inverted = invertArg;
    motorName = motNameArg;
    driveMotor = driveMotArg;
}

bool Motor2::getInversion()
{
    return inverted;
}

bool Motor2::isDriveMotor()
{
    return driveMotor;
}

std::string Motor2::getMotorName()
{
    return motorName;
}

void Motor2::setDriveMotor(bool driveMotArg)
{
    driveMotor = driveMotArg;
}

void Motor2::setInversion(bool invertArg)
{
    inverted = invertArg;
}

void Motor2::setMotorName(std::string motNameArg)
{
    motorName = motNameArg;
}

