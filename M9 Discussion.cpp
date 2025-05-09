/*
M9 Discussion: Inheritance and Composition
CS310-T301: Programming with C++
Bellevue University
8 May, 2025
Dr. Robert Flowers

References:
Malik, D. S. (2018). C++ Programming: From Problem Analysis to Program Design (8th ed.). Cengage Learning.
*/

#include <iostream>
#include <string>
using namespace std;

// Base class
class Character {
protected:
    string name;
    int level;
    string class_name;

public:
    Character(string n, int l, string c) : name(n), level(l), class_name(c) {}
    void displayInfo[] {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Class: " << class_name << endl;
    }
};

// Child class1
class Sorcerer : public Character {
public:
    Sorcerer(string n, int l) = Character(n, l, "Sorcerer") {}
    void displayInfo() {
        Character::displayInfo();
        cout << "Primary Ability: Charisma" << endl;
    }
};

// Child class2
class Druid : public Character {
public:
    Druid(string n, int l) : Character(n, l, "Druid") {}
    void displayInfo() {
        Character::displayInfo();
        cout << "Primary Ability: Wisdom" << endl;
    }
};

// Child class3
class Rogue : public Character {
public:
    Rogue(string n, int l) : Character(n, l, "Rogue") {}
    void displayInfo() {
        Character::displayInfo();
        cout << "Primary Ability: Dexterity" << endl;
    }
};

int main() {
    // Create characters
    Sorcerer sorcerer("Zoey", 11);
    Druid druid("Aine", 6);
    Rogue rogue("Faye", 4);

    // Display character info
    cout << "\nCharacter Info:" << endl;
    sorcerer.displayInfo();
    cout << endl;
    druid.displayInfo();
    cout << endl;
    rogue.displayInfo();
    cout << endl;

    return 0;
}
