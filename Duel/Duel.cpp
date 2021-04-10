/* C++ HW3 no.6
It's a program to simulate three marksman's dual(Aaron, Bob, and Charlie)
Here's the rule:
1. Aaron hits the target with the prob. of 1/3, Bob 1/2, and Charlie 1
2. The order might be: Aaron, Bob, and Charlie to compensate the inequalities
3. Turns are taken until one shooter remains
4. Simulate this dual for 10000 times with random number
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive)
{
    /*A->Aaron , B->Bob, C->Charlie
    Return: true if at least two are alive
    otherwise return false
    */

    if ((A_alive && B_alive) || (B_alive && C_alive) || (A_alive && C_alive))
        return true;
    else
        return false;
}

void Aaron_shoot1(bool &B_alive, bool &C_alive)
{
    // The first time Aaron shoot normally
    int shooting_result = rand() % 100; //random:0~100

    if (C_alive == true)
    {
        cout << "\t\tAaron is shooting at Charlie\n";
        if (shooting_result <= 33)
        {
            C_alive = false;
            cout << "\t\tCharlie is dead\n";
        }
        else
            cout << "\t\tAaron missed\n";
    }
    else if (B_alive == true)
    {
        cout << "\t\tAaron is shooting at Bob\n";
        if (shooting_result <= 33)
        {
            B_alive = false;
            cout << "\t\tBob is dead\n";
        }
        else
            cout << "\t\tAaron missed\n";
    }
    else
        cout << "\t\tAaron missed\n";
}

void Bob_shoot(bool &A_alive, bool &C_alive)
{
    int shooting_result = rand() % 100; //random:0~100

    if (C_alive == true)
    {
        cout << "\t\tBob is shooting at Charlie\n";
        if (shooting_result <= 50)
        {
            C_alive = false;
            cout << "\t\tCharlie is dead\n";
        }
        else
            cout << "\t\tBob missed\n";
    }
    else
    {
        cout << "\t\tBob is shooting at Aaron\n";
        if (shooting_result <= 50)
        {
            A_alive = false;
            cout << "\t\tAaron is dead\n";
        }
        else
            cout << "\t\tBob missed\n";
    }
}

void Charlie_shoot(bool &A_alive, bool &B_alive)
{
    if (B_alive == true)
    {
        cout << "\t\tCharlie is shooting at Bob\n";
        B_alive = false;
        cout << "\t\tBob is dead\n";
    }
    else
    {
        cout << "\t\tCharlie is shooting at Aaron\n";
        A_alive = false;
        cout << "\t\tAaron is dead\n";
    }
}

void Aaron_shoot2(bool &B_alive, bool &C_alive)
{
    int i = 0;
    int shooting_result = rand() % 100;
    if (B_alive && C_alive && i < 1)
    {
        cout << "\t\tAaron intentionally misses his first shot\n";
        cout << "\t\tBoth Bob and Charlie are alive.\n";
        i++;
    }
    else if (B_alive)
    {
        cout << "\t\tAaron is shooting at Bob\n";
        if (shooting_result <= 33)
        {
            cout << "\t\tBob is dead\n";
            B_alive = false;
        }
        else
        {
            cout << "\t\tAaron misses\n";
        }
    }
    else if (C_alive)
    {
        cout << "\t\tAaron is shooting at Charlie\n";
        if (shooting_result <= 33)
        {
            cout << "\t\tCharlie is dead\n";
            C_alive = false;
        }
        else
        {
            cout << "\t\tAaron missed\n";
        }
    }
}

int main()
{
    srand(time(0)); // use this to achieve the real  'random'
    const int run_count = 10000;
    int A_win_s1 = 0, B_win_s1 = 0, C_win_s1 = 0,
        A_win_s2 = 0, B_win_s2 = 0, C_win_s2 = 0;

    cout << "Let's start this dual of death\n";

    //Strategy 1
    cout << "Ready to test strategy 1:\n";
    cout << "Press any key to continue...";
    cin.ignore().get(); // sth to clean the data in buffer

    for (int i = 0; i < run_count; i++)
    {
        bool aaron_live = true;
        bool bob_live = true;
        bool charlie_live = true;

        while (at_least_two_alive(aaron_live, bob_live, charlie_live))
        {
            if (aaron_live)
            {
                Aaron_shoot1(bob_live, charlie_live);
            }
            if (bob_live)
            {
                Bob_shoot(aaron_live, charlie_live);
            }
            if (charlie_live)
            {
                Charlie_shoot(aaron_live, bob_live);
            }
            cout << endl;
        }
        if (aaron_live)
        {
            A_win_s1++;
        }
        else if (bob_live)
        {
            B_win_s1++;
        }
        else if (charlie_live)
        {
            C_win_s1++;
        }
    }

    //results are stored and printed to terminal
    double Aaron_win1 = A_win_s1 * 1.0 / run_count;
    double Bob_win1 = B_win_s1 * 1.0 / run_count;
    double Charlie_win1 = C_win_s1 * 1.0 / run_count;

    cout << "Aaron won " << A_win_s1 << "/10000 duels and the prob. is " << Aaron_win1 * 100 << "%\n";
    cout << "Bob won " << B_win_s1 << "/10000 duels and the prob. is " << Bob_win1 * 100 << "%\n";
    cout << "Charlie won " << C_win_s1 << "/10000 duels and the prob. is " << Charlie_win1 * 100 << "%\n\n";

    //Strategy 2
    cout << "Ready to test strategy 2:\n";
    cout << "Press any key to continue...";
    cin.ignore().get();

    for (int x = 0; x < run_count; x++)
    {
        bool aaron_live_2 = true;
        bool bob_live_2 = true;
        bool charlie_live_2 = true;

        while (at_least_two_alive(aaron_live_2, bob_live_2, charlie_live_2))
        {
            if (aaron_live_2)
            {
                Aaron_shoot2(bob_live_2, charlie_live_2);
            }
            if (bob_live_2)
            {
                Bob_shoot(aaron_live_2, charlie_live_2);
            }
            if (charlie_live_2)
            {
                Charlie_shoot(aaron_live_2, bob_live_2);
            }
            cout << endl;
        }

        if (aaron_live_2)
        {
            A_win_s2++;
        }
        else if (bob_live_2)
        {
            B_win_s2++;
        }
        else if (charlie_live_2)
        {
            C_win_s2++;
        }
    }

    double Aaron_win2 = A_win_s2 * 1.0 / run_count;
    double Bob_win2 = B_win_s2 * 1.0 / run_count;
    double Charlie_win2 = C_win_s2 * 1.0 / run_count;

    cout << "Aaron won " << A_win_s2 << "/10000 duels or " << Aaron_win2 * 100 << "%\n";
    cout << "Bob won " << B_win_s2 << "/10000 duels or " << Bob_win2 * 100 << "%\n";
    cout << "Charlie won " << C_win_s2 << "/10000 duels or " << Charlie_win2 * 100 << "%\n\n";

    if (Aaron_win2 > Aaron_win1)
    {
        cout << "Strategy 2 is better than strategy 1.\n";
    }
    else
    {
        cout << "Strategy 1 is better than strategy 2.\n";
    }

    return 0;
}