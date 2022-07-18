
#include "data_command.hpp"


data_command *data_command::instance = 0;

data_command *data_command::get_instance1()
{

    if (!instance)
    {
        instance = new data_command();
    }
    return instance;
}

command *OpenDataServer = new openDataServer();
command *Connect_client = new connect_client();
command *VarConvertion = new var();
command *variables_equal = new variables();
command *While_Loop = new while_loop();
command *Print_Text = new print_text();
command *Sleeping =new Sleep();

void data_command::update_map()
{
    command_map["openDataServer"] = OpenDataServer;
    command_map["connect"] = Connect_client;
    command_map["var"] = VarConvertion;  
    command_map["="] = variables_equal;
    command_map["while"] = While_Loop;
    command_map["print"] = Print_Text;
    command_map["sleep"] = Sleeping;
}

void delete_refrense()
{

delete OpenDataServer;
delete Connect_client;
delete VarConvertion;
delete variables_equal;
delete While_Loop;
delete Print_Text;
delete Sleeping;

}