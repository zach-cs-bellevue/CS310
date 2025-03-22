// Original program: https://github.com/DevZWhite/CS310/blob/main/Error_Exercise.cpp
// The original program had the following two errors:
// 1. Did not declare the variable sum before it was called; and
// 2. Was missing a semicolon after the second cout statement.
// To fix the errors, I declared sum and added the missing semicolon

#include <iostream>
using namespace std;

int main() {
    int num1, num2, sum; // Declare sum

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: "; // Add missing semicolon
    cin >> num2;

    sum = num1 + num2;

    cout << "The sum is: " << sum << endl;

    return 0;
}