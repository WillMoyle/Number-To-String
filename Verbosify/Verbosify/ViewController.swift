//
//  ViewController.swift
//  Verbosify
//
//  Created by William Moyle on 06/01/2016.
//  Copyright © 2016 Will Moyle. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet var inputTextField: UITextField!
    @IBOutlet var convertButton: UIButton!
    @IBOutlet var outputLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }

    @IBAction func convert(sender: UIButton) {
        performConversion()
    }
    
    @IBAction func finishedEditing(sender: AnyObject) {
        performConversion()
    }
    
    func performConversion() {
        inputTextField.endEditing(true)
        let inputString: String = inputTextField.text!
        if Double(inputString) != nil {
            let input: Double = Double(inputString)!
            if (input > 10000000000000 || input > 10000000000000) {
                outputLabel.text = "Input must be between plus and minus ten billion"
            }
            else {
                let output: String = convertToOutput(input)
                outputLabel.text = output;
            }
        }
        else {
            outputLabel.text = "Input must be a valid number"
        }
    }
}

