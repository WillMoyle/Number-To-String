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
    
    ConverterUnitTest() {
        std::cout << "\nBeginning unit testing suit for Number To String Converter\n";
        std::cout << "\nAuthor: Will Moyle\nLast modified: 6 January 2015\n\n";
        
        // Create list of test values
        unitTest tests;
        
        // Test decimals
        tests[0] = "Zero dollars";
        tests[0.0] = "Zero dollars";
        tests[0.1] = "10/100 dollars";
        tests[0.01] = "01/100 dollars";
        tests[0.001] = "Zero dollars";
        tests[0.009] = "Zero dollars";
        tests[0.10] = "10/100 dollars";
        tests[0.99] = "99/100 dollars";
        tests[0.999] = "99/100 dollars";
        tests[1.00] = "One dollar";
            
        // Test negative numbers
        tests[-0] = "Zero dollars";
        tests[-0.0] = "Zero dollars";
        tests[-0.1] = "Negative 10/100 dollars";
        tests[-0.01] = "Negative 01/100 dollars";
        tests[-0.001] = "Zero dollars";
        tests[-0.009] = "Zero dollars";
        tests[-0.10] = "Negative 10/100 dollars";
        tests[-0.99] = "Negative 99/100 dollars";
        tests[-0.999] = "Negative 99/100 dollars";
        tests[-1.00] = "Negative one dollar";
            
        // Test integers
        tests[9] = "Nine dollars";
        tests[15] = "Fifteen dollars";
        tests[72] = "Seventy-two dollars";
        tests[101] = "One hundred one dollars";
        tests[200] = "Two hundred dollars";
        tests[346] = "Three hundred forty-six dollars";
        tests[5414] = "Five thousand four hundred fourteen dollars";
        tests[53114] = "Fifty-three thousand one hundred fourteen dollars";
        tests[5000] = "Five thousand dollars";
        tests[7000000] = "Seven million dollars";
        tests[5000.01] = "Five thousand and 01/100 dollars";
            
        // Test large numbers
        tests[9999999999999.99] = "Nine trillion nine hundred ninety-nine billion nine hundred ninety-nine million nine hundred ninety-nine thousand nine hundred ninety-nine and 99/100 dollars";
        tests[-9999999999999.99] = "Negative nine trillion nine hundred ninety-nine billion nine hundred ninety-nine million nine hundred ninety-nine thousand nine hundred ninety-nine and 99/100 dollars";
        
        // Output result for each unit test value
        int testNumber = 0;
        int successes = 0;
        for (unitTest::iterator it = tests.begin(); it != tests.end(); it++) {
            testNumber++;
            input = it->first;
            std::cout << "\nTest " << testNumber << ": " << input;
            if (!it->second.compare(convertToOutput())) {
                std::cout << "\n\tSUCCESS";
                successes++;
            }
            else {
                std::cout << "\n\tFAILURE. \n\tExpecting:\n\t" << it->second;
                std::cout << "\n\tReceived:\n\t" << convertToOutput();
            }
            
        }
        std::cout << "\n\nTEST RESULTS: " << successes << "/";
        std::cout << testNumber << std::endl;
        
    }
};

#endif