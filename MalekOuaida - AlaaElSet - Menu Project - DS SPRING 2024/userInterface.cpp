//
//  userInterface.cpp
//  MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024
//
//  Created by Malek Ouaida on 21/04/2024.
//

#include "userInterface.hpp"
#include "Authentication.hpp"
#include <iostream>
#include "fileManager.hpp"
using namespace std;


// Initializes a new user interface object.
// Sets the initial state of admin login status, menu, order, and offers.
userInterface::userInterface() : loggedInAsAdmin(false), menu(), order(), offers(menu) {
    loadMenuItems();
    offers.initializeOffers();
}

//loads the menu item from the file
void userInterface::loadMenuItems(){
    string filename = "/Users/malekouaida/Documents/MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024/MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024/proj.txt";
    fileManager fileMgr(menu);
    fileMgr.loadMenuFromFile(filename, menu);
}

// Initiates the user interface loop.
// Displays a welcome message and prompts the user to log in as a client or an admin.
// Handles user input for menu navigation.
void userInterface::run() {
    char userType;
    bool exitProgram = false;
    do {
        cout << "Welcome to Hamido's Menu System \nAre you a client (C) or an admin (A)? ";
        cin >> userType;
        if (userType == 'C' || userType == 'c') {
            loggedInAsAdmin = false;
            displayOptions();
            processChoice();
        } else if (userType == 'A' || userType == 'a') {
            loggedInAsAdmin = false;
            do {
                if (loginAdmin()) {
                    loggedInAsAdmin = true;
                    displayOptions();
                    processChoice();
                } else
                    cout << "Invalid password! Please try again." << endl;
            } while (!loggedInAsAdmin);
        } else if (toupper(userType) == 'Q') {
            cout << "Exiting program.\n";
            exitProgram = true;
        } else {
            cout << "Invalid choice. Please enter 'C' for client, 'A' for admin, or 'Q' to quit." << endl;
        }
    } while (!exitProgram);
}

//displays the admin or customer option
void userInterface::displayOptions() {
    if (loggedInAsAdmin) {
        cout << "Admin Menu\t" << endl;
        cout << "1. Display Menu" << endl;
        cout << "2. Display Offers" << endl;
        cout << "3. Add Item to Menu" << endl;
        cout << "4. Remove Item from Menu" << endl;
        cout << "5. Modify Item in Menu" << endl;
        cout << "6. Update Special Offers" << endl;
        cout << "L. Logout" << endl;
    } else {
        cout << "User Menu\t" << endl;
        cout << "1. Display Menu" << endl;
        cout << "2. Display Offers" << endl;
        cout << "3. Place Order" << endl;
        cout << "4. Modify Order" << endl;
        cout << "5. Remove Order" << endl;
        cout << "6. Display Bill" << endl;
        cout << "L. Login as Admin" << endl;
    }
    cout << "Q. Quit" << endl;
}

//processes the choice done
void userInterface::processChoice() {
    char choice;
    cin >> choice;
    if (loggedInAsAdmin) {
        switch (toupper(choice)) {
            case '1': displayMenu(); break;
            case '2': displayOffers(); break;
            case '3': addItemToMenu(); break;
            case '4': removeItemFromMenu(); break;
            case '5': modifyItemInMenu(); break;
            case '6': updateSpecialOffers();break;
            case 'L': loggedInAsAdmin = false; cout << "Logged out as Admin.\n"; break;
            case 'Q': cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    } else {
        switch (toupper(choice)) {
            case '1': displayMenu(); break;
            case '2': displayOffers(); break;
            case '3': placeOrder(); break;
            case '4': modifyOrder();break;
            case '5': removeOrder();break;
            case '6': displayBill(); break;
            case 'L': if (loginAdmin()) { loggedInAsAdmin = true; displayOptions(); processChoice(); } break;
            case 'Q': cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    }
}

//removes the order
void userInterface::removeOrder() {
    if (order.isEmpty()) {
        cout << "No orders to remove." << endl;
        return;
    }

    cout << "Enter the ID of the item you want to remove from the order: ";
    int itemId;
    cin >> itemId;

    menuItems* item = menu.findItemById(itemId);
    if (!item) {
        cout << "Item not found!" << endl;
        return;
    }

    order.removeOrder(*item);
    cout << "Item removed from the order successfully." << endl;
}

//displays the menu
void userInterface::displayMenu() {
    char choice;
    char chosencat;
    do {
        cout << "Choose Your Category: 'A' for appetizers, 'M' for main dishes, 'D' for desserts, or 'B' for beverages" << endl;
        cin >> chosencat;
        toupper(chosencat);
        menu.displayItemsByCategory(chosencat);

        cout << "Do you want to check the other menus? (Y/N): ";
        cin >> choice;
        if (toupper(choice) != 'Y') {
            break;
        }
    } while (toupper(choice) == 'Y');
}


//display the offers
void userInterface::displayOffers() {
    offers.displayOffers();
}

//places the order done
void userInterface::placeOrder() {
    cout << "Enter the ID of the item you want to order: ";
    int itemId;
    cin >> itemId;

    menuItems* item = menu.findItemById(itemId);
    if (!item) {
        cout << "Item not found!" << endl;
        return;
    }

    cout << "Enter the quantity: ";
    int quantity;
    cin >> quantity;

    if (quantity <= 0) {
        cout << "Invalid quantity. Must be greater than zero." << endl;
        return;
    }

    if (offers.isSpecialOfferItem(itemId)) {
        order.addOffer(offers, quantity);
        offers.updateOffer(itemId, quantity);
    } else {
        order.addOrder(*item, quantity);
    }
}

//displays the bill
void userInterface::displayBill() {
    order.displayBill();
}

//adds an item to the menu by the admin
void userInterface::addItemToMenu() {
    string name;
    double price;
    char category, type;
    int ingredientCount;

    cout << "Enter the name of the item: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    cout << "Enter the price of the item: $";
    while (!(cin >> price) || price <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid price. Please enter a positive value: ";
    }

    cout << "Enter the category of the item (A for Appetizers, M for Main dishes, D for Desserts, B for Beverages): ";
    cin >> category;
    category = toupper(category);
    while (category != 'A' && category != 'M' && category != 'D' && category != 'B') {
        cout << "Invalid category. Please enter 'A', 'M', 'D', or 'B': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> category;
        category = toupper(category);
    }

    cout << "Enter the type of the item (V for Vegan, G for Vegetarian, O for Omnivorous): ";
    cin >> type;
    type = toupper(type);
    while (type != 'V' && type != 'G' && type != 'O') {
        cout << "Invalid type. Please enter 'V', 'G', or 'O': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> type;
        type = toupper(type);
    }

    cout << "Enter the number of ingredients: ";
    while (!(cin >> ingredientCount) || ingredientCount <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number. Please enter a positive integer: ";
    }

    string* ingredients = new string[ingredientCount];
    cin.ignore(); // Clear newline character before reading strings
    cout << "Enter the ingredients (one per line):" << endl;
    for (int i = 0; i < ingredientCount; ++i) {
        cout << "Ingredient " << (i + 1) << ": ";
        getline(cin, ingredients[i]);
    }

    menuItems newItem(name, price, type, category, ingredients, ingredientCount);
    menu.addItem(newItem);
    fileManager filmnger(menu);
    filmnger.writeMenuToFile("/Users/malekouaida/Documents/MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024/MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024/proj.txt");

    cout << "New item added to menu successfully." << endl;
}

//removes item from the mnu by the admin
void userInterface::removeItemFromMenu() {
    cout << "Enter the ID of the item you want to remove: ";
    int id;
    cin >> id;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid numeric ID." << endl;
        return;
    }

    if (menu.removeItem(id)) {
        fileManager fileMgr(menu);
        fileMgr.writeMenuToFile("/Users/malekouaida/Documents/MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024/MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024/proj.txt");
        cout << "Item removed from menu successfully and file updated." << endl;
    } else {
        cout << "Item not found." << endl;
    }
}

//modifies the item by the admin
void userInterface::modifyItemInMenu() {
    int id;
    cout << "Enter the ID of the item you want to modify: ";
    cin >> id;

    menuItems* item = menu.findItemById(id);

    if (item) {
        string name;
        double price;
        char type, category;
        int ingredientsCount;

        cout << "Enter the new name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter the new price: ";
        while (!(cin >> price) || price <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid price. Please enter a positive value: ";
        }

        cout << "Enter the new type (V for Vegan, G for Vegetarian, O for Omnivorous): ";
        while (true) {
            cin >> type;
            type = toupper(type);
            if (type == 'V' || type == 'G' || type == 'O') {
                break;
            } else {
                cout << "Invalid type. Enter 'V', 'G', or 'O': ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        cout << "Enter the new category (A for Appetizers, M for Main dish, D for Dessert, B for Beverages): ";
        while (true) {
            cin >> category;
            category = toupper(category);
            if (category == 'A' || category == 'M' || category == 'D' || 'B') {
                break;
            } else {
                cout << "Invalid category. Enter 'A', 'M', 'D', or 'B': ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        cout << "Enter the number of ingredients: ";
        while (!(cin >> ingredientsCount) || ingredientsCount < 1) { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid count. Enter a positive integer: ";
        }

        string* ingredients = new string[ingredientsCount];
        cout << "Enter the ingredients (one per line):" << endl;
        cin.ignore();
        for (int i = 0; i < ingredientsCount; ++i) {
            cout << "Ingredient " << (i + 1) << ": ";
            getline(cin, ingredients[i]);
        }

        menuItems newItem(name, price, type, category, ingredients, ingredientsCount);
        menu.modifyItem(id, newItem);
        fileManager fileMgr(menu);
        fileMgr.writeMenuToFile("/Users/malekouaida/Documents/MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024/MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024/proj.txt");
        cout << "Item modified successfully." << endl;
    } else {
        cout << "Item not found." << endl;
    }
}

//log in as admin if the password
bool userInterface::loginAdmin() {
    string password;
    cout << "Enter admin password: ";
    cin >> password;
    return auth.adminLogin(password);
}

//modifies the order
void userInterface::modifyOrder() {
    if (order.isEmpty()) {
        cout << "No orders to modify." << endl;
        return;
    }

    cout << "Enter the ID of the item you want to modify: ";
    int oldItemId;
    cin >> oldItemId;

    menuItems* oldItem = menu.findItemById(oldItemId);
    if (!oldItem) {
        cout << "Item not found!" << endl;
        return;
    }

    cout << "Enter the new item ID: ";
    int newItemId;
    cin >> newItemId;

    menuItems* newItem = menu.findItemById(newItemId);
    if (!newItem) {
        cout << "New item not found!" << endl;
        return;
    }

    cout << "Enter the new quantity: ";
    int newQuantity;
    cin >> newQuantity;

    if (newQuantity <= 0) {
        cout << "Invalid quantity. It must be greater than zero." << endl;
        return;
    }

    order.modifyOrder(*oldItem, *newItem, newQuantity);
    cout << "Order modified successfully." << endl;
}

//updates the special offer
void userInterface::updateSpecialOffers() {
    cout << "Updating special offers...\n";
    offers.displayOffers();
    cout << "Enter the ID of the offer to update: ";
    int offerId;
    cin >> offerId;
    int newQuantity = specialOffers::getRandomQuantity();
    offers.updateOffer(offerId, newQuantity);
    cout << "Special offer updated.\n";
}



