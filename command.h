#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <iostream>
#include <map>
using namespace std;
//Think as the type is a direction of some sort.
enum Type
{
   FORWARD,REVERSE,CLOCKWISE, COUNTCLOCK,IDLE
};


class Command
{
private:
  Type command_type;
  double type_magnitude;

public:
    Command();
    Command(Type command_type_arg, double type_mag_arg);
    Type get_command_type();
    bool set_command_type(Type command_type_arg);
    string output_command();

};

#endif // COMMAND_H
