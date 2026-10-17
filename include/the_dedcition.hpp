#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>



class text {
    public:
      std::vector<std::string> lines;
      std::vector<std::string> speakers;
      std::vector<std::string> errors;
      std::vector<std::string> uniqe_speakers;
      bool gone_wrong = false ;
      bool is_escaping = false;
 
      bool is_looking_for_name = true;
      void add_error(std::string error);
      void line_dedictor(std::string* line);
      void speaker_dedictor(std::string* name);
    
};