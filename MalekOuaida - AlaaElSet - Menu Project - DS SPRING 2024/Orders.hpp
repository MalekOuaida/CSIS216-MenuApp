//
//  Orders.hpp
//  MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024
//
//  Created by Malek Ouaida on 21/04/2024.
//

/*-- Orders.hpp ---------------------------------------------------------
 This header file defines the data types Orders that handles all the aspects regarding the orders.
 Basic operations are:
 Constructors
 addOrder: Adds an item to the order
 removeOrder: Removes an item from the order
 modifyOrder: Modifies the quantity of an item in the order
 addOffer: Adds a special offer to the order
 displayBill: Displays the bill for the order
 isEmpty: shows if the order is empty
 ------------------------------------------------------------------------
 */

#include "Menu.hpp"
#include "menuItems.hpp"
#include "specialOffers.hpp"
#include <vector>
#include <stdio.h>
#ifndef Order_h
#define Order_h
class Order{
public:
    /*** Function Members ***/
    /** Class Constructor **/
    
    Order();
    /*-------------------------------------------------------------------
     Constructor for the Order class.
     Initializes member variables.
     -------------------------------------------------------------------*/
    
    ~Order();
    /*-------------------------------------------------------------------
     Destructor for the Order class.
     *Deallocates memory used by the order.
     -------------------------------------------------------------------*/
    

    void addOrder(menuItems& , int quantity);
    /*-------------------------------------------------------------------
     Adds an item to the order.
     Precondition: None.
     Postcondition: The specified item is added to the order with the given quantity.
     -------------------------------------------------------------------*/
    
    void removeOrder(menuItems& itemId);
    /*-------------------------------------------------------------------
     Removes an item from the order.
     
     Precondition: None.
     Postcondition: The specified item is removed from the order
    -------------------------------------------------------------------*/
    
    void modifyOrder(menuItems& , menuItems& , int quantity);
    /*-------------------------------------------------------------------
     Modifies the quantity of an item in the order.
     
     Precondition: None.
     Postcondition: The quantity of the specified item in the order is modified.
     -------------------------------------------------------------------*/
    
    void addOffer(specialOffers& , int quantity);
    /*-------------------------------------------------------------------
     Adds a special offer to the order.
     
     Precondition: None.
     Postcondition: The special offer is applied to the order with the given quantity.
     -------------------------------------------------------------------*/
    
    void displayBill();
    /*-------------------------------------------------------------------
     Displays the bill for the order.
     
     Precondition: None.
     Postcondition: The bill for the order is displayed on the screen.
     -------------------------------------------------------------------*/
    
    bool isEmpty() const;
    /*-------------------------------------------------------------------
     Shows if the order is empty.
     
     Precondition: None.
     Postcondition: Returns true if the order is empty.
     -------------------------------------------------------------------*/
    
private:
    class OrderItems{
    public:
        menuItems item;     //the item in the order
        int quantity;       //the quantity of the item in the order
        OrderItems() : quantity(0) {}
        /*-------------------------------------------------------------------
         Constructor for the OrderItems class.
         Initializes member variables
         -------------------------------------------------------------------*/
        
        OrderItems(const menuItems&, int quantity);
        /*-------------------------------------------------------------------
         Parameterized constructor for the OrderItems class.
         Initializes member variables with specified values.
         -------------------------------------------------------------------*/
        
    };


    vector <OrderItems> order;      //Vector to store the items in the order

    Menu menu;      //menu object to access menu items.

};
#endif /* Order_h */
