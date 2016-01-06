/* Number to String Converter
 Author: Will Moyle
 Last Modified: 5 January 2015
 
 CONVERTER CLASS FUNCTION DEFINITIONS FILE */

#include "converter.h"

void Converter::welcomeMessage() {
    
    std::cout << "\nWelcome to the Number To String Converter";
    std::cout << "\nAuthor: Will Moyle\nLast modified: 6 January 2015";
}

void Converter::finalMessage() {
    std::cout << "\nGoodbye\n";
}


double Converter::receiveInput() {
    return 2523.04;
}

std::string* Converter::convertToOutput() {
    
    std::string* returnVal = new std::string;
    
    *returnVal = "Hello world";
    
    return returnVal;
}

void Converter::printOutput() {
    std::cout << "\nOutput: " << *output << std::endl;
}

bool Converter::repeat() {
    return false;
}


Converter::Converter() {
    bool loop = true;
    
    // Print welcome message
    welcomeMessage();
    
    // Loop to allow for multiple conversions
    while (loop) {
        // Receive user input
        input = receiveInput();
        
        // Convert number to string
        output = convertToOutput();
        
        // Display the output
        printOutput();
        
        loop = repeat();
    }
    
    finalMessage();
}

Converter::~Converter() {
    delete output;
}