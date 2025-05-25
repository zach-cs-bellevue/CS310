// Original program: https://github.com/JohnMichaelBarron/CS310/blob/06edf61320a4ab2f94838e736ae5549bf25a6602/Mod11_Discussion_ErrorCode.cpp

#include <iostream>
#include <string>
using namespace std;

template <class Type>
Type bigBoi(Type weight1, Type weight2) {
    return (weight1 > weight2) ? weight1 : weight2;
}

int main() {
    cout << " Welcome to the Pet Weight Checker \n";

    string name1, name2;
    float weight1, weight2;

    cout << "Enter the name of your first pet: ";
    getline(cin, name1);

    cout << "Enter " << name1 << "'s weight (in pounds): ";
    cin >> weight1;
    cin.ignore();   // changed to ignore

    cout << "Enter the name of your second pet: ";
    getline(cin, name2);

    cout << "Enter " << name2 << "'s weight (in pounds): ";
    cin >> weight2;

    cout << "\n Comparing " << name1 << " and " << name2 << "...\n";

    float heavier = bigBoi(weight1, weight2);


    if (heavier == weight1 && weight1 != weight2)   // changed to logical && operator
        cout << name1 << " is heavier at " << weight1 << " lbs.\n";
    else if (heavier == weight2 && weight1 != weight2)  // changed to logical && operator
        cout << name2 << " is heavier at " << weight2 << " lbs.\n";
    else
        cout << "Wow! Both " << name1 << " and " << name2 << " weigh the same: " << weight1 << " lbs.\n";

    return 0;
}