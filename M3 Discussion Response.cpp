// Original program: https://github.com/Randyiscoding/bellevuecs310spring2025/blob/cbeea90f624196795d548a9815cdaf1b3a35dd50/Module%203/Mod3Discussion1.cpp
// The original program had the following errors:
// 1. Incorrect syntax for the if...else statement;
// 2. Missing parentheses around switch statement; and
// 3. Missing break statement after second case.

#include <iostream>

using namespace std;

int main() {
    int number;

    // Prompt user for input
    cout << "Enter a number: ";
    cin >> number;


    if (number > 10)    // Replaced curly braces with parentheses
    cout << "The number is greater than 10." << endl;
    else
        cout << "The number is 10 or less." << endl;

    // Selection control statement using switch
    switch (number) {   // Added parentheses around number
    case 5:
        cout << "You entered five!" << endl;
        break;
    case 10:
        cout << "You entered ten!" << endl;
        break;  // Added break statement
    default:
        cout << "You entered something else." << endl;
    }

}