/*
M9: Inheritance and Composition
CS310-T301: Programming with C++
Bellevue University
11 May, 2025
Dr. Robert Flowers

References:
Malik, D. S. (2018). C++ Programming: From Problem Analysis to Program Design (8th ed.). Cengage Learning.
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// Base class: bankAccount
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
    // Default constructor
    bankAccount() {
        account_holder = "Unknown";
        account_number = ++account_counter;
        account_type = "new";
        balance = 0.0;
        interest_rate = 0.0;
    }

    // Constructor with parameters
    bankAccount(string name, string type, double balance, double interest) {
        account_holder = name;
        account_type = type;
        this->balance = balance;
        this->interest_rate = interest;
        account_number = ++account_counter;  // Auto-increment account number
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

    double getBalance() const {
        return balance;
    }

    double getInterestRate() const {
        return interest_rate;
    }

    void setAccountType(string type) {
        // Use strcmp() to compare C-style strings for validation
        while (strcmp(type.c_str(), "checking") != 0 && strcmp(type.c_str(), "savings") != 0) {
            cout << "Invalid account type! Please enter 'checking' or 'savings': ";
            cin >> type;
        }
        account_type = type;
    }

    // Display account details
    virtual void displayAccountDetails() {
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

    virtual void withdraw(double amount) {
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


// Derived class: checkingAccount
class checkingAccount : public bankAccount {
private:
    double minimum_balance;
    double service_charge;

public:
    // Constructor with parameters
    checkingAccount(string name, string type, double balance, double interest, double min_balance, double service_charge)
        : bankAccount(name, type, balance, interest) {
        this->minimum_balance = min_balance;
        this->service_charge = service_charge;
    }

    // Accessor functions
    double getMinimumBalance() const {
        return minimum_balance;
    }

    double getServiceCharges() const {
        return service_charge;
    }

    // Mutator functions
    void setMinimumBalance(double min_balance) {
        minimum_balance = min_balance;
    }

    void setServiceCharges(double charges) {
        service_charge = charges;
    }

    // Override withdraw function to handle minimum balance and service charges
    void withdraw(double amount) override {
        if (amount <= getBalance()) {
            if (getBalance() - amount < minimum_balance) {
                cout << "Non-sufficient funds, service charge applied!" << endl;
                amount += service_charge;
            }
            bankAccount::withdraw(amount);
        }
        else {
            cout << "Insufficient balance!" << endl;
        }
    }

    // Display account details for checkingAccount
    void displayAccountDetails() override {
        bankAccount::displayAccountDetails();
        cout << "Minimum Balance: $" << minimum_balance << endl;
        cout << "Service Charges: $" << service_charge << endl;
    }
};

// Derived class: savingsAccount
class savingsAccount : public bankAccount {
public:
    // Constructor
    savingsAccount(string name, string type, double balance, double interest)
        : bankAccount(name, type, balance, interest) {
    }

    // Mutator functions
    void applyInterest() {
        double interest = getBalance() * getInterestRate();
        deposit(interest);
    }

    void withdraw(double amount) override {
        if (amount <= getBalance()) {
            bankAccount::withdraw(amount);
        }
        else {
            cout << "Insufficient balance!" << endl;
        }
    }

    // Display account details for savingsAccount
    void displayAccountDetails() override {
        bankAccount::displayAccountDetails();
    }
};

int main() {
    // Create an array of 3 bank accounts
    bankAccount* accounts[3];

    // Simulate new bank accounts
    accounts[0] = new checkingAccount("Zooey Deutsch", "checking", 1500.0, 0.02, 500.0, 25.0);
    accounts[1] = new savingsAccount("Sofia Vulpo", "savings", 2500.0, 0.03);
    accounts[2] = new checkingAccount("Faye Tina", "checking", 2000.0, 0.03, 750.0, 25.0);

    // Display account details for all customers
    for (int i = 0; i < 3; i++) {
        cout << "\nCustomer " << i + 1 << " Account Info:" << endl;
        accounts[i]->displayAccountDetails();
    }

    // Clean up memory
    for (int i = 0; i < 3; i++) {
        delete accounts[i];
    }

    return 0;
}
