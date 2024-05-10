//
//  menuItems.cpp
//  MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024
//
//  Created by Malek Ouaida on 21/04/2024.
//

#include "menuItems.hpp"
#include <iostream>
#include <cctype>
using namespace std;

// Static member initialization
int menuItems::lastAppetizerId = 100;
int menuItems::lastMainDishId = 200;
int menuItems::lastDessertId = 300;
int menuItems::lastBeverageId = 400;

// Default constructor
menuItems::menuItems(){}

// Parameterized constructor
menuItems::menuItems(string name, double price, char type, char category, string ingredients[], int numIngredients) {
    this->id = generateNextId(category);
    this->name = name;
    this->price = price;
    this->type = type;
    this->category = category;
    this->numIngredients = numIngredients;
    this->ingredients = new string[numIngredients];
    for (int i = 0; i < numIngredients; i++) {
        this->ingredients[i] = ingredients[i];
    }
}

// Copy constructor
menuItems::menuItems(const menuItems& other) {
    this->id = other.id;
    this->name = other.name;
    this->price = other.price;
    this->type = other.type;
    this->category = other.category;
    this->numIngredients = other.numIngredients;
    this->ingredients = new string[this->numIngredients];
    for (int i = 0; i < this->numIngredients; i++) {
        this->ingredients[i] = other.ingredients[i];
    }
}

// Destructor
menuItems::~menuItems(){
    delete[] ingredients;
}

//sets the name
void menuItems::setName(string newName){
    if (!newName.empty()) {
            name = newName;
        } else {
            cerr << "Error: Name cannot be empty." << endl;
    }
}

//sets the price
void menuItems::setPrice(double newPrice) {
    if (newPrice > 0) {
        price = newPrice;
    } else {
        cerr << "Error: Price must be positive." << endl;
    }
}

//sets the type
void menuItems::setType(char newType) {
    newType = toupper(newType);
    
    if (newType == 'V' || newType == 'G' || newType == 'N') {
        type = newType;
    } else {
        cerr << "Error: Invalid type. Must be 'V' (Vegan), 'G' (Vegetarian), or 'N' (Normal)." << endl;
    }
}

//sets the category
void menuItems::setCategory(char newCategory) {
    newCategory = toupper(newCategory);

    if (newCategory == 'A' || newCategory == 'M' || newCategory == 'D' || newCategory == 'B') {
        category = newCategory;
        this->id = generateNextId(category);
    } else {
       // cerr << "Error: Invalid category. Must be 'A' (Appetizers), 'M' (Main Dishes), 'D' (Desserts), or 'B' (Beverages)." << endl;
    }
}

//sets the ingredients
void menuItems::setIngredients(const string newIngredients[], int newNumIngredients) {
    delete[] ingredients;
    ingredients = new string[newNumIngredients];
    numIngredients = newNumIngredients;
    for (int i = 0; i < newNumIngredients; i++) {
        ingredients[i] = newIngredients[i];
    }
}

//returns the id
int menuItems::getId() const {
    return id;
}

//returns the name
string menuItems::getName() const{
    return name;
}

//returns the price
double menuItems::getPrice() const {
    return price;
}

//returns the type
char menuItems::getType() const {
    return type;
}

//returns the category
char menuItems::getCategory() const{
    return category;
}

//returns the ingredients
string* menuItems::getIngredients() const {
    return ingredients;
}

//retruns the number of ingredients
int menuItems::getNumIngredients() const {
    return numIngredients;
}

//generates the next ID
int menuItems::generateNextId(char category) {
    switch (category) {
        case 'A':
            return ++lastAppetizerId;
        case 'M':
            return ++lastMainDishId;
        case 'D':
            return ++lastDessertId;
        case 'B':
            return ++lastBeverageId;
        default:
            //cerr << "Invalid category" << endl;
            return 0;
    }
}

//displays all the details
void menuItems::displayDetails() const {
    cout << "ID: " << id << "\nName: " << name << "\nPrice: $" << price << "\nType: " << type
              << "\nCategory: " << category << "\nIngredients: ";
    for (int i = 0; i < numIngredients; i++) {
        cout << ingredients[i];
        if (i < numIngredients - 1) cout << ", ";
    }
    cout << endl;
}
