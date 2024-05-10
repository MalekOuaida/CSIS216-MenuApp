//
//  Menu.cpp
//  MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024
//
//  Created by Malek Ouaida on 21/04/2024.
//

#include "Menu.hpp"
#include <cctype>

//Default constructor for the Menu class
Menu::Menu() {
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        categories[i] = NULL;
    }
}

//Destructor for the Menu class.
Menu::~Menu() {
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        if (categories[i] != NULL) {
            Node* start = categories[i];
            Node* current = start;
            do {
                Node* next = current->next;
                delete current;
                current = next;
            } while (current != start);
        }
    }
}

//Adds a menu item to the Menu object.
void Menu::addItem(const menuItems& item) {
    char category = toupper(item.getCategory());
    int index = -1;
    
    switch (category) {
        case 'A':
            index = 0;
            break;
        case 'M':
            index = 1;
            break;
        case 'D':
            index = 2;
            break;
        case 'B':
            index = 3;
            break;
        default:
            return;
    }
    Node* newNode = new Node(item);
    if(categories[index] == NULL){
        categories[index] = newNode;
        newNode -> next = newNode -> prev = newNode;
    }
    else {
        Node* tail = categories[index] -> prev;
        tail -> next = newNode;
        newNode -> prev = tail;
        newNode -> next = categories[index];
        categories[index] -> prev = newNode;
    }
}

//Removes a menu item from the Menu object by its ID.
bool Menu::removeItem(int id) {
    for(int i = 0; i < NUM_CATEGORIES; i++) {
        Node* head = categories[i];
        if (head) {
            Node* current = head;
            Node* prev = NULL;
            do {
                if (current->data.getId() == id) {
                    if (current == current->next) {
                        categories[i] = NULL;
                    } else {
                        if (current == head) { 
                            categories[i] = head->next;
                        }
                        current->prev->next = current->next;
                        current->next->prev = current->prev;
                    }
                    delete current;
                    return true;
                }
                prev = current;
                current = current->next;
            } while (current != head);
        }
    }
    return false;
}

//Finds a menu item by its ID.
menuItems* Menu::findItemById(int id) {
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        Node* head = categories[i];
        if (head) {
            Node* current = head;
            do {
                if (current->data.getId() == id) {
                    return &current->data;
                }
                current = current->next;
            } while (current != head);
        }
    }
    return NULL;
}

//Modifies a menu item with the specified ID.
bool Menu::modifyItem(int id, const menuItems& newData) {
    menuItems* item = findItemById(id);
    if (item) {
        *item = newData;
        return true;
    }
    return false;
}

//Displays all menu items in a specified category.
void Menu::displayItemsByCategory(char category) {
    int index = -1;
    switch (toupper(category)) {
        case 'A': index = 0; break;
        case 'M': index = 1; break;
        case 'D': index = 2; break;
        case 'B': index = 3; break;
        default:
            cerr << "Category not found: " << category << endl;
            return;
    }

    Node* head = categories[index];
    if (head == NULL) {
        cout << "No items found in category " << category << "." << endl;
        return;
    }

    Node* current = head;
    cout << "Items in category " << category << ":" << endl;
    do {
        current->data.displayDetails();
        current = current->next;
    } while (current != head);
}

//Displays all menu items of a specified type across all categories.
void Menu::filterItemsByType(char type) {
    type = toupper(type);
    bool found = false;
    cout << "Items of type " << type << " across all categories:" << endl;

    for (int i = 0; i < NUM_CATEGORIES; i++) {
        Node* head = categories[i];
        if (head != NULL) {
            Node* current = head;
            do {
                if (current->data.getType() == type) {
                    current->data.displayDetails();
                    found = true;
                }
                current = current->next;
            } while (current != head);
        }
    }

    if (!found) {
        cout << "No items found of type " << type << "." << endl;
    }
}

//Displays all vegetarian and vegan menu items across all categories.
void Menu::displayVeganVegetarianMenu() {
 filterItemsByType('V');
 filterItemsByType('G');
 }

//Displays menu items across all categories.
void Menu::traverseMenu(function<void(const menuItems &)> action) {
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        Node* head = categories[i];
        if (head) {
            Node* current = head;
            do {
                action(current->data);
                current = current->next;
            } while (current != head);
        }
    }
}
