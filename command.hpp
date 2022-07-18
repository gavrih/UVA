#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "SuntingYardToken.cpp"

using namespace std;

class command
{
private:
public:
    virtual void do_command(vector<vector<string>> ,int) = 0;
    command(){};
    ~command(){};
};

class openDataServer : public command
{
private:
    /* data */
public:
    void do_command(vector<vector<string>> ,int);
    openDataServer(/* args */){};
    ~openDataServer(){};
};

class connect_client : public command
{
private:
    /* data */
public:
    void do_command(vector<vector<string>> ,int);
    connect_client(/* args */){};
    ~connect_client(){};
};

static unordered_map<string, string> var_map;
class var : public command
{
private:
    /* data */

public:
    void do_command(vector<vector<string>> ,int);
    var(/* args */){};
    ~var(){};
};
static unordered_map<string, double> var_value;

class variables : public command
{
private:
    /* data */
public:
    void do_command(vector<vector<string>> ,int);
    variables(/* args */){};
    ~variables(){};
};

class while_loop : public command
{
private:
    /* data */
public:
    void do_command(vector<vector<string>> ,int);
    while_loop(){};
    ~while_loop(){};
};

class print_text : public command
{
private:
    /* data */
public:
    void do_command(vector<vector<string>> ,int);
    print_text(){};
    ~print_text(){};
};

class Sleep : public command
{
private:
    /* data */
public:
    void do_command(vector<vector<string>> ,int);
    Sleep(){};
    ~Sleep(){};
};

