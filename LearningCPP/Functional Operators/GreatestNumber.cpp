// This program is to find the the largest number in an array of 3 numbers


#include <iostream>
using namespace std;

float findLargest(float a, float b, float c)
{
    if (a > b && a > c)
    {
        return a;
    }
    else if (b > a && b > c)
    {
        return b;
    }
    else
    {
        return c;
    }
}

int main()
{
    float a, b, c;
    cout << "Enter 3 numbers (example: 1 2 3): ";
    cin >> a >> b >> c;
    cout << "The largest number is: " << findLargest(a, b, c);
    return 0;
}



