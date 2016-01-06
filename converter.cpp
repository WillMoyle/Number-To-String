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
    float inputValue;
    std::cout << "\n\nINPUT:\nPlease enter a valid number: ";
    std::cin >> inputValue;
    return inputValue;
}

std::string Converter::convertToOutput() {
    std::string returnVal = "";
    
    if (input < 0) {
        returnVal += "Negative ";
        input = -input;
    }
    
    
    int wholeDollars = trunc(input);
    int cents = float((input - wholeDollars) * 100.0);
    
    returnVal += convertThreeDigits(wholeDollars);
    
    if (wholeDollars != 0 && cents != 0)
        returnVal += "and ";
    else if (wholeDollars == 0 && cents == 0)
        returnVal += "Zero ";
    
    if (cents >= 10)
        returnVal += std::to_string(cents) + "/100 ";
    else if (cents > 0)
        returnVal += "0" + std::to_string(cents) + "/100 ";
    
    returnVal += "dollars";
    
    return returnVal;
}

std::string Converter::convertThreeDigits(int number) {
    if (number < 0 || number > 999)
        return NULL;
    
    int hundred = number / 100;
    int ten = (number - (100 * hundred)) / 10;
    int digit = (number - (100 * hundred) - (10 * ten));
    
    std::string returnVal = "";
    
    if (hundred > 0) {
        returnVal += convertOneDigit(hundred);
        if (ten > 0 || digit > 0)
            returnVal += " hundred and ";
        else if (ten == 0 && digit == 0)
            returnVal += " hundred ";
    }
    
    if (ten >= 2) {
        returnVal += convertTwoDigits(ten);
        if (digit >= 1)
            returnVal += "-" + convertOneDigit(digit) + " ";
    }
    else if (ten == 1)
        returnVal += convertTeens(digit) + " ";
    else if (digit >= 1)
        returnVal += convertOneDigit(digit) + " ";
    
    return returnVal;
}

std::string Converter::convertTeens(int digit) {
    std::string teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "ninteen"};
    
    std::string returnVal = teens[digit];
    
    return returnVal;
}

std::string Converter::convertTwoDigits(int number) {
    std::string tens[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty",
        "seventy", "eighty", "ninty"};
    
    std::string returnVal = tens[number];
    
    return returnVal;
}

std::string Converter::convertOneDigit(int number) {
    std::string digits[10] = {"zero", "one", "two", "three", "four", "five", "six",
        "seven", "eight", "nine"};
    
    std::string returnVal = digits[number];
    
    return returnVal;
}

void Converter::printOutput() {
    std::cout << "\nOutput: " << output << std::endl;
}

bool Converter::repeat() {
    return false;
}


Converter::Converter() {
    // Print welcome message
    welcomeMessage();
}

Converter::~Converter() {
}

void Converter::run() {
    bool loop = true;
    
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