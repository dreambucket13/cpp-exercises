#include <string>
#include <iostream>

namespace log_line {

    static const std::string extract_message(const std::string& input){

        uint32_t message_delimiter_index = 0;

        for (uint32_t i = 0; i < input.length(); i++){

            if (input.at(i) == ':'){
                message_delimiter_index = i + 2;
                break;
            }
        }

        std::string output = input.substr(message_delimiter_index, input.length() - message_delimiter_index);
        return output;
    }


    static const std::string extract_level(const std::string& input){

        uint32_t log_level_start;
        uint32_t log_level_end;

        for (uint32_t i = 0; i < input.length(); i++){

            if (input.at(i) == '['){
                log_level_start = i + 1;
            }

            if (input.at(i) == ']'){
                log_level_end = i;
            }

        }

        std::string output = input.substr(log_level_start, log_level_end - log_level_start );
        return output;
    }

    const std::string message(const std::string& input){
        return extract_message(input);
    }

    const std::string log_level(const std::string& input){
        return extract_level(input);
    }

    const std::string reformat(const std::string& input){
        return extract_message(input) + " (" + extract_level(input) + ")";
    }

} // namespace log_line
