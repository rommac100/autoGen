#include "command.h"

inline const string To_String(Type type)
{
    switch (type)
    {
    case IDLE: return "IDLE";
    case FORWARD: return "FORWARD";
    case REVERSE: return "REVERSE";
    case CLOCKWISE: return "CLOCKWISE";
    case COUNTCLOCK: return "COUNTCLOCK";
    default: return "NULL";
    }
}

Command::Command()
{
    command_type = IDLE;
    type_magnitude = 0;
}

Command::Command(Type command_type_arg, double type_mag_arg)
{
    command_type = command_type_arg;
    type_magnitude = type_mag_arg;
}

Type Command::get_command_type()
{
    return command_type;
}

string Command::output_command()
{
    string temp = "do("+To_String(command_type)+","+to_string(type_magnitude)+")";
    return temp;
}

bool Command::set_command_type(Type command_type_arg)
{
    command_type = command_type_arg;
    return true;
}
