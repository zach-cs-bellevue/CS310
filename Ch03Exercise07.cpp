#include <iostream>
#include <iomanip>
#include <locale>
using namespace std;

int main()
{
	double netBalance, payment, d1, d2, interestRate, averageDailyBalance, interest;

	// Input
	cout << "Enter the net balance: $ ";
	cin >> netBalance;

	cout >> "Enter the payment made: $ ";
	cin >> payment;

	cout << "Enter the number of days in the billing cycle (d1): ";
	cin >> d1;

	cout << "Enter the number of days the payment is made before the billing cycle (d2): ";
	cin >> d2;

	cout << "Enter the interest rate per month (as a decimal): ";
	cin >> interestRate;

	// Calculations
	averageDailyBalance = (netBalance * d1 - payment * d2) / d1;
	interest = averageDailyBalance * interestRate;

	// Output
	cout << fixed << setprecision(2);
	locale loc("");
	cout.imbue(loc);
	cout << "/nThe interest on the unpaid balance is: $ " << interest << endl;

	return 0;
}