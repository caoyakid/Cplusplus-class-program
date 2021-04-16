#include <iostream>
using namespace std;

#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
class InventoryItem{
private:
    int itemNumber;
    int quantity; //number of units on hand
    double cost; 
    int onhand;

public:
    InventoryItem(); //default constructor
    InventoryItem(int, int, double, int); //constructor 2
    void setItemNumber(int itemNumbers){itemNumber = itemNumbers;}
    void setQuantity(int quantitys){quantity = quantitys;}
    void setCost(double costs){cost = costs;}
    void setonhand(int oh){onhand = oh;}
    int getItemNumber() const {return itemNumber;}
    int getQuantity() const {return quantity;}
    double getCost() const {return cost;}
    int getOnHand() const {return onhand;}

};

InventoryItem::InventoryItem(){
    itemNumber = 0;
    quantity = 0;
    cost = 0.0;
    onhand = 0;
}

InventoryItem::InventoryItem(int para_itemnumber, int para_quantity, double para_cost, int para_onhand){
    itemNumber = para_itemnumber;
    quantity = para_quantity;
    cost = para_cost;
    onhand = para_onhand;
}

#endif // INVENTORYITEM_H