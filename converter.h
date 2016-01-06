/* Number to String Converter
 Author: Will Moyle
 Last Modified: 5 January 2015
 
 CONVERTER CLASS HEADER FILE
 
 C++ command line program that converts a decimal value input by the user
 into its string representation
 
 For example:
 2523.04 to "Two thousand five hundred twenty-three and 04/100 dollars" */

#ifndef converter_h
#define converter_h

#include <iostream>
#include <string>
#include <cmath>

class Converter {
    double input;
    std::string* output;
    
    void welcomeMessage();
    void finalMessage();
    double receiveInput();
    std::string* convertToOutput();
    void printOutput();
    bool repeat();
    std::string convertThreeDigits(int number);
    std::string convertTwoDigits(int number);
    std::string convertOneDigit(int number);
    std::string convertTeens(int number);
    
public:
    
    Converter();
    ~Converter();
};

#endif