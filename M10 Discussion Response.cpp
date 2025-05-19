// Original program: https://github.com/JohnMichaelBarron/CS310/blob/c78722f8882bfe0a622d80aba19c8f18426bf2c1/Mod10_Discussion_ErrorCode.cpp

#include <iostream>
using namespace std;

void slidingWindowSum(int* arr, int size, int windowSize) {      // missing the pointer to the array
    if (windowSize > size) {
        cout << "Your window size can't be greater than the number of elements.\n";
        return;
    }

    int* start = arr;
    int* end = arr + windowSize;

    while (end <= arr + size) {
        int sum = 0;
        for (int* ptr = start; ptr < end; ++ptr) {
            sum += *ptr;
        }
        cout << "Window sum: " << sum << endl;
        ++start;
        ++end;
    }
}

int main() {
    int size;
    cout << "How many numbers do you wanna enter? ";
    cin >> size;

    int* data = new int[size];      // missing 'new' to allocate memory for the array

    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        cin >> data[i];
    }

    int windowSize;
    cout << "Enter the sliding window size: ";
    cin >> windowSize;

    cout << "\nSliding window sums:\n";
    slidingWindowSum(data, size, windowSize);

    delete[] data;
    return 0;
}