
#include <iostream>
#include <vector>
#include "parser.hpp"
#include "lexer.hpp"
 

int main()
{

    Lexer::get_instance()->create_data();
    data_command::get_instance1()->update_map();
    parser ps;
    ps.par(Lexer::get_instance()->alllines);




    void delete_refrense();

    return 0;
}
