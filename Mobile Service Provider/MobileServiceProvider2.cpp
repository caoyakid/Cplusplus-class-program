#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Varibles
    string month;
    int duration;
    float billA, billB, billC;
    float minutes;
    char package;
    // Ask for input: month
    cout << "Please enter the month(by name): ";
    cin >> month;
    if (month == "January" || month == "March" || month == "May" || month == "July" || month == "August" || month == "October" || month == "December")
    {
        duration = 744 * 60;
    }
    else if (month == "February")
    {
        duration = 672 * 60;
    }
    else if (month == "April" || month == "June" || month == "September" || month == "November")
    {
        duration = 720 * 60;
    }
    else
    {
        cout << "Invalid input" << endl;
        cout<<"Please enter the month again:"<<endl;
        cin>>month;
    }

    // 
    while(1)
    {
        // Ask for input1
        cout << "\nWhich package have you purchased? ";
        cout << "\nPlease use Capital(A.B.C ...)";
        cin >> package;

        // Check out if there exists wrong input
        while (!(package == 'A' || package == 'B' || package == 'C'))
        {
            cout << "Sorry, you just can select package A, B or C...";
            cout << "\nPlease select your package again: ";
            cin >> package;
        }
        // Ask for input2
        cout << "How many minutes were used? ";
        cin >> minutes;

        if (minutes < duration)
        {
            // Get the bill
            if (minutes < 450)
                billA = 39.99;
            else
                billA = 39.99 + (minutes - 450) * 0.45;

            if (minutes < 900)
                billB = 59.99;
            else
                billB = 59.99 + (minutes - 900) * 0.40;

            billC = 69.99;

            // Judge saving money or not
            if (package == 'A')
            {
                cout << "Your monthly bill is: " << billA << endl;
                if (billA > billB)
                    cout << "If you purchase B, you would save $" << billA - billB;
                if (billA > billC)
                    cout << "\nIf you purchase C, you would save $" << billA - billC;
            }
            else if (package == 'B')
            {
                cout << "Your monthly bill is: " << billB << endl;
                if (billB > billA)
                    cout << "If you purchase A, you would save $" << billB - billA;
                if (billB > billC)
                    cout << "\nIf you purchase C, you would save $" << billB - billC;
            }
            else
            {
                cout << "Your monthly bill is: " << billC << endl;
                if (billC > billA)
                    cout << "If you purchase A, you would save $" << billC - billA;
                if (billC > billB)
                    cout << "\nIf you purchase B, you would save $" << billC - billB;
            }
        }
        else
            cout << "The duration you actually use is more than that month..." << endl;
    }
    return 0;
}