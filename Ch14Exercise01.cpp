/*
M12 Assignment: Exception Handling
CS310-T301: Programming with C++
Bellevue University
30 May, 2025
Dr. Robert Flowers

References:
Malik, D. S. (2018). C++ Programming: From Problem Analysis to Program Design (8th ed., pp. 992-1033). Cengage Learning.
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;

// Exception class1: negative numbers (pp. 1016)
class negativeNumber {
public:
    negativeNumber() {
        message = "Only positive numbers are not allowed. Try again.";
    }
    negativeNumber(string str) {
        message = str;
    }
    string what() const {
        return message;
    }

private:
    string message;
};

// Exception class2: non-numbers (pp. 1016)
class nonNumber {
public:
    nonNumber() {
        message = "Only numbers allowed. Try again.";
    }
    nonNumber(string str) {
        message = str;
    }
    string what() const {
        return message;
    }

private:
    string message;
};

double validate_number(string prompt);

int main() {
    double FT = 0, IN = 0;
    bool valid_feet = false, valid_inches = false;

    cout << "Enter the length in feet and inches." << endl;

    // Validate input for feet
    do {
        try {
            FT = validate_number("Enter feet: ");
            valid_feet = true;
        }
        catch (negativeNumber& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (nonNumber& e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (!valid_feet);

    // Validate input for inches
    do {
        try {
            IN = validate_number("Enter inches: ");
            valid_inches = true;
        }
        catch (negativeNumber& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (nonNumber& e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (!valid_inches);

    // Convert imperial to metric
    const double CM_PER_FT = 30.48, CM_PER_IN = 2.54;
    double cm = (FT * CM_PER_FT) + (IN * CM_PER_IN);

    cout << "Length (cm): " << cm << endl;

    return 0;
}

// Function to validate user input for positive values (pp. 1021)
double validate_number(string str) {
    double input;
    
    for (;;) {
        cout << str;
        cin >> input;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            throw nonNumber();
        }

        if (input < 0) {
            throw negativeNumber();
        }

        return input;
    }
}