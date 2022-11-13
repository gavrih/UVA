#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "lexer.hpp"

using namespace std;

void Lexer::create_data()
{
    string myline;
    ifstream MyReadFile("my_text.txt");
    while (getline(MyReadFile, myline))
    {

        vector<string> texts;
        vector<string> row = splite_row(myline, texts);
        alllines.push_back(row);
    }
}

vector<string> Lexer::splite_row(string str, vector<string> texts)
{

    string word = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            texts.push_back(word);
            word = "";
        }
        else
        {
            
            word = word + x;
        }
    }
    return texts;
}
