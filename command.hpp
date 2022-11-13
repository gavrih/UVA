#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "ShuntingYardToken.cpp"

using namespace std;
static unordered_map<string, string> var_map;

class Command
{
public:
    virtual void do_command(const vector<string> &) = 0;
    Command() = default;
    ~Command() = default;
};

class OpenDataServer : public Command
{
public:
    void do_command(const vector<string> &);
    OpenDataServer() = default;
    ~OpenDataServer() = default;
};

class Connect_Client : public Command
{
public:
    void do_command(const vector<string> &);
    Connect_Client() = default;
    ~Connect_Client() = default;
};

class Var : public Command
{
public:
    void do_command(const vector<string> &);
    Var() = default;
    ~Var() = default;
};

class Variables : public Command
{
public:
    void do_command(const vector<string> &);
    Variables() = default;
    ~Variables() = default;
};

class While_Loop : public Command
{
public:
    void do_command(const vector<string> &);
    While_Loop() = default;
    ~While_Loop() = default;
};

class Print_Text : public Command
{
public:
    void do_command(const vector<string> &);
    Print_Text() = default;
    ~Print_Text() = default;
};

class Sleep : public Command
{
public:
    void do_command(const vector<string> &);
    Sleep() = default;
    ~Sleep() = default;
};
