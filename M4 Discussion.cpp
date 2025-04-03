#include <iostream>
#include <string>
using namespace std;

int main() {
    string dayOfWeek;
    string daysOfWeek[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    int daysLeft == 0;

    // Input
    cout << "Enter the day of the week (i.e Monday, Tuesday, etc.): ";
    cin >> dayOfWeek;

    // Output1
    if (dayOfWeek = "Sunday") {
        cout << "Weekly assignments are due today, better get to it!" << endl;
    }
    // Repetition control
    else {
        for (int i = 0: i < 6; i++) {
            if (dayOfWeek == daysOfWeek[i]) {
                daysLeft = 7 - (i + 1);
                break;
            }
        }
        // Output2
        cout << daysLeft << " day(s) left until Sunday, you still have time to complete your weekly assignments!"
    }

    return 0;
}