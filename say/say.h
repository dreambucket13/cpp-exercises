#if !defined(SAY_H)
#define SAY_H

#include <string>
#include <exception>
#include <iostream>
#include <stdexcept>

namespace say {

    std::string in_english(uint64_t input);

    enum numberSegment {
    BILLIONS,
    MILLIONS,
    THOUSANDS,
    HUNDREDS
    };
    
}  // namespace say

#endif // SAY_H