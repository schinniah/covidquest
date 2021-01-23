// Lucas Fraulin lfraulin@uwo.ca
// Header File for Item Object
// November 6, 2020
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

class Item {

    private:
        //data members
        std::string itemName;
        std::string itemType;
        int upgradeQuantity;
        bool equipped;
        std::string textureFilename;
        std::tuple<int, int> location;


    public:
        //constructor
        Item(std::string itemName, std::string itemType, std::string textureFilename, int upgradeQuantity);
        Item(std::string itemName, std::string itemType, std::string textureFilename, int upgradeQuantity, int randseed);
        
        //destructor
        ~Item();    

        //getters
        std::string getItemName();
        std::string getItemType();
        std::string getTextureFilename();
        int getUpgradeQuantity();
        bool isEquipped();
        std::tuple<int, int> getLocation();

        //setters
        void setItemName(std::string str);
        void setItemType(std::string str);
        void setTextureFilename(std::string str);
        void setUpgradeQuantity(int quant);
        void equipItem();
        void setLocation(std::tuple<int, int> loc);

};
#endif