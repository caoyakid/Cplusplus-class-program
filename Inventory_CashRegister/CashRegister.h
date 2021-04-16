#include <iostream>
using namespace std;
#ifndef CASHREGISTER_H
#define CASHREGISTER_H
#include "InventoryItem.h"

class InventortItem;

class CashRegister{
    friend class InventoryItem;

private:
    double subtotal;
    double total;
    double tax;
public:
    CashRegister();
    CashRegister(double, double, double);
    void setSubtotal(double sub)
	{subtotal = sub;}

	void setTotal(double tot)
	{total = tot;}

    void setTax(double tx)
    {tax = tx;}

	double getSubtotal() const
	{return subtotal ;}

	double getTotal() const
	{return total ;}

    double getTax() const
    {return tax;}
};

CashRegister::CashRegister()
{
    subtotal = 0;
    total = 0;
    tax = 0.06;
}

CashRegister::CashRegister(double sub, double tot, double tx)
{   
    subtotal = sub;
    total = tot;
    tax = tx;
}

#endif // CASHREGISTER_H