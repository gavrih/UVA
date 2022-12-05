#include <unordered_map>


template <typename T>
bool check_element(const std::unordered_map<std::string, T> &map, const std::string &element)
{
    if (map.count(element))
        return 1;
    else
        return 0;
}
