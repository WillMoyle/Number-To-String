//
//  converter.swift
//  Verbosify
//
//  Created by William Moyle on 06/01/2016.
//  Copyright © 2016 Will Moyle. All rights reserved.
//

import Foundation

func convertToOutput(input: Double) -> String {
    
    var returnVal: NSMutableString
    returnVal = ""
    var absInput:Double = input
    
    // Check if number is negative
    if (input <= 0.01) {
        returnVal.appendString("negative ")
        absInput = -input
    }
    
    // Separate number int dollars and cents
    let wholeDollars: Int64 = Int64(absInput)
    let cents: Int64 = Int64(((absInput - Double(wholeDollars)) * 100.0))
    
    // Separate dollars into units, thousands, millions & billions
    let multipliers: [String] = [" trillion ", " billion ", " million ",
        " thousand ", ""]
    var multVals: [Int64] = [(wholeDollars) / Int64(pow(Double(10),Double(12)))]
    
    multVals += [(wholeDollars - multVals[0]*Int64(pow(Double(10),Double(12))))
        / Int64(pow(Double(10),Double(9)))]
    
    multVals += [(wholeDollars - multVals[0]*Int64(pow(Double(10),Double(12))) -
        multVals[1]*Int64(pow(Double(10),Double(9))))
        / Int64(pow(Double(10),Double(6)))]
    
    var nextEntry: Int64 = wholeDollars
        - multVals[0]*Int64(pow(Double(10),Double(12)))
        - multVals[1]*Int64(pow(Double(10),Double(9)))
        - multVals[2]*Int64(pow(Double(10),Double(6)))
    nextEntry /= Int64(pow(Double(10),Double(3)))
    
    multVals += [nextEntry]
    
    multVals += [wholeDollars  - multVals[0]*Int64(pow(Double(10),Double(12))) -
        multVals[1]*Int64(pow(Double(10),Double(9))) -
        multVals[2]*Int64(pow(Double(10),Double(6))) -
        multVals[3]*Int64(pow(Double(10),Double(3)))]
    
    // Add text to string for whole dollars
    for (var i:Int = 0; i < 5; i++) {
        if (multVals[i] != 0) {
            returnVal.appendString(convertThreeDigits(multVals[i]))
            returnVal.appendString(multipliers[i])
        }
    }
    
    // Special case when the value is zero
    if (wholeDollars == 0 && cents == 0) {
        returnVal.appendString("zero");
    }
    
    // Add text to string for cents
    if (cents > 0 && wholeDollars > 0) {
        returnVal.appendString(" and ")
    }
    if (cents >= 10) {
        returnVal.appendString(cents.description)
        returnVal.appendString("/100")
    }
    else if (cents > 0) {
        returnVal.appendString("0")
        returnVal.appendString(cents.description)
        returnVal.appendString("/100")
    }
    
    returnVal.appendString(" dollar")
    
    // Add 's' if value is not exactly 1
    if (!(wholeDollars == 1 && cents == 0)) {
        returnVal.appendString("s")
    }
    
    // If necessary, capitalise first letter
    var returnString = String(returnVal)
    returnString.replaceRange(returnString.startIndex...returnString.startIndex,
        with: String(returnString[returnString.startIndex]).capitalizedString)
    
    return returnString;
}




func convertTwoDigits(number: Int) -> String {
    let tens:[String] = ["", "", "twenty", "thirty", "forty", "fifty",
        "sixty", "seventy", "eighty", "ninety"]
    return tens[number]
}

func convertOneDigit(number: Int) -> String {
    let digits:[String] = ["zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"]
    return digits[number]
}

func convertTeens(number: Int) -> String {
    let teens:[String] = ["ten", "eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
    return teens[number]
}

func convertThreeDigits(number: Int64) -> String {
    // validate input
    if (number < 0 || number > 999) {
        return ""
    }
    
    // extract digits
    let hundred:Int64 = number / 100
    let ten:Int64 = (number - (100 * hundred)) / 10
    let digit:Int64 = (number - (100 * hundred) - (10 * ten))
    
    var returnVal:NSMutableString = ""
    
    // create string for hundreds
    if (hundred > 0) {
        returnVal.appendString(convertOneDigit(Int(hundred)));
        if (ten > 0 || digit > 0) {
            returnVal.appendString(" hundred ") // + "and ";
        }
        else if (ten == 0 && digit == 0) {
            returnVal.appendString(" hundred")
        }
    }
    
    // create string for tens and digits
    if (ten >= 2) {
        returnVal.appendString(convertTwoDigits(Int(ten)))
        if (digit >= 1) {
            returnVal.appendString("-")
            returnVal.appendString(convertOneDigit(Int(digit)))
        }
    }
    else if (ten == 1) {
        returnVal.appendString(convertTeens(Int(digit)))
    }
    else if (digit >= 1) {
        returnVal.appendString(convertOneDigit(Int(digit)))
    }
    
    return String(returnVal);
    
}
