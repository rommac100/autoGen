#ifndef GENERATEAUTO_H
#define GENERATEAUTO_H
#include <string>
#include <vector>
#include <command.h>
#include <motor2.h>
using namespace std;

enum RunMode{
    RUN_TO_POSITION,STOP_AND_RESET_ENCODER,RUN_USING_ENCODER,RUN_WITHOUT_ENCODER
};

enum BrakeSettings{
    BRAKE, FLOAT
};

class GenerateAuto
{
private:
    float motPow = .5f;
    vector<Motor2> motors;
    vector<Motor2> *drive_motors;
    vector<string> servos;
    vector<string> sensors;

    //unused at the moment will be used for turning and accurate encoder based movement
    float turn_p;
    float turn_i;
    float turn_d;

    float move_p;
    float move_i;
    float move_d;

    vector<string> set_drive_motors_dir(bool inversion);
    vector<string> set_drive_motors_runmode(RunMode runMode);
    vector<string> set_drive_motors_brake_settings(BrakeSettings brakeSettings);
    void refresh_drive_motors();
    vector<string> init_code;
    vector<Command> commands;

    string path;

public:
    bool add_to_motors(Motor2 motor_arg);
    bool add_to_servos(string servo_arg);
    bool add_to_sensors(string sensor_arg);
    bool adjust_motor_inversion(string motorName, bool inversion);
    vector<string> get_list_motors();
    vector<string> get_list_servos();
    vector<string> get_list_sensors();

    bool outputCode();
    GenerateAuto();
    GenerateAuto(string path_arg);
    GenerateAuto(vector<Motor2> motors_arg, vector<string> servos_arg, vector<string> sensors_arg);
};

#endif // GENERATEAUTO_H
