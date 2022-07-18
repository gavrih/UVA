
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "parser.hpp"

using namespace std;

void parser::par(vector<vector<string>> alllines)
{
  for (int i = 0; i < alllines.size(); i++)
  {
    
    if (alllines[i][1] == "=")
    {
      string commands = alllines[i][1];
      data_command::get_instance1()->command_map[commands]->do_command( alllines,i);
    
    }
    else
    {
      string commands = alllines[i][0];
    data_command::get_instance1()->command_map[commands]->do_command( alllines,i);
    if (commands == "while")
    {
      i=i+9;
    }
    
        

    }

  }
}
