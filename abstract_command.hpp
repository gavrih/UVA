#include <vector>

class Command
{
public:
    virtual void do_command(const std::vector<std::string> &) = 0;
    Command() = default;
    virtual ~Command() = default;
};