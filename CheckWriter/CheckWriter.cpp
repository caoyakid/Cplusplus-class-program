#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

/* prototype declaration*/
void display_money(double money);
void digit_to_word(int digit);
void tens_to_word(int tens);
void eleven_to_nighteen(int tens, int digit);
void display(string data, string name, double money);

int main()
{
    string date, name;
    double money;
    cout << "Enter data(ex: MM/DD/YEAR): ";
    getline(cin, date);
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter money: $";
    while ((cin >> money) && (money < 0 || money > 10000))
    {
        cout << "Invalid Input " << endl;
        cout << "Enter money: $";
    }
    display(date, name, money);
    return 0;
}

void display_money(double money)
{
    int dollars = static_cast<int>(money);
    int cents = (money - floor(money)) * 100 + 1;
    int thousands, hundreds, tens, digits;
    thousands = dollars / 1000;
    dollars = dollars % 1000;
    hundreds = dollars / 100;
    dollars = dollars % 100;
    tens = dollars / 10;
    digits = dollars % 10;
    if (thousands > 0)
    {
        digit_to_word(thousands);
        cout << "thousand ";
    }
    if (hundreds > 0)
    {
        digit_to_word(hundreds);
        cout << "hundred ";
    }
    if (tens == 1)
        eleven_to_nighteen(tens, digits);
    else if (tens > 1)
    {
        tens_to_word(tens);
        if (digits)
            digit_to_word(digits);
    }
    cout << "and " << cents << " cents " << endl;
}

void digit_to_word(int digit)
{
    if (digit == 1)
        cout << "one ";
    else if (digit == 2)
        cout << "two ";
    else if (digit == 3)
        cout << "three ";
    else if (digit == 4)
        cout << "four ";
    else if (digit == 5)
        cout << "five ";
    else if (digit == 6)
        cout << "six ";
    else if (digit == 7)
        cout << "seven ";
    else if (digit == 8)
        cout << "eight ";
    else if (digit == 9)
        cout << "nine ";
    else
        return;
}

void tens_to_word(int tens)
{
    if (tens == 2)
        cout << "twenty ";
    else if (tens == 3)
        cout << "thirty ";
    else if (tens == 4)
        cout << "forty ";
    else if (tens == 5)
        cout << "fifty ";
    else if (tens == 6)
        cout << "sixty ";
    else if (tens == 7)
        cout << "seventy ";
    else if (tens == 8)
        cout << "eighty ";
    else if (tens == 9)
        cout << "ninety ";
    else
        return;
}

void eleven_to_nighteen(int tens, int digit)
{
    int number = (10 * tens) + digit;
    if (number == 10)
        cout << "ten ";
    else if (number == 11)
        cout << "eleven ";
    else if (number == 12)
        cout << "twelve ";
    else if (number == 13)
        cout << "thirteen ";
    else if (number == 14)
        cout << "fourteen ";
    else if (number == 15)
        cout << "fifteen ";
    else if (number == 16)
        cout << "sixteen ";
    else if (number == 17)
        cout << "seventeen ";
    else if (number == 18)
        cout << "eighteen ";
    else if (number == 19)
        cout << "nineteen ";
    else
        return;
}

void display(string date, string name, double money)
{
    cout << "Date: " << date << endl;
    cout << "Pay to the Order of:  " << name << "\t$" << fixed << setprecision(2) << money << endl;
    display_money(money);
}
