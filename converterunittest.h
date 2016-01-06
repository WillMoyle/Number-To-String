/* Number to String Converter
 Author: Will Moyle
 Last Modified: 6 January 2015
 
 CONVERTER UNIT TEST CLASS HEADER FILE */

#ifndef converterunittest_h
#define converterunittest_h

#include "converter.h"
#include <map>

typedef std::map<double, std::string> unitTest;

class ConverterUnitTest : public Converter {
    
public:
    // Constructor creates and performs unit tests
    ConverterUnitTest();
};

#endif