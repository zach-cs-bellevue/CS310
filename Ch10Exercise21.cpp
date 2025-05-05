/*
M8: Classes and Data Abstractions
CS310-T301: Programming with C++
Bellevue University
4 May, 2025
Dr. Robert Flowers

References:
Malik, D. S. (2018). C++ Programming: From Problem Analysis to Program Design (8th ed.). Cengage Learning.
*/

#include <iostream>
#include <string>
using namespace std;

class bankAccount {
private:
    string account_holder;
    int account_number;
    string account_type;
    double balance;
    double interest_rate;

    // Static member to automatically assign account numbers
    static int account_counter;

public:
    bankAccount() {
        account_holder = "Unknown";
        account_number = ++account_counter;
        account_type = "new";
        balance = 0.0;
        interest_rate = 0.0;
    }

    // Constructor to initialize the bank account
    bankAccount(string name, string type, double balance, double interest) {
        account_holder = name;
        account_type = type;
        this->balance = balance;
        this->interest_rate = interest;
        account_number = ++account_counter;  // Assign account number automatically
    }

    // Accessor functions
    string getAccountHolder() {
        return account_holder;
    }

    int getAccountNumber() {
        return account_number;
    }

    string getAccountType() {
        return account_type;
    }

    double getBalance() {
        return balance;
    }

    double getInterestRate() {
        return interest_rate;
    }

    void setAccountType(string type) {
        while (type != "checking" && type != "savings") {
            cout << "Invalid account type! Please enter 'checking' or 'savings': ";
            cin >> type; // Prompt the user again for a valid input
        }
        account_type = type;
    }

    // Display account details
    void displayAccountDetails() {
        cout << "Account Holder: " << account_holder << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Account Type: " << account_type << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Interest Rate (%): " << interest_rate << endl;
        cout << "---------------------------" << endl;
    }

    // Mutator functions
    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        }
        else {
            cout << "Insufficient balance!" << endl;
        }
    }
};

// Initialize static member
int bankAccount::account_counter = 0;

int main() {
    bankAccount customers[10];  // Array to process up to 10 customers

    // Input details for 10 customers
    for (int i = 0; i < 10; i++) {
        string name, type;
        double balance, interest_rate;

        cout << "Enter details for customer " << i + 1 << endl;
        cout << "Enter account holder's name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter account type (checking/savings): ";
        cin >> type;
        cout << "Enter initial balance: $";
        cin >> balance;
        cout << "Enter interest rate (in decimal form): ";
        cin >> interest_rate;

        // Initialize the bankAccount object
        customers[i] = bankAccount(name, type, balance, interest_rate);

        // Display the account details of the current customer
        customers[i].displayAccountDetails();
    }

    return 0;
}

