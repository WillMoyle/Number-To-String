/* Number to String Converter
 Author: Will Moyle
 Last Modified: 5 January 2015
 
 CONVERTER UNIT TEST CLASS HEADER FILE */

#ifndef converterunittest_h
#define converterunittest_h

#include "converter.h"

class ConverterUnitTest : public Converter {
    
public:
    
    ConverterUnitTest(int val) {
        float inputs[] = {0, 0.1, 0.03, 0.001, 0.123, 0.129, 5, 10, 19,
            31, 531, 801, 900, 100, 453, 546.3, 35, -0, -0.1, -1.2};
        
        for (int i = 0; i < 20; i++) {
            input = inputs[i];
            output = convertToOutput();
            std::cout << "\n" << input << " converts to: " << output;
        }
        
    }
};

#endif