#pragma once
#include <unordered_map>
#include "command.hpp"

class data_command
{
private:
    data_command(){};
    ~data_command();
    static data_command *instance;

public:
    void update_map();
    static data_command *get_instance1();
    unordered_map<std::string, command *> command_map;

};
