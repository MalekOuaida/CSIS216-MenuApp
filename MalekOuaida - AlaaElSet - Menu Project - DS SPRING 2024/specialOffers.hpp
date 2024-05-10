//
//  specialOffers.hpp
//  MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024
//
//  Created by Malek Ouaida on 21/04/2024.
//

/*-- specialOffers.hpp ---------------------------------------------------------
 This header file defines the data types and methods the class specialOffers uses.
 Basic operations are:
 Constructors: Initializes a specialOffers object.
 initializeOffers: Initializes special offers.
 addOffer: Adds a special offer for an item.
 updateOffer: Updates a special offer after an item is sold.
 isSpecialOfferItem: Checks if an item has a special offer.
 replaceOffer: Replaces a special offer at the specified index.
 displayOffers: dislays all the offers.
 getOffers: Retrieves the list of special offers.
 getRandomItemId: Retrieves a random item ID from the specified category.
 calculateDiscountPrice: Calculates the discount price for an item.
 getRandomQuantity: Retrieves a random quantity for a special offer.
 getItemPrice: Retrieves the item's price
 getItemCategory: Retrieves the item's category.
 ------------------------------------------------------------------------
 */

#ifndef specialOffers_hpp
#define specialOffers_hpp

#include <iostream>
#include <vector>
#include <random>
#include "menuItems.hpp"
class Menu;

using namespace std;

class specialOffers {
public:
    /*** Function Members ***/
    /** Class Constructor **/
    class Offer {
    public:
        int itemId;     //the item's id number
        int quantity;       //the quantity number
        Offer(int id, int qty) : itemId(id), quantity(qty) {}
        /*-------------------------------------------------------------------
         Constructor for the Offer class.
         
         Precondition: none
         Postcondition:  initializes itemId and Quantity
         -------------------------------------------------------------------*/
    };

    vector<Offer> offers;  //the vector that contains the offers

public:
    specialOffers(Menu&);
    /*-------------------------------------------------------------------
     Constructor for the specialOffers class.
     
     Precondition: none
     Postcondition: Initializes member variables.
     
     -------------------------------------------------------------------*/
    
    void initializeOffers();
    /*-------------------------------------------------------------------
     Initializes special offers.
     
     Precondition: None.
     Postcondition: Special offers are initialized.
     
     -------------------------------------------------------------------*/
    
    void addOffer(int itemId, int quantity);
    /*-------------------------------------------------------------------
     Adds a special offer for an item.
     
     Precondition: None.
     Postcondition: A special offer for the specified item is added.
     
     -------------------------------------------------------------------*/
    
    void updateOffer(int itemId, int soldQuantity);
    /*-------------------------------------------------------------------
     Updates a special offer after an item is sold.
     
     Precondition: None.
     Postcondition: The special offer is updated based on the sold quantity of the item.
     -------------------------------------------------------------------*/
    
    bool isSpecialOfferItem(int itemId);
    /*-------------------------------------------------------------------
     Checks if an item has a special offer.
     
     Precondition: None.
     Postcondition: Returns true if the item has a special offer, otherwise false.
     -------------------------------------------------------------------*/
    
    void replaceOffer(int index);
    /*-------------------------------------------------------------------
     Replaces a special offer at the specified index.
     
     Precondition: None.
     Postcondition: The special offer at the specified index is replaced.
     -------------------------------------------------------------------*/
    
    void displayOffers() const;
    /*-------------------------------------------------------------------
     Displays all special offers.
     
     Precondition: None.
     Postcondition: Special offers are displayed on the screen.
     -------------------------------------------------------------------*/
    
    const vector<Offer>& getOffers() const;
    /*-------------------------------------------------------------------
     Retrieves the list of special offers.
     
     Precondition: None.
     Postcondition: Returns the list of special offers.
     -------------------------------------------------------------------*/
    
    int getRandomItemId(char category);
    /*-------------------------------------------------------------------
     Retrieves a random item ID from the specified category.
     
     Precondition: None.
     Postcondition: Returns a random item ID from the specified category.
     -------------------------------------------------------------------*/
    double calculateDiscountPrice(int itemId) const;
    /*-------------------------------------------------------------------
     Calculates the discount price for an item.
     
     Precondition: None.
     Postcondition: Returns the discount price for the specified item.
     -------------------------------------------------------------------*/
    
    static const double DISCOUNT_RATE;  //final rate for the discount
    
    static int getRandomQuantity();
    /*-------------------------------------------------------------------
     Retrieves a random quantity for a special offer.
     
     Precondition: None.
     Postcondition: Returns a random quantity for a special offer.
     -------------------------------------------------------------------*/
    
    double getItemPrice(int itemId) const;
    /*-------------------------------------------------------------------
     Retrieves the price of an item.
     
     Precondition: None.
     Postcondition: Returns the price of the specified item.
     -------------------------------------------------------------------*/
    
    char getItemCategory(int itemId);
    /*-------------------------------------------------------------------
     Retrieves the category of an item.
     
     Precondition: None.
     Postcondition: Returns the category of the specified item.
     -------------------------------------------------------------------*/

private:
    Menu& menu;
};


#endif // specialOffers_hpp
