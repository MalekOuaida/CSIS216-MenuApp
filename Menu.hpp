//
//  Menu.hpp
//  MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024
//
//  Created by Malek Ouaida on 21/04/2024.
//

/*-- Menu.hpp ---------------------------------------------------------
 This header file defines the data types Menu that handles the menu.
 Basic operations are:
 Constructors: initializes a new menu object
 validateItem: Checks if a menu item is valid.
 addItem: Adds a menu item to the menu.
 removeItem: Removes a menu item from the menu.
 modifyItem: Modifies a menu item in the menu.
 findItemById: Finds a menu item in the menu by its ID.
 displayItemsByCategory: Displays menu items of a specified category.
 filterItemsByType: Filters menu items by type and displays them.
 displayVeganVegetarianMenu: Displays vegan and vegetarian menu items.
 traverseMenu: traverses through the menu.
 ------------------------------------------------------------------------
 */


#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include "menuItems.hpp"
#include <iostream>
#include <functional>

using namespace std;
class Menu {
private:
    /*** Function Members ***/
    /** Class Constructor **/
    class Node {
    public:
        menuItems data; //Data of the menu item
        Node* prev; //Pointer to the previous node
        Node* next; // Pointer to the next node
        
        Node(const menuItems& item) : data(item), prev(this), next(this) {}
        /*-------------------------------------------------------------------
         Constructor for the Node class.
         Initializes member variables.
         -------------------------------------------------------------------*/
        
        ~Node() {}
        /*-------------------------------------------------------------------
         Destructor for the Node class.
         Deallocates memory used by the node.
         -------------------------------------------------------------------*/
    };
    
    static const int NUM_CATEGORIES = 4; //Number of categories in the menu
    Node* categories[NUM_CATEGORIES];   //array of pointers to the head node of each category
    
public:
    Menu();
    /*-------------------------------------------------------------------
     Constructor for the Menu class.
     Initializes member variables.
     -------------------------------------------------------------------*/
    
    ~Menu();
    /*-------------------------------------------------------------------
     Destructor for the Menu class.
     Deallocates memory used by the menu.
     -------------------------------------------------------------------*/
    
    bool validateItem(const menuItems& item);
    /*-------------------------------------------------------------------
     Validates if a menu item is valid.
     
     Precondition: None.
     Postcondition: Returns true if the menu item is valid, otherwise false.
     -------------------------------------------------------------------*/

    void addItem(const menuItems& item);
    /*-------------------------------------------------------------------
     Adds a menu item to the menu.
     
     Precondition: None.
     Postcondition: The menu item is added to the menu.
     -------------------------------------------------------------------*/
    
    bool removeItem(int id);
    /*-------------------------------------------------------------------
     Removes a menu item from the menu.
     
     Precondition: None.
     Postcondition: Returns true if the menu item is removed successfully, otherwise false.
     -------------------------------------------------------------------*/
    
    bool modifyItem(int id, const menuItems& newData);
    /*-------------------------------------------------------------------
     Modifies a menu item in the menu.
     
     Precondition: None.
     Postcondition: Returns true if the menu item is modified successfully, otherwise false.
     -------------------------------------------------------------------*/
    
    menuItems* findItemById(int id);
    /*-------------------------------------------------------------------
     Finds a menu item in the menu by its ID.
     
     Precondition: None.
     Postcondition: Returns a pointer to the menu item if found, otherwise NULL.
     -------------------------------------------------------------------*/
    
    void displayItemsByCategory(char category);
    /*-------------------------------------------------------------------
     Displays menu items by category.
     
     Precondition: None.
     Postcondition: Displays menu items of the specified category on the screen.
     -------------------------------------------------------------------*/
    
    void filterItemsByType(char type);
    /*-------------------------------------------------------------------
     Filters menu items by type.
     
     Precondition: None.
     Postcondition: Displays menu items of the specified type on the screen.
     -------------------------------------------------------------------*/
    
    void displayVeganVegetarianMenu();
    /*-------------------------------------------------------------------
     Displays vegan and vegetarian menu items.
     * Precondition: None.
     * Postcondition: Displays vegan and vegetarian menu items on the screen.
     -------------------------------------------------------------------*/
    
    void traverseMenu(function<void(const menuItems&)> action);
    /*-------------------------------------------------------------------
     Displays menu items.
     * Precondition: None.
     * Postcondition: Displays the whole menu items on the screen.
     -------------------------------------------------------------------*/
    };


#endif /* Menu_hpp */
