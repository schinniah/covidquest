/**
 * @brief Keyboard class
 * @details Contains keyboard inputs and what they do
 * 
 * @author Suseela Chinniah
 */

/*
-----------------------------------------------------
 INCLUDES
-----------------------------------------------------
*/
#include "Keyboard.h"

/**
 * @brief Construct a new Keyboard:: Keyboard object
 * @details This is a constructor for a Keyboard object
 */
Keyboard::Keyboard() {}

/**
 * @brief Destroy the Keyboard:: Keyboard object
 * @details This is a destructor for a Keyboard object
 */
Keyboard::~Keyboard() {}

/**
 * @brief Up
 * @details If the keyboard input is up, return true. Otherwise, return false
 * 
 * @param input 
 * @return true 
 * @return false 
 */
bool Keyboard::up(char input) {
    return(input == KEY_UP);
}

/**
 * @brief Down
 * @details If the keyboard input is down, return true. Otherwise, return false
 * 
 * @param input 
 * @return true 
 * @return false 
 */
bool Keyboard::down(char input) {
    return(input == KEY_DOWN);
}

/**
 * @brief Left
 * @details If the keyboard input is left, return true. Otherwise, return false
 * 
 * @param input 
 * @return true 
 * @return false 
 */
bool Keyboard::left(char input) {
    return(input == KEY_LEFT);
}

/**
 * @brief Right
 * @details If the keyboard input is right, return true. Otherwise, return false
 * 
 * @param input 
 * @return true 
 * @return false 
 */
bool Keyboard::right(char input) {
    return(input == KEY_RIGHT);
}

/**
 * @brief Inventory
 * @details If the keyboard input is inventory, return true. Otherwise, return false
 * 
 * @param input 
 * @return true 
 * @return false 
 */
bool Keyboard::inventory(char input) {
    return(input == KEY_INVENTORY);
}

/**
 * @brief Use
 * @details If the keyboard input is use, return true. Otherwise, return false
 * 
 * @param input 
 * @return true 
 * @return false 
 */
bool Keyboard::use(char input) {
    return(input == KEY_USE);
}

