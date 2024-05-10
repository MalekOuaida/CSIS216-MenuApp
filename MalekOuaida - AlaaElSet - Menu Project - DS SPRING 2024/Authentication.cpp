//
//  Authentication.cpp
//  MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024
//
//  Created by Malek Ouaida on 21/04/2024.
//

#include "Authentication.hpp"

//admin logs in the account
bool authentication::adminLogin(const string &adminPassword){
    return verifyPassword(adminPassword);
}

