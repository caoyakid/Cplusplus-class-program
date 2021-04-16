#include <iostream>
#include <iomanip>
#include "InventoryItem.h"
#include "CashRegister.h"
using namespace std;

int main()
{
    int pickItem;
    double newtax = 0.06;
    double newcost = 0;
    int newquantity = 0;
    int newonhand = 0;
    int stock = 0;
    const int NUM_ITEMS = 5;

    InventoryItem inventory[NUM_ITEMS] = {
        InventoryItem(1, 12, 6.95, 10),
        InventoryItem(2, 20, 8.75, 10),
        InventoryItem(3, 10, 3.75, 10),
        InventoryItem(4, 14, 7.95, 10),
        InventoryItem(5, 22, 2.50, 10),
    };


    cout << setw(14) << "Inventory Item"
         << setw(8) << "Cost"
         << setw(12) << "Quantity" << setw(14) << "On Hand\n";
    cout << "----------------------------------------------------------\n";

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        cout << setw(14) << inventory[i].getItemNumber();
        cout << setw(8) << inventory[i].getCost();
        cout << setw(12) << inventory[i].getQuantity();
        cout << setw(14) << inventory[i].getOnHand() << endl;
    }

    cout << "\n";
    cout << "Enter #1 to #5 for item selection: ";

    int flag1 = 0;
    while (flag1 = 1)
    {
        cin >> pickItem;
        if (pickItem < 1 || pickItem > 5)
        {
            cout << "Please enter a number within range: ";
        }
        else
        {
            break;
        }
    };

    cout << "\n";

    if (pickItem == 1)
    {
        newcost = inventory[0].getCost();
    }
    else if (pickItem == 2)
    {
        newcost = inventory[1].getCost();
    }
    else if (pickItem == 3)
    {
        newcost = inventory[2].getCost();
    }
    else if (pickItem == 4)
    {
        newcost = inventory[3].getCost();
    }
    else if (pickItem == 5)
    {
        newcost = inventory[4].getCost();
    }

    cout << "How much would you like to buy: ";

    int flag2 = 0;
    while (flag2 = 1)
    {
        cin >> newquantity;
        if (newquantity < 1)
        {
            cout << "Please enter a positive number: ";
        }
        else
        {
            break;
        }
    };

    CashRegister Register((1.3*newcost)*newquantity,1.06 * ((1.3*newcost)*newquantity), newtax);
    Register.setSubtotal(((1.3*newcost)*newquantity));
    Register.setTotal(1.06 * ((1.3*newcost)*newquantity));

	cout << fixed << showpoint << setprecision(2);
	cout << "Your Subtotal is $" << Register.getSubtotal()
		<< " and your Total is $" << Register.getTotal()
		<< " with " << Register.getTax() << "% Tax included."
		<< "\n" << endl;

	cout << "In addition, there is ";

    cout << "\n";

    if (pickItem == 1)
	{ inventory[0].setonhand(inventory[0].getQuantity() - newquantity);
	cout << inventory[0].getOnHand();}
	else if (pickItem == 2)
	{ inventory[1].setonhand(inventory[1].getQuantity() - newquantity);
	cout << inventory[1].getOnHand();}
	else if (pickItem == 3)
	{ inventory[2].setonhand(inventory[2].getQuantity() - newquantity);
	cout << inventory[2].getOnHand();}
	else if (pickItem == 4)
	{ inventory[3].setonhand(inventory[3].getQuantity() - newquantity);
	cout << inventory[3].getOnHand();}
	else if (pickItem == 5)
	{ inventory[4].setonhand(inventory[4].getQuantity() - newquantity);
	cout << inventory[4].getOnHand();}

	cout << " of ";

	if (pickItem == 1)
	{cout << inventory[0].getItemNumber();}
	else if (pickItem == 2)
	{cout << inventory[1].getItemNumber();}
	else if (pickItem == 3)
	{cout << inventory[2].getItemNumber();}
	else if (pickItem == 4)
	{cout << inventory[3].getItemNumber();}
	else if (pickItem == 5)
	{cout << inventory[4].getItemNumber();}
	
	cout << " left in stock." << endl;

    cin.get();
    cin.ignore();
    return 0;
}
