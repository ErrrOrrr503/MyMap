#include <iostream>
#include "map.h"

using namespace std;

int main()
{
    mymap <std::string, std::string> my_map;
    my_map.insert("g", "g");
    my_map.insert("g", "g");
    my_map.insert("f", "f");
    my_map.insert("c", "c");
    my_map.insert("d", "d");
    my_map.insert("e", "e");
    my_map.insert("b", "b");
    my_map.insert("a", "a");
    my_map.insert("h", "fgdugfiew");
    my_map.insert("j", "j");
    my_map.insert("i", "i");
    my_map.insert("k", "k");
    my_map.insert("o", "o");
    my_map.insert("n", "n");
    my_map.insert("l", "l");
    my_map.insert("m", "m");
    my_map.print ();
    cout << "_ERASING_NO_ELEM " << my_map.erase ("egnkw") << std::endl;
    cout << "_ERASING_ELEM " << my_map.erase ("i") << std::endl;
    my_map.print ();
    cout << my_map.find ("h") << std::endl;
    mymap <int, std::string> int_string;
    int_string.insert(2, "dsvs");
    int_string.insert(10, "dsvs");
    int_string.print();
    return 0;
}
