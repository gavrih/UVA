#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Lexer
{
private:
    Lexer(){}
static Lexer *instance;
    
    ~Lexer(){}
   

public:
    vector<vector<string>> alllines;
    static Lexer *get_instance();
    void create_data();
    vector<string> splite_row(string, vector<string>);
    
};
