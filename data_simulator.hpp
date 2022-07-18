#include<unordered_map>

class data_simulator
{
private:
    static data_simulator *instance;
    data_simulator(){};
    ~data_simulator(){};
    
public:
static data_simulator *get_instance();
static std::unordered_map <std::string,double> simulator_table;
void update_data();

};

