//
//  specialOffers.cpp
//  MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024
//
//  Created by Malek Ouaida on 21/04/2024.
//

#include "specialOffers.hpp"
#include "Menu.hpp"
#include <iostream>
#include <algorithm>
#include <random>

// The discount rate for special offers.
const double specialOffers::DISCOUNT_RATE = 0.70;


// Initializes a new specialOffers object.
// Reserves memory for up to 8 special offers and initializes them.
specialOffers::specialOffers(Menu& menuRef) : menu(menuRef) {
    initializeOffers();
}


// Initializes special offers by randomly selecting items from each category.
void specialOffers::initializeOffers() {
    const vector<char> categories = {'A', 'M', 'D', 'B'};
    for (char category : categories) {
        for (int i = 0; i < 2; ++i) {
            int itemId = getRandomItemId(category);
            if (itemId != -1) {
                addOffer(itemId, getRandomQuantity());
            }
        }
    }
}

// Adds a special offer for an item with a given ID and quantity.
// If the maximum number of offers is reached, the offer is not added.
void specialOffers::addOffer(int itemId, int quantity) {
    if (offers.size() < 8) {
        offers.push_back(Offer(itemId, quantity));
    }
}

// Updates the quantity of a special offer after an item is sold.
// If the quantity becomes zero or negative, the offer is replaced.
void specialOffers::updateOffer(int itemId, int soldQuantity) {
    for (int i = 0; i < offers.size(); ++i) {
        if (offers[i].itemId == itemId) {
            offers[i].quantity -= soldQuantity;
            if (offers[i].quantity <= 0) {
                replaceOffer(i);
            }
            return;
        }
    }

}

// Replaces a special offer with a new randomly selected item and quantity.
void specialOffers::replaceOffer(int index) {
    char category = getItemCategory(offers[index].itemId);
    int newItemId = getRandomItemId(category);
    int newQuantity = getRandomQuantity();

    offers[index].itemId = newItemId;
    offers[index].quantity = newQuantity;
}


// Displays all special offers, including item ID, quantity, and discounted price.
void specialOffers::displayOffers() const {
    if (offers.empty()) {
        cout << "No offers available." << endl;
        return;
    }

    for (const Offer& offer : offers) {
        double discountedPrice = calculateDiscountPrice(offer.itemId);
        cout << "Item ID: " << offer.itemId
             << ", Quantity: " << offer.quantity
             << ", Discounted Price: $" << discountedPrice
             << endl;
    }
}


// Generates a random item ID within a given category.
int specialOffers::getRandomItemId(char category) {
    vector<int> availableIds;
    menu.traverseMenu([&availableIds, category](const menuItems &item) {
        if (item.getCategory() == category) {
            availableIds.push_back(item.getId());
        }
    });

    if (!availableIds.empty()) {
        int randomIndex = rand() % availableIds.size();
        return availableIds[randomIndex];
    }
    return -1; // or handle no available item case appropriately
}

// Checks if an item with a given ID is included in the special offers.
bool specialOffers::isSpecialOfferItem(int itemId){
    for(int i = 0; i < offers.size(); i++){
        if(offers[i].itemId == itemId)
            return true;
    }
    return false;
}

// Generates a random quantity for a special offer.
int specialOffers::getRandomQuantity() {
    return 3 + rand() % 8;
}

// Determines the category of an item based on its ID.
char specialOffers::getItemCategory(int itemId) {
    if (itemId >= 100 && itemId <= 199) return 'A';
    else if (itemId >= 200 && itemId <= 299) return 'M';
    else if (itemId >= 300 && itemId <= 399) return 'D';
    else if (itemId >= 400 && itemId <= 499) return 'B';
    return 'X';
}

// Retrieves the price of an item with a given ID.
double specialOffers::getItemPrice(int itemId) const {

    menuItems* item = menu.findItemById(itemId);
    if (item) {
        return item->getPrice();
    } else {
        cerr << "Error: Item ID " << itemId << " not found in menu." << endl;
        return 0.0; 
    }
}

// Retrieves a constant reference to the vector of special offers.
const vector<specialOffers::Offer>& specialOffers::getOffers() const {
    return offers;
}

//Calculates the price after the discount.
double specialOffers::calculateDiscountPrice(int itemId) const {
    double originalPrice = getItemPrice(itemId);
    return originalPrice * DISCOUNT_RATE;
}


