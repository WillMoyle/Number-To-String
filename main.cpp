/* Number to String Converter
Author: Will Moyle
Last Modified: 6 January 2015
 
MAIN FILE

C++ command line program that converts a decimal value input by the user 
into its string representation

For example: 
2523.04 to "Two thousand five hundred twenty-three and 04/100 dollars" */



#include "converterunittest.h"

int main() {
    
    // Set to true if the program should perform unit tests
    bool performUnitTests = true	;
    
    if (!performUnitTests) {
        // Create an instance of the Converter class and run conversion
        Converter converter;
        converter.run();
    }
    else
        // Perform unit tests, if required
        ConverterUnitTest converterUnitTest;
    
    return 0;
}