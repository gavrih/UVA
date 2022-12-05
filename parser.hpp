#pragma once

#include <unordered_map>
#include "command.hpp"

class Parser
{
public:
    static std::vector<std::vector<std::string>> lines_while;
    std::unordered_map<std::string, Command *> command_map;

public:
    void parse( std::vector<std::vector<std::string>> &);
    Parser();
    ~Parser();

private:
    std::string commands;
};
