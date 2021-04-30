#include <iostream>
using namespace std;

int gcd_1(int a, int b)
{
    if (a <= 0 || b <= 0)
        return 0;

    int d;
    d = (a <= b ? a : b);
    while (a % d != 0 || b % d != 0)
    {
        --d;
    }
    return d;
}

int gcd_2(int a, int b)
{
    if (a <= 0 || b <= 0)
        return 0;

    int remainder = a % b;

    while (remainder != 0)
    {
        a = b;
        b = remainder;
        remainder = a % b;
    }
    return b;
}

int main()
{
    cout << gcd_1(256, 625) << endl;
    cout << gcd_1(42, 6) << endl;
    cout << gcd_1(0, 32) << endl;
    cout << gcd_1(10, -6) << endl;

    cout << gcd_2(256, 625) << endl;
    cout << gcd_2(42, 6) << endl;
    cout << gcd_2(0, 32) << endl;
    cout << gcd_2(10, -6) << endl;

    return 0;
}
