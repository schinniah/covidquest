/**
 * @brief Bot Class
 * @details Create a bot that contains name, type, location, start, end, damage and delay
 * @authors Yurim Kang, Lucas Fraulin
 */

#ifndef BOT_H
#define BOT_H

using namespace std;

/*
-----------------------------------------------------
 INCLUDES
-----------------------------------------------------
*/
#include <tuple>
#include <string>

/*
-----------------------------------------------------
DECLARATIONS
-----------------------------------------------------
*/
class Bot{
    private:
        string name;
        string botType;
        std::tuple<int, int> botLocation;
        std::tuple<int, int> startRoute;
        std::tuple<int, int> endRoute;
        int damage;
        double delay;
        int xMoveValue;
        int yMoveValue;
        bool switchDirection;
        
    public:
        //Bot constructor class
        Bot(string name, string botType, std::tuple<int, int> botLocation, std::tuple<int, int> startRoute, std::tuple<int, int> endRoute, int damage, double delay);

        void setBot(string name, string botType, std::tuple<int, int> botLocation, std::tuple<int, int> startRoute, std::tuple<int, int> endRoute, int damage, double delay);

        //Getter functions
        string getName();
        string getType();
        std::tuple<int, int> getLocation();
        std::tuple<int, int> getStartRoute();
        std::tuple<int, int> getEndRoute();
        int getDamage();
        double getDelay();
        bool getSwitchDirection();
        int getXMoveValue();
        int getYMoveValue();

        //Setter functions
        void setName(string name);
        void setType(string newType);
        void setLocation(std::tuple<int, int> newLocation);
        void setRoute(std::tuple<int, int> start, std::tuple<int, int> end);
        void setDamage(int damage);
        void setDelay(double delay);
        void setSwitchDirection(bool value);
        void setXMoveValue(int x);
        void setYMoveValue(int y);

        //This is the destructor
        ~Bot();


};

#endif
