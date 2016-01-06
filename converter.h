/* Number to String Converter
 Author: Will Moyle
 Last Modified: 6 January 2015
 
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

protected: // protected functions and parameters used by unit test child class
    
    double input;
    std::string output;
    
    // Returns full string representation of double 'input' member variable
    std::string convertToOutput();

private:
    
    // Prints a welcome message to the console
    void welcomeMessage();
    
    // Prints a final message to the console
    void finalMessage();
    
    // Recieves input as a string and returns it as a double (if valid)
    double receiveInput();
    
    // Prints the output of the conversion to the console
    void printOutput();
    
    // Returns true if user wishes to convert another number
    bool repeat();
    
    // Returns string representations of integers between 0 and 999
    std::string convertThreeDigits(int number);
    
    // Takes integers from 0 to 9 returns as string
    std::string convertTwoDigits(int number);
    std::string convertOneDigit(int number);
    std::string convertTeens(int number);
    
    // Returns true if the given string represents a valid decimal number
    bool stringIsNumber(std::string word);
    
public:
    Converter();
    ~Converter();
    
    // Handles the main flow of control for the Converter class, including I/O
    // TO BE CALLED IN MAIN FILE AFTER CONSTRUCTOR
    void run();
    
};

#endif