/**
 * @brief Protagonist class
 * @details Class file for Protagonist object
 * @author 
 */

/*
-----------------------------------------------------
 INCLUDES
-----------------------------------------------------
*/
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Protagonist.h"

using namespace std;

/**
 * @brief Construct a new Protagonist:: Protagonist object
 * @details Protagonist's default status is: health(100), speed(1), location(1,1)
 *
 * @author
 */
Protagonist::Protagonist(){
	health = 100;
	speed = 1;
	tuple<int, int> loc = tuple<int, int>{1, 1};
	location = loc;
}

/**
 * @brief Construct a new Protagonist:: Protagonist object
 * @details Set Protagonist with given health, inventory, speed and location
 * 
 * @param health 
 * @param inventory 
 * @param speed 
 * @param location 
 * 
 * @author 
 */
Protagonist::Protagonist(int health, vector<Item> inventory, int speed, tuple<int, int> location)
{
	SetProtagonist(health, inventory, speed, location);
}

/**
 * @brief Setter funtion
 * @details Assigns member to Protagonist object
 * 
 * @param phealth 
 * @param pinventory 
 * @param pspeed 
 * @param plocation 
 * 
 * @author 
 */
void Protagonist::SetProtagonist(int phealth, vector<Item> pinventory, int pspeed, tuple<int, int> plocation)
{
	health = phealth;
	inventory = pinventory;
	speed = pspeed;
	location = plocation;
}

/**
 * @brief Getter Function
 * @details Get health of the protagonist
 * 
 * @return int 
 * 
 * @author 
 */
int Protagonist::getHealth() { return health; }

/**
 * @brief Getter function
 * @details Get speed of the protagonist
 * 
 * @return int 
 * 
 * @author 
 */
int Protagonist::getSpeed() { return speed; }

/**
 * @brief Getter function
 * @details Get location of the protagonist
 * 
 * @return tuple<int, int> 
 * 
 * @author 
 */
tuple<int, int> Protagonist::getLocation() { return location; }

/**
 * @brief Getter function
 * @details Get a list(vector) of inventory the protagonist owns
 * 
 * @return vector<Item> 
 * 
 * @author
 */
vector<Item> Protagonist::getInventory() { return inventory; }

/**
 * @brief Setter function
 * @details Set the health of the protagonist
 * 
 * @param newHealth 
 * 
 * @author
 */
void Protagonist::setHealth(int newHealth) { health = newHealth; }

/**
 * @brief Getter function
 * @details Get the speed of the protagonist
 * 
 * @param newSpeed 
 * 
 * @author 
 */
void Protagonist::setSpeed(int newSpeed) { speed = newSpeed; }

/**
 * @brief Setter function
 * @details Set the location of the protagonist
 * 
 * @param newLocation 
 * 
 * @author 
 */
void Protagonist::setLocation(tuple<int, int> newLocation) { location = newLocation; }

/**
 * @brief Setter function
 * @details Set the inventory of the protagonist
 * 
 * @param newInventory 
 * 
 * @author 
 */
void Protagonist::setInventory(vector<Item> newInventory) { inventory = newInventory; }

/**
 * @brief Equip an item
 * @details Find the index of the item and push the item to inventory
 * 
 * @param item
 * 
 * @author Lucas Fraulin 
 */
void Protagonist::equip(Item item){
	int index = findItemIndex(item);
	inventory.at(index).equipItem();
}

/**
 * @brief Find item index
 * @details find the index of an item inside inventory vector, returns -1 if not found
 * 
 * @param item 
 * @return int 
 * 
 * @author Lucas Fraulin
 */
int Protagonist::findItemIndex(Item item){
	for (int i = 0; i < inventory.size(); i++){
		if(item.getItemName() == inventory.at(i).getItemName()){
			return i;
		} else {
			continue;
		}
	}
	return -1; //not found
}

/**
 * @brief Destroy the Protagonist:: Protagonist object
 * @details This is the destructor of the Protagonist object
 * 
 * @author 
 */
Protagonist::~Protagonist() { }

