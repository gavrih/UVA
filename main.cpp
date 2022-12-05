#include <vector>
#include "parser.hpp"
#include "lexer.hpp"

int main()
{
    Lexer *lex = new Lexer();
    lex->create_data();
    Parser *ps = new Parser();
    ps->parse(lex->alllines);
    
    delete lex;
    delete ps;
     
    return 0;
}
