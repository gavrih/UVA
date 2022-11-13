
#include <iostream>
#include <thread>
#include <unordered_map>
#include <vector>
class Server
{

public:
  void openServer(int port);
  static void read_data();
  static Server *get_instance();

public:
  std::vector<std::string> paths = {"/instrumentation/airspeed-indicator/indicated-speed-kt", "/sim/time/warp", "/controls/switches/magnetos", "/instrumentation/heading-indicator/offset-deg", "/instrumentation/altimeter/indicated-altitude-ft", "/instrumentation/altimeter/pressure-alt-ft", "/instrumentation/attitude-indicator/indicated-pitch-deg", "/instrumentation/attitude-indicator/indicated-roll-deg", "/instrumentation/attitude-indicator/internal-pitch-deg", "/instrumentation/attitude-indicator/internal-roll-deg", "/instrumentation/encoder/indicated-altitude-ft", "/instrumentation/encoder/pressure-alt-ft", "/instrumentation/gps/indicated-altitude-ft", "/instrumentation/gps/indicated-ground-speed-kt", "/instrumentation/gps/indicated-vertical-speed", "/instrumentation/heading-indicator/indicated-heading-deg", "/instrumentation/magnetic-compass/indicated-heading-deg", "/instrumentation/slip-skid-ball/indicated-slip-skid", "/instrumentation/turn-indicator/indicated-turn-rate", "/instrumentation/vertical-speed-indicator/indicated-speed-fpm", "/controls/flight/aileron", "/controls/flight/elevator", "/controls/flight/rudder", "/controls/flight/flaps", "/controls/engines/engine/throttle", "/controls/engines/current-engine/throttle", "/controls/switches/master-avionics", "/controls/switches/starter", "/engines/active-engine/auto-start", "/controls/flight/speedbrake", "/sim/model/c172p/brake-parking", "/controls/engines/engine/primer", "/controls/engines/current-engine/mixture", "/controls/switches/master-bat", "/controls/switches/master-alt", "/engines/engine/rpm"};

private:
  static Server *instance;

private:
  Server() = default;
  ~Server(){delete instance;};
  std::vector<double> splite_line(std::string);
};