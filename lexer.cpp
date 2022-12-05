#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "lexer.hpp"



void Lexer::create_data()
{
    std::string myline;
    std::ifstream MyReadFile("my_text.txt");
    while (getline(MyReadFile, myline))
    {

        std::vector<std::string> texts;
        std::vector<std::string> row = splite_row(myline, texts);
        alllines.push_back(row);
    }
}

std::vector<std::string> Lexer::splite_row(const std::string& str,std::vector<std::string>& texts)
{

    std::string word = "";
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
