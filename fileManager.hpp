//
//  fileManager.hpp
//  MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024
//
//  Created by Malek Ouaida on 21/04/2024.
//

/*-- menuItems.hpp ---------------------------------------------------------
 This header file defines the data types fileManager will read and write from.
 Basic operations are:
 Constructors: initializes a new menu item object
 readMenuFromFile: reads from the file
 writeMenuItemToFile: writes on the file
 ------------------------------------------------------------------------
 */

#ifndef fileManager_hpp
#define fileManager_hpp

#include <fstream>
#include <stdio.h>
#include <string>
#include "Menu.hpp"
using namespace std;
class fileManager {
    /*** Function Members ***/
    /** Class Constructor **/
private:
    Menu& menu; // Reference to the Menu object


public:
    fileManager(Menu&);
    /*-------------------------------------------------------------------
     Constructor for the fileManager class.
     Initializes member variables.
     -------------------------------------------------------------------*/
    
    void loadMenuFromFile(const string& filename, Menu& menu);
    /*-------------------------------------------------------------------
     Reads menu items from a file and adds them to the menu.
     
     Precondition: The specified file exists and is readable.
     Postcondition: Menu items are read from the file and added to the menu.
     -------------------------------------------------------------------*/
    
    void writeMenuToFile(const string& filename);
    /*-------------------------------------------------------------------
     Writes a menu item to a file.
     
     Precondition: The specified file is writable.
     Postcondition: The menu item is written to the file.
     -------------------------------------------------------------------*/
private:
};


#endif /* fileManager_hpp */

