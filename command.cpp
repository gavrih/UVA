
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

double check_value(string a)
{
  string path = var_map[a];
  double value = data_simulator::get_instance()->simulator_table[path];

  return value;
}

bool check_element(unordered_map<string, double> map, string element)

{
  if (map.count(element))
    return 1;
  else
    return 0;
}

void change_equation(vector<vector<string>> lines_while)
{
  string word;
  vector<vector<string>> copy_lines_while = lines_while;
  for (int i = 0; i < lines_while.size(); i++)
  {
    vector<string> line = copy_lines_while[i];

    if (var_map.find(line[0]) != var_map.end())
    {
      for (int j = 2; j < line.size(); j++)
      {
        word = line[j];
        if (var_map.find(word) != var_map.end())
        {
          double value = check_value(word);
          

          string str_value = to_string(value);
          copy_lines_while[i][j] = str_value;
        }
      }
    }
  }
  string str_to_sunting = "";
  for (int i = 0; i < copy_lines_while.size(); i++)
  {
    for (int j = 2; j < copy_lines_while[i].size(); j++)
    {
      str_to_sunting += (copy_lines_while[i][j]);
    }
    if (var_map.find(copy_lines_while[i][0]) != var_map.end())
    {

      Calculator c;
      vector<string> line_fix = {copy_lines_while[i][0], copy_lines_while[i][1], to_string(c.calculate(str_to_sunting))};
      string send_set = "set " + var_map[line_fix[0]] + " " + line_fix[2] + "\r\n";
      client::get_instance()->Send(send_set);
    }
    str_to_sunting = "";
  }
}

void openDataServer::do_command(vector<vector<string>> alllines, int num_line)
{
  cout << "connecting server......" << endl;
  vector<string> line = alllines[num_line];

  int port = stoi(line[1]);

  server::get_instance()->openServer(port);

};

void connect_client::do_command(vector<vector<string>> alllines, int num_line)
{

  vector<string> line = alllines[num_line];
  int port = stoi(line[2]);
  const char *ip = line[1].c_str();

  client::get_instance()->Connect(port, ip);
  cout << "client connect" << endl;
  
}

void var::do_command(vector<vector<string>> alllines, int num_line)
{
  vector<string> line = alllines[num_line];
  if (line[3] == "bind")
  {
    var_map.insert({line[1], line[4]});
    data_simulator::get_instance()->simulator_table.insert({line[4], 0});
    
  }
  else
  {
    var_map.insert({line[1], to_string(check_value(line[3]))});
    data_simulator::get_instance()->simulator_table.insert({line[1],check_value(line[3])});
    
  }
}

void variables::do_command(vector<vector<string>> alllines, int num_line)
{

  vector<string> line = alllines[num_line];

  if (line.size() == 3)

  {

    string send_set = "set " + var_map[line[0]] + " " + line[2] + "\r\n";

    client::get_instance()->Send(send_set);
data_simulator::get_instance()->simulator_table[var_map[line[0]]] = stoi(line[2]);
   
  }
  else
  {

    for (int i = 2; i < line.size(); i++)
    {
      if (check_element(data_simulator::get_instance()->simulator_table, line[i]) == 1)
      {
        line[i] = data_simulator::get_instance()->simulator_table[line[i]];
      }
    }
  }
}

void while_loop::do_command(vector<vector<string>> alllines, int num_line)
{
  parser pars;
  vector<vector<string>> lines_while;
  int i = num_line + 1;
  while (alllines[i][0] != "}")
  {
    for (int j = 0; j < alllines[i].size(); j++)
    {
      alllines[i][0].erase(alllines[i][0].begin());
      lines_while.push_back(alllines[i]);
      i++;
    }
  }

  while (check_value(alllines[num_line][1]) < stoi(alllines[num_line][3]))

  {
    pars.par(lines_while);
    change_equation(lines_while);
  }
 
}

void print_text::do_command(vector<vector<string>> alllines, int num_line)
{
  vector<string> line = alllines[num_line];
  // sleep(0.8);
  if (line[1][0] == '"')
  {
    cout << line[1] << endl;
  }
  
  
  else
  {
    cout << line[1] << ":" << check_value(line[1]) << endl;
  }
};
void Sleep::do_command(vector<vector<string>> alllines, int num_line)
{
  vector<string> line = alllines[num_line];
  if (line.size() == 2)

  {

    cout << "Waiting " << line[1] << " Milliseconds" << endl;
    this_thread::sleep_for(chrono::milliseconds(stoi(line[1])));
  }
};