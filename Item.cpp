/**
 * @brief Item class
 * @details Class file for Item object
 * @author Lucas Fraulin
 */

/*
-----------------------------------------------------
 INCLUDES
-----------------------------------------------------
*/
#include <string> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <tuple>
#include "Item.h"

using namespace std;

/**
 * @brief Construct a new Item:: Item object
 * @details This is a contructor for an Item object. It contains the name, type, file name and an integer that upgrades quantity
 * 
 * @param name 
 * @param type 
 * @param filename 
 * @param upQuant 
 */
Item::Item(string name, string type, string filename, int upQuant){
    itemName = name;
    itemType = type;
    upgradeQuantity = upQuant;
    equipped = false;
    textureFilename = filename;
}

/**
 * @brief Construct a new Item:: Item object
 * @details This is another constructor for an Item object that contains the name, type, file name, an integer that checks upgrade in quantity and random seed
 * 
 * @param name 
 * @param type 
 * @param filename 
 * @param upQuant 
 * @param rseed 
 */
Item::Item(string name, string type, string filename, int upQuant, int rseed){
    itemName = name;
    itemType = type;
    upgradeQuantity = upQuant;
    equipped = false;
    textureFilename = filename;

    int x, y;
    srand(rseed);
    x = rand() % 816;
    srand(rseed+1);
    y = rand() % 624;

    location = tuple<int, int>{x,y};
}

/**
 * @brief Destroy the Item:: Item object
 * @details This is the destructor for the Item object
 */
Item::~Item(){}

/**
 * @brief Getter function
 * @details Get the name of the item
 * 
 * @return string 
 */
string Item::getItemName(){return itemName;}

/**
 * @brief Getter function
 * @details Get the type of the item
 * 
 * @return string 
 */
string Item::getItemType(){return itemType;}

/**
 * @brief Getter function
 * @details Get the upgrade quantity
 * 
 * @return int 
 */
int Item::getUpgradeQuantity(){return upgradeQuantity;}

/**
 * @brief Getter function
 * @details Get whether any items are equipped or not
 * 
 * @return true 
 * @return false 
 */
bool Item::isEquipped(){return equipped;}

/**
 * @brief Getter function
 * @details Get the texture file name
 * 
 * @return string 
 */
string Item::getTextureFilename() {return textureFilename;}

/**
 * @brief Getter function
 * @details Get the location
 * 
 * @return tuple<int, int> 
 */
tuple<int, int> Item::getLocation(){ return location;}

/**
 * @brief Setter function
 * @details Set the name of the item
 * 
 * @param str 
 */
void Item::setItemName(string str){itemName = str;}

/**
 * @brief Setter funciton
 * @details Set the type of an item
 * 
 * @param str 
 */
void Item::setItemType(string str){itemType = str;}

/**
 * @brief Setter function
 * @details Set the texture file name
 * 
 * @param str 
 */
void Item::setTextureFilename(string str) {textureFilename = str;}

/**
 * @brief Setter Function
 * @details Set the upgrade quantity
 * 
 * @param quant 
 */
void Item::setUpgradeQuantity(int quant){upgradeQuantity = quant;}

/**
 * @brief Equip item
 * @details Equip item and change the status to equipped
 */
void Item::equipItem(){equipped = !equipped;}

/**
 * @brief Setter function
 * @details Set the location of an item
 * 
 * @param loc 
 */
void Item::setLocation(tuple<int, int> loc){location = loc;}
