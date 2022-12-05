class Client
{
public:
    void connecting_client(int port, const char *ip);
    void send_to_simulator(const std::string &path, const std::string &value);
    static Client& get_instance();

private:
    Client() = default;
    

private:
    
    char buffer[1024] = {0};
    int sock = 0;
};
