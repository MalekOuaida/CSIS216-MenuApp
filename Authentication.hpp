//
//  Authentication.hpp
//  MalekOuaida - AlaaElSet - Menu Project - DS SPRING 2024
//
//  Created by Malek Ouaida on 21/04/2024.
//

/*-- Authentication.hpp ---------------------------------------------------------
 This header file defines the data types authentication uses to authenticate the admin log in.
 Basic operations are:
 Constructors: initializes a new menu item object
 adminLogin: login for the admin
 verifyPassword: verifies the password
 ------------------------------------------------------------------------
 */

#ifndef Authentication_hpp
#define Authentication_hpp

#include <stdio.h>
#include <string>
using namespace std;

class authentication {
    /*** Function Members ***/
    /** Class Constructor **/
private:
    const string adminPassword = "ADMIN12345";  //Admin Password
public:
    authentication() {}
    /*-------------------------------------------------------------------
     Default constructor for the authentication class.
     Initializes member variables
     -------------------------------------------------------------------*/
    authentication(const string& password) : adminPassword(password) {}
    /*-------------------------------------------------------------------
     Parameterized constructor for the authentication class.
     Initializes the admin password with the specified value.
     -------------------------------------------------------------------*/
    
    bool adminLogin(const string& password);
    /*-------------------------------------------------------------------
     Logs in the admin with the provided password.
     
     Precondition: None.
     Postcondition: Returns true if the provided password matches the admin password, otherwise false.
     -------------------------------------------------------------------*/
    
    bool verifyPassword(const string& input) const {
        return input == adminPassword;
        /*-------------------------------------------------------------------
         Verifies if the provided input matches the admin password.
         
         Precondition: None.
         Postcondition: Returns true if the provided input matches the admin password, otherwise false.
         -------------------------------------------------------------------*/
    }
};
#endif /* Authentication_hpp */
