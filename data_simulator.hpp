#include <unordered_map>

class data_simulator
{
public:
    static data_simulator *get_instance();
    static std::unordered_map<std::string, double> symbol_table;

private:
    static data_simulator *instance;
    data_simulator() = default;
    ~data_simulator() {delete instance;};
};
