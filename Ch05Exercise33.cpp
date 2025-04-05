#include <iostream>
using namespace std;

int main() {
	int a, b, t;
	int time = 0;
	int dishes = 0;

	// Input
	cout << "Enter how many minutes it takes to prepare the first dish: ";
	cin >> a;

	cout << "Enter how many minutes it will take to prepare each subsequent dish: ";
	cin >> b;

	cout << "Enter how many total minutes available to prepare all dishes: ";
	cin >> t;

	// Calculations
	while (time + a + (b * dishes) <= t) {
		time += a + (b * dishes);
		dishes++;
	}

	// Output
	cout << "\nBianca can prepare " << dishes << " dishes." << endl;

	return 0;
}