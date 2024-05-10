//
//  fileManager.cpp
//  MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024
//
//  Created by Malek Ouaida on 21/04/2024.
//

#include "fileManager.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "menuItems.hpp"

// Writes the menu items to a file
void fileManager::writeMenuToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    menu.traverseMenu([&file](const menuItems& item) {
        file << item.getName() << "," << item.getType() << "," << item.getCategory() << ","
             << item.getPrice();
        const string* ingredients = item.getIngredients();
        for (int i = 0; i < item.getNumIngredients(); i++) {
            file << (i == 0 ? "," : ",") << ingredients[i];
        }
        file << endl;
    });

    file.close();
}

// Loads menu items from a file
void fileManager::loadMenuFromFile(const string &filename, Menu &menu) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string token;
        vector<string> tokens;

        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 5) {
            cerr << "Invalid line, skipping: " << line << endl;
            continue;
        }

        string name = tokens[0];
        char type = toupper(tokens[1][0]);
        char category = toupper(tokens[2][0]);//a m b d
        double price = atof(tokens[3].c_str());
        vector<string> ingredients(tokens.begin() + 4, tokens.end());

        // Assuming menuItems constructor takes these parameters.
        menuItems newItem(name, price, type, category, ingredients.data(), ingredients.size());
        menu.addItem(newItem);
    }
    file.close();
}

// Constructor for fileManager class
fileManager::fileManager(Menu& men):menu(men) {}

