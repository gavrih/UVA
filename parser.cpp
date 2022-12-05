#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "parser.hpp"
#include "lexer.hpp"


std::vector<std::vector<std::string>> Parser::lines_while;

Parser::Parser()
{
  command_map["openDataServer"] = new OpenDataServer();
  command_map["connect"] = new Connect_Client();
  command_map["var"] = new Var();
  command_map["="] = new Variables();
  command_map["while"] = new While_Loop();
  command_map["print"] = new Print_Text();
  command_map["sleep"] = new Sleep();
}
Parser::~Parser()
{
  delete command_map["openDataServer"];
  delete command_map["connect"];
  delete command_map["var"];
  delete command_map["="];
  delete command_map["while"];
  delete command_map["print"];
  delete command_map["sleep"];
}
void Parser::parse( std::vector<std::vector<std::string>> &alllines)
{

  for (size_t i = 0; i < alllines.size(); i++)
  {

    if (!command_map.count(alllines[i][0]))
    {
      commands = alllines[i][1];
      command_map[commands]->do_command(alllines[i]);
    }
    else
    {
      if (alllines[i][0] == "while")
      {
        commands = alllines[i][0];
        int j = i + 1;
        while (alllines[j][0] != "}")
        {

          alllines[j][0].erase(alllines[j][0].begin());

          Parser::lines_while.push_back(alllines[j]);

          j++;
        }
        command_map[commands]->do_command(alllines[i]);
        int size_of_whileloop_vec = Parser::lines_while.size() + 1;
        i = i + size_of_whileloop_vec;
      }

      else
      {
        commands = alllines[i][0];
        command_map[commands]->do_command(alllines[i]);
      }
    }
  }
}
