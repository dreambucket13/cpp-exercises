#include "say.h"

namespace say {

    std::string in_english(unsigned long long int input){

        if (input == 0){
            return "zero";
        } 

        return "not zero";
    }
    
}  // namespace say
