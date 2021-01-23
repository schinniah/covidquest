/**
 * @brief Bot Class
 * @details Create a bot that contains name, type, location, start, end, damage and delay
 * @authors Yurim Kang, Lucas Fraulin
 */

using namespace std;

/*
-----------------------------------------------------
 INCLUDES
-----------------------------------------------------
*/
#include "Bot.h"

/**
 * @brief Construct a new Bot:: Bot object
 * @details Construct a new Bot object that contains these attributes: name, botType, botLocation, start, end, dam, delay
 * 
 * @param name 
 * @param botType 
 * @param botLocation 
 * @param start 
 * @param end 
 * @param dam 
 * @param delay
 * 
 * @authors Yurim Kang, Lucas Fraulin
 */
Bot::Bot(string name, string botType, std::tuple<int, int> botLocation, tuple<int, int> start, tuple<int, int> end, int dam, double delay){
    setBot(name, botType, botLocation, start, end, dam, delay);
}

/**
 * @brief Setter function for a Bot object
 * @details Set name, type, location, starting coordination, ending coordination, damage, delay time of a Bot
 * 
 * @param bname 
 * @param bType 
 * @param bLocation 
 * @param start 
 * @param end 
 * @param dam 
 * @param delayinms
 * 
 * @return void 
 * 
 * @authors Yurim Kang, Lucas Fraulin
 */
void Bot::setBot(string bname, string bType, tuple<int, int> bLocation, tuple<int, int> start, tuple<int, int> end, int dam, double delayinms){
    name = bname;
    botType = bType;
    botLocation = bLocation;
    startRoute = start;
    endRoute = end;
    damage = dam;
    delay = delayinms;
}

/**
 * @brief Getter function for Bot
 * @details Get name of a Bot
 * 
 * @return string
 * 
 * @author Yurim Kang
 */
string Bot::getName() {return name;}

/**
 * @brief Getter function for Bot
 * @details Get type of a Bot
 * 
 * @return string 
 * 
 * @author Yurim Kang
 */
string Bot::getType() {return botType;}

/**
 * @brief Getter function for Bot
 * @details Get the location of a Bot
 * 
 * @return tuple<int, int> 
 * 
 * @author Yurim Kang
 */
tuple<int, int> Bot::getLocation() {return botLocation;}

/**
 * @brief Getter function for Bot
 * @details Get the starting coordination of the Bot on a map
 * 
 * @return tuple<int, int> 
 * 
 * @author Lucas Fraulin
 */
tuple<int, int> Bot::getStartRoute(){return startRoute;}

/**
 * @brief Getter function for Bot
 * @details Get the ending coordination of the Bot on a map
 * 
 * @return tuple<int, int>
 * 
 * @author Lucas Fraulin 
 */
tuple<int, int> Bot::getEndRoute(){return endRoute;}

/**
 * @brief Getter function for Bot
 * @details Get the damage caused by the Bot when the protagonist is near
 * 
 * @return int
 * 
 * @author Lucas Fraulin
 */
int Bot::getDamage(){return damage;}

/**
 * @brief Getter function for Bot
 * @details Get the delay time of a Bot
 * 
 * @return double 
 * 
 * @author Lucas Fraulin
 */
double Bot::getDelay(){return delay;}
bool Bot::getSwitchDirection() {return switchDirection;}
int Bot::getXMoveValue() { return xMoveValue;}
int Bot::getYMoveValue() {return yMoveValue;}

/**
 * @brief Setter function for Bot
 * @details Set the name of a Bot
 * 
 * @param bname 
 * 
 * @author Yurim Kang
 */
void Bot::setName(string bname){name = bname;}

/**
 * @brief Setter function for Bot
 * @details Set the type of a Bot
 * 
 * @param newType 
 * 
 * @author Yurim Kang
 */
void Bot::setType(string newType) {botType = newType;}

/**
 * @brief Setter function for Bot
 * @details Set the location of a Bot
 * 
 * @param newLocation
 * 
 * @author Yurim Kang 
 */
void Bot::setLocation(std::tuple<int, int> newLocation) {botLocation = newLocation;}

/**
 * @brief Setter function for Bot
 * @details Set the damage caused by the Bot when the Protagonist is near
 * 
 * @param damage 
 * 
 * @author Lucas Fraulin
 */
void Bot::setDamage(int damage){damage = damage;}

/**
 * @brief Setter function for Bot
 * @details Set the delay time of the Bot in m/s
 * 
 * @param delayinms 
 * 
 * @author Lucas Fraulin
 */
void Bot::setDelay(double delayinms){delay = delayinms;}
void Bot::setXMoveValue(int x) {xMoveValue = x;}
void Bot::setYMoveValue(int y) {yMoveValue = y;}

/**
 * @brief Setter function
 * @details Set a route for the Bot using coordinations
 * 
 * @param start 
 * @param end 
 * 
 * @author Lucas Fraulin
 */
void Bot::setRoute(tuple<int, int> start, tuple<int, int> end){
    startRoute = start;
    endRoute = end;
}

void Bot::setSwitchDirection(bool value) {
    switchDirection = value;
}

//This is the destructor
/**
 * @brief Destroy the Bot:: Bot object
 * @details This is the destructor for the Bot object
 * 
 * @author Yurim Kang
 */
Bot::~Bot() { }

/*
    Level 1 = 1 lvl1 bot
    level 2 = 1 lvl2 bot
    level 3 = 1 lvl3 bot
    level 4 = 2 lvl1 bots
    level 5 = 1 lvl1 + 1lvl2 bots
    level 6 = 2 lvl2 bots
    level 7 = 1 lvl1 + 1 lvl3 bot
    level 8 = 1 lvl2 + 1 lvl3 bot
    level 9 = 2 lvl3 bots
    level 10 = 1 lvl1 + 1 lvl2 + 1 lvl3 bots
 */
