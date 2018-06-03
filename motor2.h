#ifndef MOTOR_H
#define MOTOR_H
#include <iostream>
#include <string>

class Motor2
{
public:
    Motor2();
    Motor2(std::string motNameArg, bool invertArg, bool driveMotArg);
    void setMotorName(std::string motNameArg);
    void setDriveMotor(bool driveMotArg);
    void setInversion (bool invertArg);
    std::string getMotorName();
    bool isDriveMotor();
    bool getInversion();
private:
    //false = forward, true = reverse
    bool inverted;
    bool driveMotor;
    std::string motorName;
};

#endif // MOTOR_H
