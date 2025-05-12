// Original program: https://github.com/justyce-bellevue/CS310/blob/c98ddc437781f1ad2a8b2356f0b9dc4cdc37cc9d/M9DisucssionBroke.cpp

#include <iostream>

class Shape {
private:
    int id;
public:
    Shape(int i) : id(i) {}

    void printId() {
        std::cout << "ID: " << id << std::endl;
    }

    // Getter for 'id' so that derived classes can access it
    int getId() const {
        return id;
    }
};

// Child class 1
class Circle : public Shape {
public:
    Circle(int i) : Shape(i) {}

    void show() {
        std::cout << "Circle ID: " << getId() << std::endl;  // Using getter
    }
};

// Child class 2
class Square : public Shape {
public:
    Square(int i) : Shape(i) {}

    void display() {
        printId();
    }
}; // Added missing semicolon here

int main() {
    Circle c(1);
    Square s(2);

    c.show();
    s.display();

    return 0;
}
