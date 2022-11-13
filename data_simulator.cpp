#include <unordered_map>
#include "data_simulator.hpp"
#include "command.hpp"
data_simulator *data_simulator::instance = 0;
data_simulator *data_simulator::get_instance()
{
    if (!instance)
    {
        instance = new data_simulator();
    }

    return instance;
};

std::unordered_map<std::string, double> data_simulator::symbol_table;