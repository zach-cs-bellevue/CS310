#include <iostream>
using namespace std;

int main()
{
	const double SALES_TAX_RATE = 6.0, markupPercent = 2.2 //Northern VA sales tax rate; normal profit margin for grocery stores
	double originalPrice;
	double sellingPrice, salesTax, finalPrice;

	// Input
	cout << "Enter the original price of item: $ ";
	cin >> originalPrice;

	// Calculations
	sellingPrice = originalPrice + (originalPrice * markupPercent / 100);

	salesTax = sellingPrice * SALES_TAX_RATE / 100;

	finalPrice = sellingPrice + salesTax;

	// Output
	cout << "Original price of the item: $ " << originalPrice << endl;
	cout << "Percentage of the marked-up price: " << markupPercent << "%" << endl;
	cout << "Store selling price: $ " << sellingPrice << endl;
	cout << "Sales tax rate: " << SALES_TAX_RATE << "%" << endl;
	cout << "Sales tax: $ " << salesTax << endl;
	cout << "Final price of the item: $ " << finalPrice << endl;

	return 0;
}