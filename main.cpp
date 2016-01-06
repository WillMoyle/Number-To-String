/* Number to String Converter
Author: Will Moyle
Last Modified: 5 January 2015
 
MAIN FILE

C++ command line program that converts a decimal value input by the user 
into its string representation

For example: 
2523.04 to "Two thousand five hundred twenty-three and 04/100 dollars" */

#include "converter.h"

//#include "converterunittest.h"

int main() {
    
    // Create an instance of the Converter class, automatically runs conversions
    Converter converter;
    converter.run();
    
    
    //ConverterUnitTest converterUnitTest(0);
    
    return 0;
}