#if !defined(SAY_H)
#define SAY_H

#include <string>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace say {

    std::string in_english(uint64_t input);
    std::string trim(std::string rawString);

    enum numberSegment {
    BILLIONS,
    MILLIONS,
    THOUSANDS,
    HUNDREDS
    };
    
}  // namespace say

#endif // SAY_H