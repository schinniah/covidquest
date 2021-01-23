//Include guard to prevent multiple file inclusions
#ifndef PROTAGONIST_H
#define PROTAGONIST_H

#include <tuple>
#include <vector>

#include "Item.h"


//Class Protagonist for Covid-Quest
class Protagonist {
	//declaring the private parameters
	private:
		int health, speed;
		//board organized by coordinates
		std::tuple<int, int> location;
		//An array of Item objects
		std::vector<Item> inventory;
	public:
		//Protagonist constructor class
		Protagonist();
		Protagonist(int health, std::vector<Item> inventory, int speed, std::tuple<int, int> location);

		//Constructor member function
		void SetProtagonist(int health, std::vector<Item> inventory, int speed, std::tuple<int, int> location);

		//Getter functions
		int getHealth();
		int getSpeed();
		std::tuple<int, int> getLocation();
		std::vector<Item> getInventory();

		//Setter functions
		void setHealth(int newHealth);
		void setSpeed(int newSpeed);
		void setLocation(std::tuple<int, int> newLocation);
		void setInventory(std::vector<Item> newInventory);

		void equip(Item item);

		int findItemIndex(Item item);

		//This is the destructor
		~Protagonist();
};

#endif
