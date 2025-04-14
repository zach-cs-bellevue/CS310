// Reference:
// Malik, D. S. (2018). C++ Programming: From Problem Analysis to Program Design (8th ed.). Cengage Learning.

#include <iostream>
#include <iomanip>

using namespace std;

//Function prototypes (p. 361)
double low_income_charge(double rate, int time);
double low_time_charge(double rate, int time);

int main() {
    double rate;
    int time;
    int income;
    double fee;

    // Input
    cout << "Enter the hourly rate: $";
    cin >> rate;
    cout << endl;

    cout << "Enter the time: ";
    cin >> time;
    cout << endl;

    cout << "Enter their income amount: $";
    cin >> income;
    cout << endl;

    // Calculations and function calls
    if (income <= 25000) {
        fee = low_income_charge(rate, time);
    }
    else {
        fee = low_time_charge(rate, time);
    }

    // Output
    cout << fixed << setprecision(2);
    cout << "Fee: $" << fee << endl;

    return 0;
}

// User-defined functions (p. 353-378)
double low_income_charge(double rate, int time) {
    if (time <= 30) {
        return 0.0;
    }
    else {
        return (rate * 0.40) * ((time - 30) / 60.0);
    }
}

double low_time_charge(double rate, int time) {
    if (time <= 20) {
        return 0.0;
    }
    else {
        return (rate * 0.70) * ((time - 20) / 60.0);
    }
}