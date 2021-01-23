/**
 * @brief Level class
 * @details Level class for different levels in the game
 * 
 * @author Lucas Fraulin
 */

/*
-----------------------------------------------------
 INCLUDES
-----------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Level.h"

using namespace std;

Level::Level() {}

/**
 * @brief Construct a new Level:: Level object
 * @details Each level gets different items and enemies
 * 
 * @param lvl 
 */
Level::Level(int lvl){
    int x, y;
    level = lvl;
    tuple<int, int> loc1, loc2, loc3;
    switch(lvl){
        case 1: //1 lvl1 bot
            srand(0);
            x = rand() % 816;
            srand(1);
            y = rand() % 624;
            loc1 = tuple<int, int>{480, 144};
            loc2 = tuple<int, int>{720, 288};

            bots.push_back(Bot("bot1","level1", loc1, loc1, loc2, 20, 1000));

            //2 items 
            items.push_back(Item("mask", "health", "images/mask.png", 20, 100));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10,101));

            break;
        case 2: // level 2 = 1 lvl2 bot
            srand(2);
            x = rand() % 816;
            srand(3);
            y = rand() % 624;
            loc1 = tuple<int, int>{x, y};

            bots.push_back(Bot("bot1","level2", loc1, loc1, loc1, 30, 750));

            //3 items
            items.push_back(Item("sanitizer", "health", "images/sanitizer.png", 20.102));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1,103));
            items.push_back(Item("toiletpaper", "null", "images/toilet-paper.png", 0,104));

            break;
        case 3: // level 3 = 1 lvl3 bot
            srand(4);
            x = rand() % 816;
            srand(5);
            y = rand() % 624;
            loc1 = tuple<int, int>{x, y};

            bots.push_back(Bot("bot1","level3", loc1, loc1, loc1, 40, 500));

            //4 items
            items.push_back(Item("mask", "health", "images/mask.png", 20,201));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1,202));
            items.push_back(Item("vaccine", "health", "images/vaccine.png", 50,203));
            items.push_back(Item("toiletpaper", "null", "images/toilet-paper.png", 0, 204));

            break;
        case 4: // level 4 = 2 lvl1 bots
            srand(6);
            x = rand() % 816;
            srand(7);
            y = rand() % 624;
            loc1 = tuple<int, int>{x, y};

            bots.push_back(Bot("bot1","level1", loc1, loc1, loc1, 20, 1000));

            srand(8);
            x = rand() % 816;
            srand(9);
            y = rand() % 624;
            loc2 = tuple<int, int>{x, y};

            bots.push_back(Bot("bot2","level1", loc2, loc2, loc2, 20, 1000));
            
            //5 items
            items.push_back(Item("sanitizer", "health", "images/sanitizer.png", 20, 301));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1, 302));
            items.push_back(Item("mask", "health", "images/mask.png", 20, 303));
            items.push_back(Item("toiletpaper", "null", "images/toilet-paper.png", 0, 304));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10, 305));

            break;
        case 5: // level 5 = 1 lvl1 + 1lvl2 bots
            srand(10);
            x = rand() % 816;
            srand(11);
            y = rand() % 624;
            loc1 = tuple<int, int>{x, y};
            
            bots.push_back(Bot("bot1","level1", loc1, loc1, loc1, 20, 1000));

            srand(12);
            x = rand() % 816;
            srand(13);
            y = rand() % 624;
            loc2 = tuple<int, int>{x, y};

            bots.push_back(Bot("bot2","level2", loc2, loc2, loc2, 30, 750));

            //6 items
            items.push_back(Item("sanitizer", "health", "images/sanitizer.png", 20, 306));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1, 307));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10, 308));
            items.push_back(Item("mask", "health", "images/mask.png", 20, 309));
            items.push_back(Item("toiletpaper", "null", "images/toilet-paper.png", 0, 310));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10, 211));

            break;
        case 6: // level 6 = 2 lvl2 bots
            srand(14);
            x = rand() % 816;
            srand(15);
            y = rand() % 624;
            loc1 = tuple<int, int>{x, y};

            bots.push_back(Bot("bot1","level2", loc1, loc1, loc1, 30, 750));

            srand(16);
            x = rand() % 816;
            srand(17);
            y = rand() % 624;
            loc2 = tuple<int, int>{x, y};

            bots.push_back(Bot("bot2","level2", loc2, loc2, loc2, 30, 750));

            //7 items
            items.push_back(Item("sanitizer", "health", "images/sanitizer.png", 20,401));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1, 402));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10, 403));
            items.push_back(Item("mask", "health", "images/mask.png", 20, 404));
            items.push_back(Item("toiletpaper", "null", "images/toilet-paper.png", 0, 405));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10, 406));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1, 407));

            break;
        case 7: // level 7 = 1 lvl1 + 1 lvl3 bot
            srand(18);
            x = rand() % 816;
            srand(19);
            y = rand() % 624;
            loc1 = tuple<int, int>{x, y};

            bots.push_back(Bot("bot1","level1", loc1, loc1, loc1, 20, 1000));

            srand(20);
            x = rand() % 816;
            srand(21);
            y = rand() % 624;
            loc2 = tuple<int, int>{x, y};

            bots.push_back(Bot("bot2","level3", loc2, loc2, loc2, 40, 500));

            //8 items
            items.push_back(Item("sanitizer", "health", "images/sanitizer.png", 20, 408));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1, 409));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10, 410));
            items.push_back(Item("mask", "health", "images/mask.png", 20, 410));
            items.push_back(Item("toiletpaper", "null", "images/toilet-paper.png", 0, 411));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10, 412));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1, 413));
            items.push_back(Item("vaccine", "health", "images/vaccine.png", 50, 414));

            break;
        case 8: // level 8 = 1 lvl2 + 1 lvl3 bot
            srand(22);
            x = rand() % 816;
            srand(23);
            y = rand() % 624;
            loc1 = tuple<int, int>{x, y};

            bots.push_back(Bot("bot1","level2", loc1, loc1, loc1, 30, 750));

            srand(24);
            x = rand() % 816;
            srand(25);
            y = rand() % 624;
            loc2 = tuple<int, int>{x, y};

            bots.push_back(Bot("bot2","level3", loc2, loc2, loc2, 40, 500));

            //9 items
            items.push_back(Item("sanitizer", "health", "images/sanitizer.png", 20,501));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1,502));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10,503));
            items.push_back(Item("mask", "health", "images/mask.png", 20,504));
            items.push_back(Item("toiletpaper", "null", "images/toilet-paper.png", 0,505));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10,506));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1,507));
            items.push_back(Item("vaccine", "health", "images/vaccine.png", 50,508));
            items.push_back(Item("toiletpaper", "null", "images/toilet-paper.png", 0,509));

            break;
        case 9: // level 9 = 2 lvl3 bots
            srand(26);
            x = rand() % 816;
            srand(27);
            y = rand() % 624;
            loc1 = tuple<int, int>{x, y};

            bots.push_back(Bot("bot1","level3", loc1, loc1, loc1, 40, 500));

            srand(28);
            x = rand() % 816;
            srand(29);
            y = rand() % 624;
            loc2 = tuple<int, int>{x, y};

            
            bots.push_back(Bot("bot2","level3", loc2, loc2, loc2, 40, 500)); 

            //10 items
            items.push_back(Item("sanitizer", "health", "images/sanitizer.png", 20,601));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1,602));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10,603));
            items.push_back(Item("mask", "health", "images/mask.png", 20,604));
            items.push_back(Item("toiletpaper", "null", "images/toilet-paper.png", 0,605));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10,606));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1,607));
            items.push_back(Item("vaccine", "health", "images/vaccine.png", 50,608));
            items.push_back(Item("toiletpaper", "null", "images/toilet-paper.png", 0,609));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10,610));
            

            break;
        case 10: // level 10 = 1 lvl1 + 1 lvl2 + 1 lvl3 bots
            srand(30);
            x = rand() % 816;
            srand(31);
            y = rand() % 624;

            loc1 = tuple<int, int>{x, y};

            bots.push_back(Bot("bot1","level1", loc1, loc1, loc1, 20, 1000));

            srand(32);
            x = rand() % 816;
            srand(33);
            y = rand() % 624;

            loc2 = tuple<int, int>{x, y};

            bots.push_back(Bot("bot2","level2", loc2, loc2, loc2, 30, 750));

            srand(34);
            x = rand() % 816;
            srand(35);
            y = rand() % 624;

            loc3 = tuple<int, int>{x, y};

            bots.push_back(Bot("bot3","level3", loc3, loc3, loc3, 40, 500));

            //15 items
            items.push_back(Item("sanitizer", "health", "images/sanitizer.png", 20,701));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1,702));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10,703));
            items.push_back(Item("mask", "health", "images/mask.png", 20,704));
            items.push_back(Item("toiletpaper", "null", "images/toilet-paper.png", 0,705));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10,706));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1,707));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1,708));
            items.push_back(Item("vaccine", "health", "images/vaccine.png", 50,709));
            items.push_back(Item("toiletpaper", "null", "images/toilet-paper.png", 0,710));
            items.push_back(Item("gloves", "health", "images/gloves.png", 10,711));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1,712));
            items.push_back(Item("energybar", "speed", "images/energy-bar.png", 1,713));
            items.push_back(Item("toiletpaper", "null", "images/toilet-paper.png", 0,714));
            items.push_back(Item("sanitizer", "health", "images/sanitizer.png", 20,715));
            break;
        default:
            break;
    }
    
}

/**
 * @brief Getter Function
 * @details Get a list(vector) of bots
 * 
 * @return vector<Bot> 
 */
vector<Bot> Level::getBots(){ return bots; }

/**
 * @brief Getter Function
 * @details Get a list(vector) of items
 * 
 * @return vector<Item> 
 */
vector<Item> Level::getItems(){ return items; }

/**
 * @brief Setter Function
 * @details Set new bots
 * 
 * @param newbots 
 */
void Level::setBots(vector<Bot> newbots){ bots = newbots; }

/**
 * @brief Setter function
 * @details Set new items
 * 
 * @param newitems 
 */
void Level::setItems(vector<Item> newitems){ items = newitems; }

    // Level 1 = 1 lvl1 bot
    // level 2 = 1 lvl2 bot
    // level 3 = 1 lvl3 bot
    // level 4 = 2 lvl1 bots
    // level 5 = 1 lvl1 + 1lvl2 bots
    // level 6 = 2 lvl2 bots
    // level 7 = 1 lvl1 + 1 lvl3 bot
    // level 8 = 1 lvl2 + 1 lvl3 bot
    // level 9 = 2 lvl3 bots
    // level 10 = 1 lvl1 + 1 lvl2 + 1 lvl3 bots

Item Level::findItem(string name){
    for(int i = 0; i < items.size(); i++){
        if (name == items.at(i).getItemName()){
            return items.at(i);
        }
    }
}

/**
 * @brief Destroy the Level:: Level object
 * @details This is a destructor for the Level object
 */
Level::~Level(){ }