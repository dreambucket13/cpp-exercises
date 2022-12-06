#include "say.h"

namespace say {

std::string in_english(uint64_t input){

    /*define internal class for numbers...each segment can have hundreds, tens, or ones
    of itself.
    */

    class tNumberStructure{
    public:

        uint64_t hundreds; 
        uint64_t tens; 
        uint64_t ones;  
        numberSegment type;
        std::string typeString;

        tNumberStructure(numberSegment inputType){
            hundreds = 0; 
            tens = 0; 
            ones = 0;     
            type = inputType; 
            typeString = "";            
        }

        bool isEmpty(){
            if (hundreds != 0 || tens !=0 || ones !=0){
                return false;
            } else {
                return true;
            }
        }

        void generate(uint64_t input){

            uint64_t maskedInput;

            switch (type) {
                case BILLIONS:
                    maskedInput = (input / 1000000000) % 1000;
                    typeString = "billion";
                    break;
                case MILLIONS:
                    maskedInput = (input / 1000000) % 1000;
                    typeString = "million";
                    break;
                case THOUSANDS:
                    maskedInput = (input / 1000) % 1000;
                    typeString = "thousand";
                    break;
                case HUNDREDS:
                    maskedInput = input % 1000;
                    typeString = "hundred";
                    break;
                default:
                    maskedInput = input;
                    break;
            }

            ones = maskedInput % 10;
            maskedInput = maskedInput / 10; //shift digit
            tens = maskedInput % 10;
            maskedInput = maskedInput / 10; //shift digit
            hundreds = maskedInput; // no need to mod 10, last digit

        }

        std::string toString(){

            std::string output = "";

            if (type == HUNDREDS && hundreds == 0){
                typeString = "";
            }

            if (!isEmpty()){
                output += digitToString(hundreds) + " " + lessThan99ToString() + " " + typeString;
            }

            return output;
        }

        private:

        std::string lessThan99ToString(){

            std::string lessThan99 = "";
            std::string dash = "";

            switch (tens){
                case 9:
                    lessThan99 += "ninety";
                    break;
                case 8:
                    lessThan99 += "eighty";
                    break;                    
                case 7:
                    lessThan99 += "seventy";
                    break;  
                case 6:
                    lessThan99 += "sixty";
                    break;  
                case 5:
                    lessThan99 += "fifty";
                    break;                    
                case 4:
                    lessThan99 += "forty";
                    break;  
                case 3:
                    lessThan99 += "thirty";
                    break;  
                case 2:
                    lessThan99 += "twenty";
                    break;  
                case 1:
                    lessThan99 += teensToString();
                    break;  
                case 0:
                    lessThan99 += digitToString(ones);
                    break;  
                default:
                    break;
            }           

            if (ones > 0){
                dash = "-";
            }

            return lessThan99 + dash + digitToString(ones);
        }
        std::string teensToString(){
            switch (ones){
                case 9:
                    return "nineteen";
                    break;
                case 8:
                    return "eighteen";
                    break;                    
                case 7:
                    return "seventeen";
                    break;  
                case 6:
                    return "sixteen";
                    break;  
                case 5:
                    return "fifteen";
                    break;                    
                case 4:
                    return "fourteen";
                    break;  
                case 3:
                    return "thirteen";
                    break;  
                case 2:
                    return "twelve";
                    break;  
                case 1:
                    return "eleven";
                    break;  
                case 0:
                    return "ten";
                    break;  
                default:
                    return "";
                    break;
            }           
        }
        std::string digitToString(uint64_t digit){

            switch (digit){
                case 9:
                    return "nine";
                    break;
                case 8:
                    return "eight";
                    break;                    
                case 7:
                    return "seven";
                    break;  
                case 6:
                    return "six";
                    break;  
                case 5:
                    return "five";
                    break;                    
                case 4:
                    return "four";
                    break;  
                case 3:
                    return "three";
                    break;  
                case 2:
                    return "two";
                    break;  
                case 1:
                    return "one";
                    break;  
                case 0:
                    return ""; 
                    break;
                default:
                    return "";
                    break;
            }

        }

    };  //class tNumberStructure

    if ((int64_t) input < 0 ){
        throw std::domain_error("Input cannot be negative.");
    }

    if (input >= (uint64_t) (1000ULL * 1000ULL * 1000ULL * 1000ULL)){
        throw std::domain_error("Input cannot be or exceed 1 trillion.");
    }

    //special case, no other test case includes zero.
    //very simple check to immediately return.
    if (input == 0){
        return "zero";
    }

    tNumberStructure billions(BILLIONS);
    tNumberStructure millions(MILLIONS);        
    tNumberStructure thousands(THOUSANDS);    
    tNumberStructure hundreds(HUNDREDS);  

    hundreds.generate(input);
    thousands.generate(input);
    millions.generate(input);
    billions.generate(input);

    std::string output = billions.toString() + " " +
                            millions.toString()+ " " +
                            thousands.toString()+ " " +
                            hundreds.toString();
    
    return output;

}
    
}  // namespace say
