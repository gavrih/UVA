
#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include "command.hpp"
#include "server.hpp"
#include "client.hpp"
#include "lexer.hpp"
#include "data_simulator.hpp"
#include "parser.hpp"

using namespace std;

bool check_element(unordered_map<string, double> map, string element)

{
  if (map.count(element))
    return 1;
  else
    return 0;
}
double check_value(string a)
{
  double value;
  if (check_element(data_simulator::get_instance()->symbol_table, a) == 1)
  {
    value = data_simulator::get_instance()->symbol_table[a];
    return value;
  }
  else
  {

    string path = var_map[a];
    value = data_simulator::get_instance()->symbol_table[path];
    return value;
  }
}

void change_equation(vector<string> line)
{

  if (var_map.find(line[0]) != var_map.end())
  {
    for (int i = 2; i < line.size(); i++)
    {

      if (var_map.find(line[i]) != var_map.end())
      {
        double value = check_value(line[i]);

        string str_value = to_string(value);
        line[i] = str_value;
      }
    }
  }

  string str_to_sunting = "";
  for (int i = 2; i < line.size(); i++)
  {

    str_to_sunting += (line[i]);
  }

  Calculator c;
  string new_valoue = to_string(c.calculate(str_to_sunting));
  vector<string> line_fix = {line[0], line[1], new_valoue};
  string send_set = "set " + var_map[line_fix[0]] + " " + line_fix[2] + "\r\n";
  Client::get_instance()->send_to_simulator(send_set);
  data_simulator::get_instance()->symbol_table[var_map[line_fix[0]]] = stod(new_valoue);
  str_to_sunting = "";
}

void OpenDataServer::do_command(const vector<string> &line)
{
  cout << "connecting server......" << endl;

  int port = stoi(line[1]);

  Server::get_instance()->openServer(port);
}

void Connect_Client::do_command(const vector<string> &line)
{

  int port = stoi(line[2]);
  const char *ip = line[1].c_str();

  Client::get_instance()->connecting_client(port, ip);
  cout << " The client connected" << endl;
}

void Var::do_command(const vector<string> &line)
{

  for (int i = 0; i < line.size(); i++)
  {
  }

  if (line[3] == "bind")
  {
    string path;
    for (int i = 0; i < line[4].size(); i++)
    {
      if (line[4][i] == '"')
      {
        continue;
      }
      else
      {
        path += line[4][i];
      }
    }

    var_map.insert({line[1], path});
    data_simulator::get_instance()->symbol_table.insert({path, 0.0});
  }
  else
  {
    var_map.insert({line[1], to_string(check_value(line[3]))});
    data_simulator::get_instance()->symbol_table.insert({line[1], check_value(line[3])});
  }
}

void Variables::do_command(const vector<string> &line)
{
  change_equation(line);
}

void While_Loop::do_command(const vector<string> &line)
{
  Parser pars;
  while (check_value(line[1]) < stoi(line[3]))
  {
    pars.parse(Parser::lines_while);
  }
}

void Print_Text::do_command(const vector<string> &line)
{

  if (line[1].front() == '"')
  {
    cout << line[1] << endl;
  }

  else
  {
    cout << line[1] << ":" << check_value(line[1]) << endl;
  }
}

void Sleep::do_command(const vector<string> &line)
{

  cout << "Waiting " << line[1] << " Milliseconds" << endl;
  this_thread::sleep_for(chrono::milliseconds(stoi(line[1])));
}