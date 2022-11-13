#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Lexer
{
public:
    void create_data();
    Lexer() = default;
    ~Lexer() = default;

public:
    vector<vector<string>> alllines;

private:
    vector<string> splite_row(string, vector<string>);
};
