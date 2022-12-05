#pragma once


#include <vector>
#include <unordered_map>



class Command
{
public:
    virtual void do_command(const std::vector<std::string> &) = 0;
    Command() = default;
   virtual ~Command() = default;
};

class OpenDataServer : public Command
{
public:
    void do_command(const std::vector<std::string> &);
    OpenDataServer() = default;
    ~OpenDataServer() = default;
};

class Connect_Client : public Command
{
public:
    void do_command(const std::vector<std::string> &);
    Connect_Client() = default;
    ~Connect_Client() = default;
};

class Var : public Command
{
public:
    void do_command(const std::vector<std::string> &);
    Var() = default;
    ~Var() = default;
};

class Variables : public Command
{
public:
    void do_command(const std::vector<std::string> &);
    Variables() = default;
    ~Variables() = default;
};

class While_Loop : public Command
{
public:
    void do_command(const std::vector<std::string> &);
    While_Loop() = default;
    ~While_Loop() = default;

private:
    bool expression(double x, const std::string &operat, double y);
};

class Print_Text : public Command
{
public:
    void do_command(const std::vector<std::string> &);
    Print_Text() = default;
    ~Print_Text() = default;
};

class Sleep : public Command
{
public:
    void do_command(const std::vector<std::string> &);
    Sleep() = default;
    ~Sleep() = default;
};
