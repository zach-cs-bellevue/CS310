//Original program: https://github.com/NormC402/CS310/blob/f2a89f838997959b09b1d2f32cd222e0a9a8293a/Cervantes_CS310_M5D_bugged.cpp

#include <iostream>

int square(int value)
{
    int result = value * value;	// declare variable result, add missing semicolon
    return result;
}

bool isEven(int num)
{
    if (num % 2 == 0)	// add missing parentheses for if statement
        return true;
    else
        return false;
}

void displayResult(int number)
{
    std::cout << "The square of " << number << " is " << square(number) << std::endl;	//add missing semicolon
    if (isEven(number))
        std::cout << "The number is even." << std::endl;
    else
        std::cout << "The number is odd." << std::endl;
}

int main()
{
    int userNumber

        std::cout << "Enter a number: ";
    std::cin >> userNumber;	// fix variable name inconsistency

    displayResult(userNumber);	// fix variable name inconsistency

    return 0;
}