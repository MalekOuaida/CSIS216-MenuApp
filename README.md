# Menu System

This project is a menu system developed for Hamido's restaurant, allowing both clients and admins to interact with the menu, place orders, and manage special offers.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [File Structure](#file-structure)
- [Dependencies](#dependencies)
- [Usage](#usage)
- [Contributors](#contributors)
- [License](#license)

## Introduction

Hamido's Menu System is a software application developed as part of the DS Spring 2024 project by Malek Ouaida and AlaaElSet. It provides a user-friendly interface for both clients and administrators to interact with the restaurant's menu and place orders. The system also includes functionality for managing special offers to enhance customer experience.

## Features

- **Client Interface**: Clients can view the menu, place orders, modify orders, remove orders, and view the bill.
- **Admin Interface**: Administrators can view the menu, manage special offers, add items to the menu, remove items from the menu, and modify items in the menu.
- **Special Offers**: The system automatically generates special offers by randomly selecting items from each category and allows administrators to update offers as needed.
- **File Management**: Menu items are loaded from and saved to a file, allowing for easy management and persistence of data.

## File Structure

The project consists of the following files:

- `Authentication.hpp`: Header file for authentication functionality.
- `Orders.hpp`: Header file for order-related functionality.
- `Orders.cpp`: Implementation file for order-related functionality.
- `Menu.hpp`: Header file for menu-related functionality.
- `specialOffers.hpp`: Header file for special offers-related functionality.
- `specialOffers.cpp`: Implementation file for special offers-related functionality.
- `userInterface.hpp`: Header file for user interface functionality.
- `userInterface.cpp`: Implementation file for user interface functionality.
- `fileManager.hpp`: Header file for file management functionality.
- `fileManager.cpp`: Implementation file for file management functionality.
- `menuItems.hpp`: Header file for menu item class definition.
- `menuItems.cpp`: Implementation file for menu item class.
- `proj.txt`: Text file containing menu item data.
- `readMe.md`: Markdown file containing project documentation (this file).

## Dependencies

- C++ Standard Library
- `iostream`
- `vector`
- `algorithm`
- `random`

## Usage

To use the Hamido's Menu System:

1. Compile the source code files using a C++ compiler.
2. Run the compiled executable file.
3. Choose whether to log in as a client or an admin.
4. Follow the on-screen prompts to navigate the menu, place orders, manage special offers, and perform other actions.

## Contributors

- Malek Ouaida
- Alaa ElSet

## License

This project is licensed under the [GNU GENERAL PUBLIC LICENSE](LICENSE).
