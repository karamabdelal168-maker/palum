#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include "the_dedcition.hpp"
#include "vector_to_string_array.hpp"

void transpile(std::string the_dialouge){
    text speach;
    std::string dialouge;
    for (char c: the_dialouge){
        if (!speach.is_escaping){
            if (c == '\\'){
                speach.line_dedictor(&dialouge);
            }
            else if (c == ':'){
               speach.speaker_dedictor(&dialouge);
            }
            else if (c == '@'){
                speach.is_escaping= true;
            }
            else if (c == '\t' || c == '\n'){
                continue;
            }
            else{
                dialouge.push_back(c);
            }
        }
        else{
            if (c == '\\'){
                dialouge.push_back(c);
            }
            else if (c == ':'){
                dialouge.push_back(c);
            }
            else if (c == '@'){
                dialouge.push_back(c);
            }
            else if (c == 't'){
                dialouge.push_back('\t');
            }
            else if (c == 'n'){
                dialouge.push_back('\n');
            }
            else{
                speach.add_error("unexpected error: non existent escaped character");
            }
            speach.is_escaping = false;
        }

    }
    if (speach.gone_wrong){
        for (std::string error: speach.errors){
            std::cout << error << std::endl;
        }
    }
    else{
        std::cout << print_string_as_array(speach.lines) << std::endl;
        std::cout << print_string_as_array(speach.speakers) << std::endl;
    }
}


int main(){
    transpile("sekmek:my fav @@ goon \\karam:pp\\");
    return 0;
}