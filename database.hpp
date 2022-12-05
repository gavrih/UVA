#include <string>
#include <unordered_map>

class DB
{
public:
    static DB &get_instance();
    void insert(const std::string &name, const std::string &value, const std::string &path );
    double getValue(const std::string &name);
    std::string getPath(const std::string &name);
    void setData(const std::string  &name, const double  &value);

private:
    DB() = default;

private:
    std::unordered_map<std::string, double> symbolTable;
    std::unordered_map<std::string, std::string> namePath;
};
