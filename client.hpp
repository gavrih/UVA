#include <iostream>

class Client
{
public:
    void connecting_client(int port, const char *ip);
    void send_to_simulator(std::string send_set);
    static Client *get_instance();

private:
    Client() = default;
    ~Client() {delete instance;};

private:
    static Client *instance;
    char buffer[1024] = {0};
    int sock = 0;
};
