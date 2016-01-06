/* Number to String Converter
 Author: Will Moyle
 Last Modified: 6 January 2015
 
 CONVERTER UNIT TEST CLASS HEADER FILE */

#ifndef converterunittest_h
#define converterunittest_h

#include "converter.h"

class ConverterUnitTest : public Converter {
    
public:
    
    ConverterUnitTest() {
        
        // Create list of test values
        double inputs[] = {
            // Test decimals
            0, 0.0, 0.1, 0.01, 0.001, 0.009, 0.10, 0.99, 0.999, 1.00, -0.1, -0.01,
            // Test large numbers
            9999999999999.99, -9999999999999.99};
        
        // Output result for each unit test value
        for (int i = 0; i < 14; i++) {
            input = inputs[i];
            output = convertToOutput();
            std::cout << "\n" << input << " converts to: " << output;
        }
        
    }
};

#endif