/* Number to String Converter
 Author: Will Moyle
 Last Modified: 6 January 2015
 
 CONVERTER CLASS FUNCTION DEFINITIONS FILE */

#include "converter.h"
#include <iomanip>

////////////////////////////////////////////////////////////////////////////////
// CONVERTING NUMBER TO STRING
////////////////////////////////////////////////////////////////////////////////



// FUNCTION: convertToOutput
// Returns full string representation of double 'input' member variable
std::string Converter::convertToOutput() {
    std::string returnVal = "";
    double absInput = input;
    
    // Check if number is negative
    if (input <= -0.01) {
        returnVal += "negative ";
        absInput = -input;
    }
    
    // Separate number into dollars and cents
    long wholeDollars = absInput;
    int cents = float((absInput - wholeDollars) * 100.0);
    
    // Separate dollars into units, thousands, millions, billions and trillions
    std::string multipliers[] = {" trillion ", " billion ", " million ",
        " thousand ", ""};
    long multVals[] = {(wholeDollars) / pow(10,12),
        (wholeDollars - multVals[0]*pow(10,12)) / pow(10,9),
        (wholeDollars - multVals[0]*pow(10,12) - multVals[1]*pow(10,9)) / pow(10,6),
        (wholeDollars - multVals[0]*pow(10,12) - multVals[1]*pow(10,9) -
        multVals[2]*pow(10,6)) / pow(10,3),
        wholeDollars  - multVals[0]*pow(10,12) - multVals[1]*pow(10,9) -
        multVals[2]*pow(10,6) - multVals[3]*pow(10,3)};
    
    // Add text to string for whole dollars
    for (int i = 0; i < 5; i++)
        if (multVals[i] != 0)
            returnVal += convertThreeDigits(multVals[i]) + multipliers[i];
    
    // Special case when the value is zero
    if (wholeDollars == 0 && cents == 0)
        returnVal += "zero";
    
    // Add text to string for cents
    if (cents > 0 && wholeDollars > 0) {
        if (multVals[4] != 0)
            returnVal += " ";
        returnVal += "and ";
    }
    if (cents >= 10)
        returnVal += std::to_string(cents) + "/100";
    else if (cents > 0)
        returnVal += "0" + std::to_string(cents) + "/100";
    if (!(wholeDollars > 0 && cents == 0 && multVals[4] == 0))
        returnVal += " ";
    returnVal += "dollar";
    
    // Add 's' if value is not exactly 1
    if (!(wholeDollars == 1 && cents == 0)) returnVal += "s";
    
    // If necessary, capitalise first letter
    if (returnVal[0] >= 'a' && returnVal[0] <= 'z')
        returnVal[0] += 'A' - 'a';
    
    return returnVal;
}
// END OF FUNCTION



// FUNCTION: convertThreeDigits
// Returns string representations of integers between 0 and 999
std::string Converter::convertThreeDigits(int number) {
    // validate input
    if (number < 0 || number > 999)
        return NULL;
    
    // extract number of hundreds, tens and single digits
    int hundred = number / 100;
    int ten = (number - (100 * hundred)) / 10;
    int digit = (number - (100 * hundred) - (10 * ten));
    
    std::string returnVal = "";
    
    // create string for hundreds
    if (hundred > 0) {
        returnVal += convertOneDigit(hundred);
        if (ten > 0 || digit > 0)
            returnVal += " hundred "; // + "and ";
        else if (ten == 0 && digit == 0)
            returnVal += " hundred";
    }
    
    // create string for tens and digits
    // CASE 1: Number >= 20
    if (ten >= 2) {
        returnVal += convertTwoDigits(ten);
        if (digit >= 1)
            returnVal += "-" + convertOneDigit(digit);
    }
    // CASE 2: 10 <= Number < 20
    else if (ten == 1)
        returnVal += convertTeens(digit);
    // CASE 3: 0 <= Number < 10
    else if (digit >= 1)
        returnVal += convertOneDigit(digit);
    
    return returnVal;
}
// END OF FUNCTION



// FUNCTIONS: digit conversions
// Takes integers from 0 to 9 returns as string
std::string Converter::convertTeens(int digit) {
    std::string teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    return teens[digit];
}
std::string Converter::convertTwoDigits(int number) {
    std::string tens[10] = {"", "", "twenty", "thirty", "forty", "fifty",
        "sixty", "seventy", "eighty", "ninety"};
    return tens[number];
}
std::string Converter::convertOneDigit(int number) {
    std::string digits[10] = {"zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"};
    return digits[number];
}
// END OF FUNCTIONS



////////////////////////////////////////////////////////////////////////////////
// FLOW OF CONTROL FUNCTIONS
////////////////////////////////////////////////////////////////////////////////



// FUNCTION: run
// Handles the main flow of control for the Converter class, including I/O
void Converter::run() {
    welcomeMessage();
    
    // Loop to allow for multiple conversions
    bool loop = true;
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
// END OF FUNCTION



// FUNCTION: welcomeMessage
// Prints a welcome message to the console
void Converter::welcomeMessage() {
    std::cout << "\nWelcome to the Number To String Converter";
    std::cout << "\nAuthor: Will Moyle\nLast modified: 6 January 2015";
    std::cout << "\nValid numbers are between plus and minus ten trillion";
    std::cout << "\nNumbers are truncated to the second decimal place\n";
}
// END OF FUNCTION



// FUNCTION: receiveInput
// Recieves input as a string and returns it as a double (if valid)
double Converter::receiveInput() {
    std::string inputString;
    std::cout << "\nINPUT:\n";
    std::getline(std::cin, inputString);
    
    bool invalidInput = true;
    double inputValue;
    
    if (stringIsNumber(inputString)) {
        inputValue = std::stod(inputString);
        if (inputValue >= -pow(10, 13) && inputValue <= pow(10, 13))
            invalidInput = false;
    }
    
    while (invalidInput) {
        std::cout << "Invalid input. Please try again: ";
        std::getline(std::cin, inputString);
        
        if (stringIsNumber(inputString)) {
            inputValue = std::stod(inputString);
            if (inputValue >= -pow(10, 13) && inputValue <= pow(10, 13))
                invalidInput = false;
        }
    }
    
    return inputValue;
}
// END OF FUNCTION



// FUNCTION: printOutput
// Prints the output of the conversion to the console
void Converter::printOutput() {
    std::cout << "\nOUTPUT:\n" << output << std::endl;
}
// END OF FUNCTION



// FUNCTION: repeat
// Returns true if user wishes to convert another number
bool Converter::repeat() {
    std::string userInput;
    std::cout << "\nDo you wish to input another number? (Y/N) ";
    std::getline(std::cin, userInput);
    
    while (userInput.compare("Y") && userInput.compare("N")
           && userInput.compare("y") && userInput.compare("n")) {
        std::cout << "\nInvalid input. Please enter 'Y' or 'N': ";
        std::getline(std::cin, userInput);
    }
    
    if (!userInput.compare("N") || !userInput.compare("n"))
        return false;
    return true;
}
// END OF FUNCTION



// FUNCTION: finalMessage
// Prints a final message to the console
void Converter::finalMessage() {
    std::cout << "\nGoodbye\n";
}
// END OF FUNCTION



////////////////////////////////////////////////////////////////////////////////
// AUXILLIARY FUNCTIONS
////////////////////////////////////////////////////////////////////////////////



// FUNCTION: stringIsNumber
// Returns true if the given string represents a valid decimal number
bool Converter::stringIsNumber(std::string word) {
    int len = word.length();
    if (len == 0)
        return false;
    
    bool seenPoint = false;
    int position = 0;
    if (word[0] == '-')
        position++;
    while (position < len) {
        if (word[position] == '.') {
            if (seenPoint)
                return false;
            else
                seenPoint = true;
        }
        else if (word[position] < '0' || word[position] > '9')
            return false;
        position++;
    }
    return true;
}
// END OF FUNCTION



// CONSTRUCTORS & DESTRUCTORS
Converter::Converter() {}
Converter::~Converter() {}

