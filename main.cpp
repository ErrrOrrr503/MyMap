#include <iostream>
#include "map.h"

using namespace std;

int main()
{
    mymap <std::string, std::string> my_map;
    my_map["a"] = "a";
    my_map["b"] = "b";
    my_map["c"] = "c";
    my_map["0"] = "0000";
    my_map["2"] = "2";
    my_map["1"] = "1";
    my_map.print ();
    my_map["a"] = "weuirwoy";
    my_map.print();
    cout << "|||test|||   " << my_map["0"] << std::endl;
    cout << "_ERASING_NO_ELEM " << my_map.erase ("egnkw") << std::endl;
    cout << "_ERASING_ELEM " << my_map.erase ("a") << std::endl;
    my_map.print ();
    mymap <int, std::string> int_string;
    int_string.insert(2, "dsvs");
    int_string.insert(10, "dsvs");
    int_string.print();
    return 0;
}
