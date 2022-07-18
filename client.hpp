#include <iostream>
class client
{
private:
         static client *instance;
         client(){};
        ~client(){};
    
public:
 void thread_client(std::string);
    void Connect(int port, const char *ip);
   static void Send(std::string send_set);
   static client *get_instance();
};
