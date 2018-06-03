#include "generateauto.h"
#include <fstream>

GenerateAuto::GenerateAuto(string path_arg)
{
 path = path_arg;
}
GenerateAuto::GenerateAuto()
{

}

GenerateAuto::GenerateAuto(vector<Motor2> motors_arg, vector<string> servos_arg, vector<string> sensors_arg)
{
    motors = motors_arg;
    servos = servos_arg;
    sensors = sensors_arg;
}

bool GenerateAuto::add_to_motors(Motor2 motor_arg)
{
    motors.push_back(motor_arg);
    refresh_drive_motors();
}

void GenerateAuto::refresh_drive_motors()
{
    vector<Motor2> *temp;
    for (int i =0; i < 0;i ++)
    {
        if (motors.at(i).isDriveMotor())
            temp->push_back(motors.at(i));
    }
    drive_motors = temp;
}

bool GenerateAuto::add_to_servos(string servo_arg)
{
    servos.push_back(servo_arg);
}
bool GenerateAuto::add_to_sensors(string sensor_arg)
{
    sensors.push_back(sensor_arg);
}
bool GenerateAuto::adjust_motor_inversion(string motorName, bool inversion)
{
}

vector<string> GenerateAuto::set_drive_motors_dir(bool inversion)
{
    vector<string> output;
    string temp;
    for (int i =0; i < motors.size(); i++)
    {
        std::cout <<"made it here pop"<<std::endl;
        if (motors.at(i).isDriveMotor())
        {
        temp = motors.at(i).getMotorName()+".setDirection(DcMotor.Direction.";
        if (!inversion)
        {
            temp += "FORWARD);\n";
        }
        else
        {
            temp+= "REVERSE);\n";
        }
        output.push_back(temp);
    }
        }
    return output;
    }
vector<string> GenerateAuto::set_drive_motors_runmode(RunMode runMode)
{
    string runModeS;
    vector<string> output;
    string tempLine;
    switch (runMode)
    {
        case RUN_TO_POSITION:
        runModeS = "RUN_TO_POSITION";
        break;
    case STOP_AND_RESET_ENCODER:
        runModeS = "STOP_AND_RESET_ENCODER";
        break;
    case RUN_USING_ENCODER:
        runModeS = "RUN_USING_ENCODER";
        break;
    case RUN_WITHOUT_ENCODER:
        runModeS = "RUN_WIHOUT_ENCODER";
        break;
    default:
       runModeS = "RUN_WIHOUT_ENCODER";
       break;
    }

    for (int i =0; i < motors.size(); i++)
    {
        if (motors.at(i).isDriveMotor())
        {
            tempLine = "robot."+motors.at(i).getMotorName()+"setMode(DcMotor.RunMode."+runModeS+");\n";
            output.push_back(tempLine);
        }
    }
    return output;

}

vector<string> GenerateAuto::set_drive_motors_brake_settings(BrakeSettings brakeSettings)
{
    string brakeSettingsS;
    vector<string> output;
    string tempLine;
    switch (brakeSettings)
    {
        case FLOAT:
        brakeSettingsS = "FLOAT";
        break;
    case BRAKE:
        brakeSettingsS = "BRAKE";
        break;
    default:
       brakeSettingsS = "FLOAT";
       break;
    }

    for (int i =0; i < motors.size(); i++)
    {
        if (motors.at(i).isDriveMotor())
        {
            tempLine = "robot."+motors.at(i).getMotorName()+"setZeroPowerBehavior(DcMotor.ZeroPowerBehavior."+brakeSettingsS+");\n";
            output.push_back(tempLine);
        }
    }
    return output;

}

bool GenerateAuto::outputCode()
{
    std::cout<<"IN ExPORT FUNCTION"<<std::endl;
    ofstream file_output("test.txt");

    vector<string> output;
    string temp = "public enum Type {FORWARD,REVERSE,CLOCKWISE, COUNTCLOCK,IDLE };\n";
    output.push_back(temp);
    temp = "public void setup(){\n";
    output.push_back(temp);
    std::cout<<"test before for";
    for (int i =0; i < motors.size(); i++)
    {
        std::cout <<"made it here pop";
        temp = motors.at(i).getMotorName()+".setDirection(DcMotor.Direction.";
        if (!motors.at(i).getInversion())
        {
            temp += "FORWARD);\n";
        }
        else
        {
            temp+= "REVERSE);\n";
        }
        output.push_back(temp);
    }
    temp = "}\n";
    output.push_back(temp);
    temp = "public void do(Type type, double magnitude){\n";
    output.push_back(temp);
    temp = "switch(type){\n";
    output.push_back(temp);
    temp = "case FORWARD:\n";
    output.push_back(temp);
    vector<string> temp2 = set_drive_motors_dir(false);
    output.insert(output.end(),temp2.begin(),temp2.end());
    temp2 = set_drive_motors_runmode(RUN_TO_POSITION);
    output.insert(output.end(),temp2.begin(),temp2.end());
    temp2 = set_drive_motors_brake_settings(BRAKE);
    output.insert(output.end(),temp2.begin(),temp2.end());
    for (int i =0; i < motors.size(); i++)
    {
        if (motors.at(i).isDriveMotor())
        {
            temp = "robot."+motors.at(i).getMotorName()+".setTargetPosition(magnitude+robot."+motors.at(i).getMotorName()+".getCurrentPosition());\n";
            output.push_back(temp);
        }
    }
    temp = "double timer = System.nanoTime()+(8*Math.pow(10,9));";
    output.push_back(temp);
    for (int i =0; i < motors.size(); i++)
    {
        if (motors.at(i).isDriveMotor())
        {
            temp = "robot."+motors.at(i).getMotorName()+"setPower("+to_string(motPow)+");\n";
            output.push_back(temp);
        }
    }

    temp = "while ("+drive_motors->at(0).getMotorName()+"isBusy() && opModeIsActive() && timer > System.nanoTime()){\n";
    output.push_back(temp);

    temp = "telemetry.addData(\"Distance Traveled \", robot."+drive_motors->at(0).getMotorName()+".getCurrentPosition());\n";
    output.push_back(temp);
    temp = "telemetry.update();\n";
    output.push_back(temp);
    temp = "idle();";
    output.push_back(temp);
    for (int i =0; i < motors.size(); i++)
    {
        if (motors.at(i).isDriveMotor())
        {
            temp = "robot."+motors.at(i).getMotorName()+"setPower("+to_string(0)+");\n";
            output.push_back(temp);
        }
    }
    temp= "}\n";
    output.push_back(temp);
    temp2 = set_drive_motors_runmode(STOP_AND_RESET_ENCODER);
    output.insert(output.end(),temp2.begin(),temp2.end());
    temp2 = set_drive_motors_runmode(RUN_WITHOUT_ENCODER);
    output.insert(output.end(),temp2.begin(),temp2.end());

    temp = "}\n";
    output.push_back(temp);
     //close statement
    for (int i =0; i < output.size(); i++)
    {
        file_output<<output.at(i);
    }
    file_output.close();


}
