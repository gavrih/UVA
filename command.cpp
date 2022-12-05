#include <iostream>
#include <chrono>
#include "command.hpp"
#include "server.hpp"
#include "client.hpp"
#include "database.hpp"
#include "parser.hpp"
#include "tools.cpp"
#include "ShuntingYardToken.cpp"

std::string change_equation(const std::string &str)
{
  std::string new_string;
  for (size_t i = 0; i < str.size(); i++)
  {
    if (isalpha(str[i]))
    {
      std::string str_;
      while (isalpha(str[i]) || isdigit(str[i]))
      {
        str_ += str[i];
        i++;
      }
      i--;

      double value = DB::get_instance().getValue(str_);
      new_string += std::to_string(value);
    }
    else
    {

      new_string += str[i];
    }
  }
  Calculator c;
  std::string new_value = std::to_string(c.calculate(new_string));
  return new_value;
}

void OpenDataServer::do_command(const std::vector<std::string> &line)
{
  std::cout << "connecting server......" << std::endl;

  int port = stoi(line[1]);

  Server::get_instance().openServer(port);
}

void Connect_Client::do_command(const std::vector<std::string> &line)
{

  int port = stoi(line[2]);
  const char *ip = line[1].c_str();

  Client::get_instance().connecting_client(port, ip);
  std::cout << " The client connected" << std::endl;
}

void Var::do_command(const std::vector<std::string> &line)
{
  if (line[3] == "bind")
  {
    std::string path;
    for (size_t i = 0; i < line[4].size(); i++)
    {
      if (line[4][i] == '"')
          continue;
      else
          path += line[4][i];
    }

      DB::get_instance().insert(line[1], "0.0", path);
  }
  else
  {
    std::string string_line;
    for (size_t i = 3; i < line.size(); i++)
    {
      string_line += line[i];
    }
    std::string value = change_equation(string_line);

    DB::get_instance().insert(line[1], value, " ");
  }
}

void Variables::do_command(const std::vector<std::string> &line)
{
  std::string string_line;
  for (size_t i = 2; i < line.size(); i++)
  {
    string_line += line[i];
  }
  std::string new_value = change_equation(string_line);

  Client::get_instance().send_to_simulator(DB::get_instance().getPath(line[0]), new_value);
}

void While_Loop::do_command(const std::vector<std::string> &line)
{
  Parser pars;
  while (expression(DB::get_instance().getValue(line[1]), line[2], stod(line[3])))
  {
    pars.parse(Parser::lines_while);
  }
}

bool While_Loop::expression(double x, const std::string &operat, double y)
{
  if ((operat == "<" && (x < y)))
    return true;
  else if ((operat == ">") && (x > y))
    return true;
  else if ((operat == ">=") && (x >= y))
    return true;
  else if ((operat == "<=") && (x <= y))
    return true;
  else if ((operat == "==") && (x == y))
    return true;
  else if ((operat == "!=") && (x != y))
    return true;
  return false;
}

void Print_Text::do_command(const std::vector<std::string> &line)
{

  if (line[1].front() == '"')
  {
    std::cout << line[1] << std::endl;
  }

  else
  {
    std::string new_str;
    for (size_t i = 1; i < line.size(); i++)
    {
      new_str += line[i];
    }

    std::cout << line[1] << ":" << change_equation(new_str) << std::endl;
  }
}

void Sleep::do_command(const std::vector<std::string> &line)
{
  std::string new_str;
  for (size_t i = 1; i < line.size(); i++)
  {
    new_str += line[i];
  }
  std::cout << "Waiting " << change_equation(new_str) << " Milliseconds" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(stoi(line[1])));
}