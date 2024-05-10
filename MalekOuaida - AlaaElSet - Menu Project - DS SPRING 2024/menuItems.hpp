//
//  menuItems.hpp
//  MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024
//
//  Created by Malek Ouaida on 21/04/2024.
//

/*-- menuItems.hpp ---------------------------------------------------------
 This header file defines the data types menuItems that handles all the items in the menu.
 Basic operations are:
 Constructors: initializes a new menu item object
 displayDetails: Displays the details of the menu item
 getId: Retrieves the ID of the menu item
 getName: Retrieves the name of the menu item
 getPrice: Retrieves the Price of the menu item
 getType: Retrieves the type of the menu item
 getCategory: Retrieves the category of the menu item
 getIngredients: Retrieves the ingredients of the menu item
 getNumIngredients: : Retrieves the number of ingredients of the menu item
 setName: Sets the name of the menu item
 setPrice: Sets the Price of the menu item
 setType: Sets the type of the menu item
 setCategory: Sets the category of the menu item
 setIngredients: Sets the ingendients of the menu item
 generateNextId: Generates the next ID for a menu item in the specified category
 ------------------------------------------------------------------------
 */

#ifndef menuItems_hpp
#define menuItems_hpp

#include "specialOffers.hpp"
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class menuItems {
    
public:
    /*** Function Members ***/
    /** Class Constructor **/
    menuItems();
    /*-------------------------------------------------------------------
     Default constructor for the menuItems class.
     Initializes member variables.
     -------------------------------------------------------------------*/
    
    menuItems(string name, double price, char type, char category, string ingredients[], int numIngredients);
    /*-------------------------------------------------------------------
     Parameterized constructor for the menuItems class.
     Initializes member variables with specified values.
     -------------------------------------------------------------------*/
    
    menuItems(const menuItems& other);
    /*-------------------------------------------------------------------
     Copy constructor for the menuItems class.
     Initializes member variables by copying values from another menuItems object.
     -------------------------------------------------------------------*/
    
    ~menuItems();
    /*-------------------------------------------------------------------
     Destructor for the menuItems class.
     Deallocates memory used by the menu item.
     -------------------------------------------------------------------*/
    
    void displayDetails() const;
    /*-------------------------------------------------------------------
     Displays details of the menu item.
     
     Precondition: None.
     Postcondition: Details of the menu item are displayed on the screen
     -------------------------------------------------------------------*/
    
    int getId() const;
    /*-------------------------------------------------------------------
     Retrieves the ID of the menu item.
     
     Precondition: None.
     Postcondition: Returns the ID of the menu item.
     -------------------------------------------------------------------*/
    
    string getName() const;
    /*-------------------------------------------------------------------
     Retrieves the name of the menu item.
     
     Precondition: None.
     Postcondition: Returns the name of the menu item.
     -------------------------------------------------------------------*/
    
    double getPrice() const;
    /*-------------------------------------------------------------------
     Retrieves the price of the menu item.
     
     Precondition: None.
     Postcondition: Returns the price of the menu item.
     -------------------------------------------------------------------*/
    
    char getType() const;
    /*-------------------------------------------------------------------
     Retrieves the type of the menu item.
     
     Precondition: None.
     Postcondition: Returns the type of the menu item.
     -------------------------------------------------------------------*/
    
    char getCategory() const;
    /*-------------------------------------------------------------------
     Retrieves the category of the menu item.
     
     Precondition: None.
     Postcondition: Returns the category of the menu item.
     -------------------------------------------------------------------*/
    
    string* getIngredients() const;
    /*-------------------------------------------------------------------
     Retrieves the ingredients of the menu item.
     
     Precondition: None.
     Postcondition: Returns the ingredients of the menu item.
     -------------------------------------------------------------------*/
    
    int getNumIngredients() const;
    /*-------------------------------------------------------------------
     Retrieves the number of ingredients of the menu item.
     
     Precondition: None.
     Postcondition: Returns the number of ingredients of the menu item.
     -------------------------------------------------------------------*/
    
    
    //void setId(int newId);
    void setName(string newName);
    /*-------------------------------------------------------------------
     Sets the name of the menu item.
     
     Precondition: None.
     Postcondition: The name of the menu item is set to the specified value.
     -------------------------------------------------------------------*/
    
    void setPrice(double newPrice);
    /*-------------------------------------------------------------------
     Sets the price of the menu item.
     
     Precondition: None.
     Postcondition: The price of the menu item is set to the specified value.
     -------------------------------------------------------------------*/
    
    void setType(char newType);
    /*-------------------------------------------------------------------
     Sets the type of the menu item.
     
     Precondition: None.
     Postcondition: The type of the menu item is set to the specified value.
     -------------------------------------------------------------------*/
    
    void setCategory(char newCategory);
    /*-------------------------------------------------------------------
     Sets the category of the menu item.
     
     Precondition: None.
     Postcondition: The category of the menu item is set to the specified value.
     -------------------------------------------------------------------*/

    
    void setIngredients(const string newIngredients[], int newNumIngredients);
    /*-------------------------------------------------------------------
     Sets the ingredients of the menu item.
     
     Precondition: None.
     Postcondition: The ingredients of the menu item is set to the specified value.
     -------------------------------------------------------------------*/
    
    static int generateNextId(char category);
    /*-------------------------------------------------------------------
     Generates the next ID for a menu item in the specified category.
     
     Precondition: None.
     Postcondition: Returns the next available ID for a menu item in the specified category.
     -------------------------------------------------------------------*/

    
private:
    
    static int lastAppetizerId;     //saves the last apptezier
    static int lastMainDishId;      //saves the last main dish
    static int lastDessertId;       //saves the last dessert
    static int lastBeverageId;      //saves the last bevarage
    
    int id;                 //ID of the menu item
    string name;            //namer of the menu item
    double price;           //price of the menu item
    char type;              //type of the menu item
    char category;          //category of the menu item
    string* ingredients;    //ingredients of the menu items
    int numIngredients;     //number of ingredients in the menu item
};


#endif /* menuItems_hpp */

