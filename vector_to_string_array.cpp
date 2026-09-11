#include <iostream>
#include <string>
#include <vector>
#include "vector_to_string_array.hpp"

std::string print_string_as_array(std::vector<std::string> x){

    std::string arr = "[";

    for (std::string i : x) {

        arr = arr + "\"" + i + "\"" + ",";

    }

    arr.at(arr.length() - 1) = ']';

    return arr;

}