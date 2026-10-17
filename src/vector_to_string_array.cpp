#include <iostream>
#include <string>
#include <vector>
#include "../include/vector_to_string_array.hpp"

std::string print_string_as_array(std::vector<std::string> x){

    std::string arr = "[";

    for (std::string i : x) {

        arr = arr + "\"" + i + "\"" + ",";

    }

    arr.at(arr.length() - 1) = ']';

    return arr;

}


std::string vector_to_dict (std::vector<std::string> x){
    std::string dict = "{";

    for (std::string s : x){
        dict = dict + "\"" + s + "\":" + s + "," ;
    }

    dict = dict + "}";

    return dict;

}