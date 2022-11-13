#pragma once
#include <iostream>
#include <unordered_map>
#include "command.hpp"

class Parser
{
public:
    static vector<vector<string>> lines_while;
    unordered_map<std::string, Command *> command_map;

public:
    void parse(std::vector<std::vector<std::string>> &);
    Parser();
    ~Parser();

private:
    string commands;
};
