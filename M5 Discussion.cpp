#include <iostream>
using namespace std;

// Function to calculate how much this sucks (it always sucks 100%)
int how_much_suck[int num] {
    return num + (100 - num)
}

int main() {
    int sucks;

    // Input
    cout << "How much does this suck? Enter a number from 1 to 100: ";
    cin >> sucks;
    cout << endl;

    // Output
    cout << "Yeah! This sucks " << how_much_suck(sucks) << "%." << endl;

    return 0;
}