#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>

#include "Bot.h"
#include "Item.h"

class Level {
    private:
        std::vector<Bot> bots;
        std::vector<Item> items;
        int level;

    public:
        //constructors
        Level();
        Level(int level);

        //getters
        std::vector<Bot> getBots();
        std::vector<Item> getItems();
        
        //setters
        void setBots(std::vector<Bot> bots);
        void setItems(std::vector<Item> items);

        Item findItem(std::string name);

        //destructor
        ~Level();
};

#endif