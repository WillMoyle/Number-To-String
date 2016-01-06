# Number To String Representation Converter

**Author:** Will Moyle
**Last modified:** 6 January 2015

**Description**
C++ command line program that converts a decimal value input by the user into its string representation in dollars.

For example, *2523.04* to *Two thousand five hundred twenty-three and 04/100 dollars*

Numbers can be in the range of plus/minus 10 trillion (including 2 decimal places). Numbers are truncated to the 2nd decimal place.

**File structure**
All functions for this conversion are found within the *Converter* class in the files *converter.h* and *converter.cpp*

**Unit tests**
Additionally, a *ConverterUnitTest* class can be found in *converterunittest.h* which is a child class of *Converter* and tests a number of cases. Sections of *main.cpp* will be required to be commented out to perform unit tests.

**Extensions**
This project presents a number of areas for future expansion:
- Improving the user interface by incorporating the program into a webpage/app
- Extending the valid input range beyond its current limits of plus/minus 10 trillion
- Allow for other currencies
