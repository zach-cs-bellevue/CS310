/*
M10 Assignment: Pointers, Classes, Virtual Functions, Abstract Classes, and Lists
CS310-T301: Programming with C++
Bellevue University
18 May, 2025
Dr. Robert Flowers

References:
Malik, D. S. (2018). C++ Programming: From Problem Analysis to Program Design (8th ed.). Cengage Learning.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

// Define structure to store candidate details
struct Candidate {
    char name[100];
    int votes;
};

bool validateAlpha(const char* name);
int validatePositiveInteger(const char* prompt);
void candidateDetails(Candidate* candidates, int numCandidates);
void displayResults(Candidate* candidates, int numCandidates, int totalVotes);
string calculateWinner(Candidate* candidates, int numCandidates);

int main() {
    int numCandidates = validatePositiveInteger("Enter the number of candidates: ");

    // Dynamically allocate memory for the candidates array
    Candidate* candidates = new Candidate[numCandidates];

    candidateDetails(candidates, numCandidates);

    int totalVotes = 0;
    for (int i = 0; i < numCandidates; i++) {
        totalVotes += candidates[i].votes;
    }

    displayResults(candidates, numCandidates, totalVotes);
    string winner = calculateWinner(candidates, numCandidates);
    cout << "\nThe winner is " << winner << "!" << endl;

    // Deallocate memory
    delete[] candidates;

    return 0;
}

bool validateAlpha(const char* name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i])) {
            return false;
        }
    }
    return true;
}

int validatePositiveInteger(const char* prompt) {
    int input;

    while (true) {
        cout << prompt;
        cin >> input;

        if (cin.fail() || input <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Only enter positive whole numbers.\n";
        }
        else {
            break;
        }
    }
    return input;
}

// Function to input candidate details
void candidateDetails(Candidate* candidates, int numCandidates) {
    int i = 0;

    while (i < numCandidates) {
        cout << "Candidate's last name: ";
        cin >> candidates[i].name;
        while (!validateAlpha(candidates[i].name)) {
            cout << "Only enter letters for the name: ";
            cin >> candidates[i].name;
        }
        candidates[i].votes = validatePositiveInteger("Number of votes received: ");
        cout << endl;
        i++;
    }
}

// Function to calculate and display the vote results
void displayResults(Candidate* candidates, int numCandidates, int totalVotes) {
    cout << "\nCandidate\t\tVotes Received\t\t% of Total Votes\n";
    double percentage;

    for (int i = 0; i < numCandidates; i++) {
        percentage = (static_cast<double>(candidates[i].votes) / totalVotes) * 100;

        cout << candidates[i].name << "\t\t\t"
            << candidates[i].votes << "\t\t\t"
            << fixed << setprecision(2) << percentage << endl;
    }
}

// Function to calculate and display the winner
string calculateWinner(Candidate* candidates, int numCandidates) {
    string winner = candidates[0].name;
    int highestVotes = candidates[0].votes;

    for (int i = 1; i < numCandidates; i++) {
        if (candidates[i].votes > highestVotes) {
            highestVotes = candidates[i].votes;
            winner = candidates[i].name;
        }
    }
    return winner;
}