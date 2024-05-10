//
//  userInterface.hpp
//  MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024
//
//  Created by Malek Ouaida on 21/04/2024.
//

/*-- userInterface.hpp ---------------------------------------------------------
  This header file defines the data types userInterface that handles all the interface the user will be able to use.
  Basic operations are:
    Constructors
    run: calls all the methods and runs the userInterface
    displayMenu: displays the meuu
    displayOffers: displays the offers avaliable
    displayOptions: displays the main options
    processChoice: processes the choice the user chooses
    loadMenuItems: loads all the menu items
    placeOrder: places the order
    displayBill: shows the final bill after ordering
    addItemToMenu: adds an item to the menu
    removeItemFromMenu: removes an iem from the menu
    modifyItemInMenu: modifies an item fin the menu
    modifyOrder: modifies the whole order
    removeOrder: removes the whole order
    loginAdmin: logs in as admin
------------------------------------------------------------------------
*/


#ifndef userInterface_hpp
#define userInterface_hpp
#include "Menu.hpp"
#include "Orders.hpp"
#include "specialOffers.hpp"
#include "Authentication.hpp"
#include <stdio.h>
using namespace std;

class userInterface {
public:
    /*** Function Members ***/
    /** Class Constructor **/
    userInterface();
    /*-------------------------------------------------------------------
    Default consturctor for userInterface class.

    Precondition: None.
    Postconsition: userInterface object is initialized with default values;
    that is, loggedInAsAdmin, menu, order, and offers to (false), "","","".

    -------------------------------------------------------------------*/
    
    void run();
    /*-------------------------------------------------------------------
    Starts the user interface, allowing users to interact with the system.

    Precondition: None.
    Postconsition: runs the userinterface.

    -------------------------------------------------------------------*/
    
    
private:
    /*** Data Members ***/
    authentication auth;    //auth object from Authentication class
    Order order;    //order object from Order class
    Menu menu;  //menu object from Menu class
    specialOffers offers;   //offers object from specialOffers class
    bool loggedInAsAdmin;   //bool variable

    void displayMenu();
    /*-------------------------------------------------------------------------
        Displays the main menu.

        Precondition: None.
        Postcondition: The main menu is displayed on the screen.
    -------------------------------------------------------------------------*/
    
    void displayOffers();
    /*-------------------------------------------------------------------------
        Displays the special offers available.

        Precondition: None.
        Postcondition: The special offers are displayed on the screen.
    -------------------------------------------------------------------------*/
    
    void displayOptions();
    /*-------------------------------------------------------------------------
        Displays all available options (for admin).

        Precondition: User must be logged in as admin.
        Postcondition: Admin options are displayed on the screen.
    -------------------------------------------------------------------------*/
    
    void processChoice();
    /*-------------------------------------------------------------------------
        Processes the user's choice.

        Precondition: None.
        Postcondition: The user's choice is processed.
    -------------------------------------------------------------------------*/
    
    void loadMenuItems();
    /*-------------------------------------------------------------------------
        Loads all the menu items
        
        Precondition: None.
        Postcondition: menu items are loaded.
    -------------------------------------------------------------------------*/
    
    void placeOrder();
    /*-------------------------------------------------------------------------
        places an order set by the user.
        
        Precondition: None.
        Postcondition: order is placed.
    -------------------------------------------------------------------------*/
    
    void displayBill();
    /*-------------------------------------------------------------------------
        Displays the bill for the current order.

        Precondition: An order must have been placed.
        Postcondition: The bill for the current order is displayed.
    -------------------------------------------------------------------------*/
    
    void addItemToMenu();
    /*-------------------------------------------------------------------------
        Adds an item to the menu (admin only).

        Precondition: User must be logged in as admin.
        Postcondition: An item is added to the menu.
    -------------------------------------------------------------------------*/
    
    void removeItemFromMenu();
    /*-------------------------------------------------------------------------
        Removes an item from the menu (admin only).

        Precondition: User must be logged in as admin.
        Postcondition: An item is removed from the menu.
    -------------------------------------------------------------------------*/

    
    void modifyItemInMenu();
    /*-------------------------------------------------------------------------
        Modifies an item in the menu (admin only).

        Precondition: User must be logged in as admin.
        Postcondition: An item in the menu is modified.
    -------------------------------------------------------------------------*/
    
    void modifyOrder();
    /*-------------------------------------------------------------------------
        modifies the order.
        
        Precondition: None.
        Postcondition: order is modified.
    -------------------------------------------------------------------------*/
    
    void removeOrder();
    /*-------------------------------------------------------------------------
        removes the order.
        
        Precondition: None.
        Postcondition: the order is removed.
    -------------------------------------------------------------------------*/
    
    void updateSpecialOffers();
    /*-------------------------------------------------------------------------
        uopdates the special offers.
        
        Precondition: None.
        Postcondition: the special .
    -------------------------------------------------------------------------*/

    bool loginAdmin();
    /*-------------------------------------------------------------------------
        Logs in as an admin.
        
        Precondition: None.
        Postcondition: User is logged in as an admin.
    -------------------------------------------------------------------------*/
    
};
#endif /* userInterface_hpp */
