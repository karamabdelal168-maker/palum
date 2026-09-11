#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include "the_dedcition.hpp"


void text::add_error(std::string error){
    this -> gone_wrong = true;
    this ->errors.push_back(error);
}

void text::speaker_dedictor(std::string* name){
    if (this -> is_looking_for_name == true){
        this -> speakers.push_back(*name);
        *name = "";
        this -> is_looking_for_name = false;
    }
    else{
        this -> add_error("unexpected error: line found when name was exepcted");
    }
    
}

void text::line_dedictor(std::string* line){
    if (this -> is_looking_for_name == false){
        this -> lines.push_back(*line);
        *line = "";
        this -> is_looking_for_name = true;
    }
    else{
        this -> add_error("unexpected error: name found when line was exepcted");
    }
    
}