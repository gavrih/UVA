#include <iostream>
#include <fstream>
#include <string>
#include <vector>



class Lexer
{
public:
    void create_data();
    Lexer() = default;
    ~Lexer() = default;

public:
    std::vector<std::vector<std::string>> alllines;

private:
    std::vector<std::string> splite_row(const std::string&, std::vector<std::string>&);
};
