/*
M11 Assignment: Overloading and Templates
CS310-T301: Programming with C++
Bellevue University
25 May, 2025
Dr. Robert Flowers

References:
Malik, D. S. (2018). C++ Programming: From Problem Analysis to Program Design (8th ed.). Cengage Learning.
*/

#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

int main() {
    // Initialize random number generator and distribution (p. 971)
    random_device rdevice{};
    default_random_engine num{ rdevice() };
    uniform_real_distribution<double> rNum(10, 100);

    int i = 1;

    // Generate 25 real numbers between 10 and 100
    do {
        cout << i << ": " << fixed << setprecision(2) << rNum(num) << endl;
        i++;
    } while (i <= 25);

    return 0;
}