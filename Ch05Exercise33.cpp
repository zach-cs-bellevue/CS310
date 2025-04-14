// Reference:
// Malik, D. S. (2018). C++ Programming: From Problem Analysis to Program Design (8th ed.). Cengage Learning.

#include <iostream>
#include <string>

using namespace std;

int main() {
	string name;
	int a, b, t;
	int time = 0;
	int dishes = 0;

	// Input
	cout << "Who is cooking? ";
	cin >> name;
	cout << endl;
	
	cout << "How long does it take " << name << " to prepare the first dish: ";
	cin >> a;
	cout << endl;

	cout << "How long will it take to prepare each subsequent dish: ";
	cin >> b;
	cout << endl;

	cout << "How long does " << name << " have to prepare all dishes : ";
	cin >> t;
	cout << endl;

	// Calculations
	// Counter-controlled while loops (p. 277)
	while (time + a + (b * dishes) <= t) {
		time += a + (b * dishes);
		dishes++;
	}

	// Output
	cout << name << " can prepare " << dishes << " dishes in " << t << " minutes." << endl;

	return 0;
}
