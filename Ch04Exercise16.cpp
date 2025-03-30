#include <iostream>
#include <iomanip>
using namespace std;

// Named constants
const double MANUSCRIPT_PAYMENT = 5000.00;      // First option  : fixed amount
const double PUBLISHING_PAYMENT = 20000.00;     // First option  : fixed payment
const double FLAT_ROYALTY_RATE = 0.125;         // Second option : 12.5% royalty
const double LOW_SALES_ROYALTY_RATE = 0.10;     // Third option  : 10% royalty (first 4,000 copies)
const double HIGH_SALES_ROYALTY_RATE = 0.14;    // Third option  : 14% royalty (4,000+ copies)
const int    HIGH_SALES_THRESHOLD = 4000;       // Third option  : Threshold for second tier royalties

int main() {
    double netPrice, firstOption, secondOption, thirdOption;
    int copiesSold;

    // Input
    cout << "Enter the net price of each copy of the novel: $";
    cin >> netPrice;

    cout << "Enter the expected number of copies to be sold: ";
    cin >> copiesSold;

    // Calculations : First Option
    firstOption = MANUSCRIPT_PAYMENT + PUBLISHING_PAYMENT;

    // Calculations : Second Option
    secondOption = netPrice * copiesSold * FLAT_ROYALTY_RATE;

    // Calculations : Third Option
    if (copiesSold <= HIGH_SALES_THRESHOLD) {
        thirdOption = netPrice * copiesSold * LOW_SALES_ROYALTY_RATE;
    }
    else {
        thirdOption = netPrice * (HIGH_SALES_THRESHOLD * LOW_SALES_ROYALTY_RATE +
            (copiesSold - HIGH_SALES_THRESHOLD) * HIGH_SALES_ROYALTY_RATE);
    }

    // Output : Compensation
    cout << fixed << showpoint << setprecision(2);

    cout << "\nRoyalties under First Option (fixed payments): $" << firstOption << endl;
    cout << "Royalties under Second Option (flat royalty): $" << secondOption << endl;
    cout << "Royalties under Third Option (tiered royalties): $" << thirdOption << endl;

    // Calculations : Recommendation
    int bestOption;

    if (firstOption >= secondOption && firstOption >= thirdOption) {
        bestOption = 1;
    }
    else if (secondOption >= firstOption && secondOption >= thirdOption) {
        bestOption = 2;
    }
    else {
        bestOption = 3;
    }

    // Output : Recommendation
    switch (bestOption) {
    case 1:
        cout << "\nThe best option for the author is the First Option (fixed payments)." << endl;
        break;
    case 2:
        cout << "\nThe best option for the author is the Second Option (flat royalty)." << endl;
        break;
    case 3:
        cout << "\nThe best option for the author is the Third Option (tiered royalties)." << endl;
        break;
    default:
        cout << "\nError: Invalid option." << endl;
        break;
    }

    return 0;
}