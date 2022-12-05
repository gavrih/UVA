#include <string>
#include "database.hpp"
#include "tools.cpp"

DB &DB::get_instance()
{
  static DB instance;
  return instance;
}
  
void DB::insert(const std::string &name, const std::string &value, const std::string &path)
{
  if (path != "")
  {
    namePath[name] = path;
    symbolTable[path] = stod(value);
  }
}

double DB::getValue(const std::string &name)
{
  double value;
  if (check_element(namePath, name) == 1)
  {
    std::string path = getPath(name);
    value = symbolTable[path];
  }
  return value;
}
std::string DB::getPath(std::string const &name)
{
  std::string path;
  if (check_element(namePath, name) == 1)
  {
    path = namePath[name];
  }
  return path;
}

void DB::setData(std::string const &path, double const &value)
{
  symbolTable[path] = value;
}