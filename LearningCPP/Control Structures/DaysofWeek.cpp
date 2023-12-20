// This program is learning about switches. Insert a number 1 through 7 and it will return the day of the week.

#include <iostream>
using namespace std;

int main()
{
    int day;
    cout << "Enter a number 1 through 7: ";
    cin >> day;

    switch (day)
    {
    case 1:
        cout << "Sunday" << endl;
        break;
    case 2:
        cout << "Monday" << endl;
        break;
    case 3:
        cout << "Tuesday" << endl;
        break;
    case 4:
        cout << "Wednesday" << endl;
        break;
    case 5:
        cout << "Thursday" << endl;
        break;
    case 6:
        cout << "Friday" << endl;
        break;
    case 7:
        cout << "Saturday" << endl;
        break;
    default:
        cout << "Invalid number" << endl;
        break;
    }

    return 0;
}