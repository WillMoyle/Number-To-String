# Number To String Representation Converter

**Author:** Will Moyle

**Last modified:** 6 January 2015

**Description**

C++ command line program that converts a decimal value input by the user into its string representation in dollars.

For example, *2523.04* to *Two thousand five hundred twenty-three and 04/100 dollars*

Numbers can be in the range of plus/minus 10 trillion (including 2 decimal places), limited by the C++ limit on double values (15 significant figures). Numbers are truncated to the 2nd decimal place.

**File structure**

All functions for this conversion are found within the *Converter* class in the files *converter.h* and *converter.cpp*

**Unit tests**

Additionally, a *ConverterUnitTest* class can be found in *converterunittest.h* which is a child class of *Converter* and tests a number of cases. The variable *performUnitTests* in *main.cpp* should be set to *true* in order to perform unit tests.

**Assumptions & Justification**

- Input: the program will only accept input containing (possibly negative) decimal numbers, without commas. This is in the style given in the above example.
- Range: range has been tested between plus and minus 10 trillion (not inclusive). This is limited by the accuracy of the C++ double values. This is justifiable as it is hugely unlikely that any user would require dollar amounts beyond that limit (approximately the GDP of China). 

**Extensions**

This project presents a number of areas for future expansion:
- Improving the user interface by incorporating the program into a webpage/app
- Extending the valid input range beyond its current limits of plus/minus 10 trillion
- Allow for other currencies
