#include "say.h"

namespace say {

std::string trim(std::string rawString){

    //remove leading spaces
    uint32_t i=0;
    uint32_t leadingSpaces = 0;
    while (i < rawString.size()){

        if (rawString.substr(i,1) == " "){
            leadingSpaces++;
        } 

        if (rawString.substr(i,1) != " "){
            rawString.erase(0,leadingSpaces);
            break;
        } 

        i++;
    }

    //remove trailing spaces
    i = rawString.size() - 1;
    uint32_t trailingSpaces = 0;
    while (i > 0){

        if (rawString.substr(i,1) == " "){
            trailingSpaces++;
        } 

        if (rawString.substr(i,1) != " "){
            rawString.erase(rawString.size() - trailingSpaces, trailingSpaces);
            break;
        } 

        i--;
    }

    //remove double spaces
    i=0; 
    while (i < rawString.size()){
        
        if (rawString.substr(i,2) == "  "){
            rawString.erase(i,1);
        } 

        i++;
    }

    return rawString;

}

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
                    typeString = "";
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
            std::string conditionalHundred = "";

            if (hundreds > 0){
                conditionalHundred = " hundred ";
            }

            if (!isEmpty()){
                output += digitToString(hundreds) + conditionalHundred + lessThan99ToString() + " " + typeString;
            }

            return output;
        }

        private:

        std::string lessThan99ToString(){

            std::string lessThan99 = "";
            std::string dash = "";

            //only do dashes if there are ones
            if (ones > 0){
                dash = "-";
            }

            switch (tens){
                case 9:
                    lessThan99 += "ninety" + dash + digitToString(ones);
                    break;
                case 8:
                    lessThan99 += "eighty" + dash + digitToString(ones);
                    break;                    
                case 7:
                    lessThan99 += "seventy" + dash + digitToString(ones);
                    break;  
                case 6:
                    lessThan99 += "sixty" + dash + digitToString(ones);
                    break;  
                case 5:
                    lessThan99 += "fifty" + dash + digitToString(ones);
                    break;                    
                case 4:
                    lessThan99 += "forty" + dash + digitToString(ones);
                    break;  
                case 3:
                    lessThan99 += "thirty" + dash + digitToString(ones);
                    break;  
                case 2:
                    lessThan99 += "twenty" + dash + digitToString(ones);
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

            return lessThan99;
        }
        std::string teensToString(){
            switch (ones){
                case 9:
                    return "nineteen";
                case 8:
                    return "eighteen";                  
                case 7:
                    return "seventeen";
                case 6:
                    return "sixteen"; 
                case 5:
                    return "fifteen";                 
                case 4:
                    return "fourteen";
                case 3:
                    return "thirteen";
                case 2:
                    return "twelve";
                case 1:
                    return "eleven";
                case 0:
                    return "ten";
                default:
                    return "";
            }           
        }
        std::string digitToString(uint64_t digit){

            switch (digit){
                case 9:
                    return "nine";
                case 8:
                    return "eight";                  
                case 7:
                    return "seven";
                case 6:
                    return "six"; 
                case 5:
                    return "five";                   
                case 4:
                    return "four";
                case 3:
                    return "three"; 
                case 2:
                    return "two";
                case 1:
                    return "one";
                case 0:
                    return ""; 
                default:
                    return "";
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

    #define STANDARD
    #ifdef STANDARD
    std::string output = billions.toString() + " " +
                            millions.toString()+ " " +
                            thousands.toString()+ " " +
                            hundreds.toString();

    output = trim(output);
    #endif

    //#define EXTENSION
    #ifdef EXTENSION

    //insert "and" before the last "lessThan99" string, if hundreds, thousands, etc is not zero

    #endif

    return output;

}
    
}  // namespace say
