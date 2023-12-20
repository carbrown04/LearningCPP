// User imputs a number and the program tells you if it is a prime number or not

#include <iostream>
using namespace std;

int main() {
    int num;
    bool isPrime = true;

    cout << "Enter a positive integer: ";
    cin >> num;

    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
        cout << num << " is a prime number";
    else
        cout << num << " is not a prime number";

    return 0;
}
