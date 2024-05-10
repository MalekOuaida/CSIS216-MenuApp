//
//  Orders.cpp
//  MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024
//
//  Created by Malek Ouaida on 21/04/2024.
//

#include "Orders.hpp"
#include "menuItems.hpp"
#include "Menu.hpp"
#include "specialOffers.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Constructs an OrderItems object with the specified menu item and quantity.
Order::OrderItems::OrderItems(const menuItems& item, int quantity) : item(item), quantity(quantity) {}


// Constructs an Order object.
// Initializes the order vector with a capacity of 8.
Order::Order() {
    order = vector<OrderItems>();
}

// Destructor for the Order class.
Order::~Order() {
    order.clear();
}

// Adds a menu item to the order with the specified quantity.
void Order::addOrder(menuItems& item, int quantity) {
    OrderItems newOrder(item, quantity);
    order.push_back(newOrder);
}

// Removes a menu item from the order.
void Order::removeOrder(menuItems& item) {
    auto it = remove_if(order.begin(), order.end(), [&](const OrderItems& oi) { return oi.item.getId() == item.getId(); });
    order.erase(it, order.end());
}

// Modifies an existing order item with a new menu item and quantity.
void Order::modifyOrder(menuItems& oldItem, menuItems& newItem, int newQuantity) {

    auto it = find_if(order.begin(), order.end(), [&](const OrderItems& oi) { return oi.item.getId() == oldItem.getId(); });
    if (it != order.end()) {
        it->item = newItem;  // Update the item reference (make sure newItem exists as long as Order exists)
        it->quantity = newQuantity;
    }

}

// Adds a special offer to the order with the specified quantity.
void Order::addOffer(specialOffers& offers, int quantity) {
    const vector<specialOffers::Offer>& offerItems = offers.getOffers();

    for (int i = 0; i < offerItems.size(); i++) {
            int itemId = offerItems[i].itemId;
            int offerQuantity = offerItems[i].quantity;

        menuItems* menuItem = menu.findItemById(itemId);
        if (!menuItem) {
            cout << "Item with ID " << itemId << " not found." << endl;
            continue;
        }

        string itemName = menuItem->getName();
        cout << "Insufficient quantity of " << itemName << " in the offer." << endl;
        cout << "Available quantity: " << offerQuantity << endl;
        cout << "Do you want to order the available quantity from this item? (y/n): ";
        char choice;
        cin >> choice;
        if (tolower(choice) == 'y') {
            if (offerQuantity < quantity) {
                addOrder(*menuItem, offerQuantity);
                offers.updateOffer(itemId, offerQuantity);
            } else {
                addOrder(*menuItem, quantity);
                offers.updateOffer(itemId, quantity);
            }
        }
    }
}

// Displays the bill for the order, including details of each item and the total cost.
void Order::displayBill() {
    double total = 0;
    cout << "Order Bill:" << endl;
    for (const auto& oi : order) {
        double lineTotal = oi.quantity * oi.item.getPrice();
        total += lineTotal;
        cout << oi.item.getId() << " " << oi.item.getName() << "\t" << oi.quantity << "\t" << oi.item.getPrice() << "\t$" << lineTotal << endl;
    }
    cout << "Total: $" << total << endl;
}

//Returns true if the order is empty.
bool Order::isEmpty() const {
    return order.empty();
}


