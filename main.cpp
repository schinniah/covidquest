/**
 * @brief main class
 * @authors Lucas Fraulin, Suseela Chinniah, Ibai Seco
 */

/*
-----------------------------------------------------
 INCLUDES
-----------------------------------------------------
*/
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Graphics.h"
#include "Item.h"
#include "Entity.h"
#include "Protagonist.h"
#include "Level.h"
#include "Bot.h"
#include "Timer.h"

#define FRAME_RATE 60

bool debug = true;
bool running = true;
int fps;
int level;

Graphics graphics;

/*
-----------------------------------------------------
 MAIN
-----------------------------------------------------
*/
int main(int argc, char *argv[]) {
    
    /* initialize all levels 1- */
    level = 1;
    Level lvl1(level);
    Level lvl2(level+1);
    Level lvl3(level+2);
    Level lvl4(level+3);
    Level lvl5(level+4);
    Level lvl6(level+5);
    Level lvl7(level+6);
    Level lvl8(level+7);
    Level lvl9(level+8);
    Level lvl10(level+9);

    Level curLevel = lvl1;

    std::vector<Item> inventory;

    int numofitems = lvl1.getItems().size();

    /* Initialize protagonist object */
    SDL_Rect protagonistRectangle;

    /**
     * @brief Protagonist rectangle
     * @details Initialize location and dimension of protagonist square 
     */
    protagonistRectangle.x = WIDTH / 2;
    protagonistRectangle.y = HEIGHT - 40;
    protagonistRectangle.w = 40;
    protagonistRectangle.h = 40;

    /* Create protagonist sprite from png file */
    SDL_Texture *playerTexture = graphics.createTexture("images/black-mage.png");
    
    Entity protagonistEntity("protagonist", protagonistRectangle, playerTexture);
    graphics.addEntity(protagonistEntity);

    
    /* Place bots for level 1 */
    for(int i = 0; i < curLevel.getBots().size(); i++){
        Bot curBot = curLevel.getBots().at(i);

        SDL_Texture *botTexture = graphics.createTexture("images/covid.png");
        SDL_Rect botRectangle;

        botRectangle.w = 30;
        botRectangle.h = 30;
        
        botRectangle.x = get<0>(curBot.getLocation());
        botRectangle.y = get<1>(curBot.getLocation());

        Entity botEntity(curBot.getName(), botRectangle, botTexture);
        graphics.addEntity(botEntity);
    }

    /* Place items for level 1 */
    for(int i = 0; i < curLevel.getItems().size(); i++){

        Item curItem = curLevel.getItems().at(i);

        SDL_Texture *itemTexture = graphics.createTexture(&curItem.getTextureFilename()[0]);
        SDL_Rect itemRect;

        itemRect.x = get<0>(curItem.getLocation());
        itemRect.y = get<1>(curItem.getLocation());
        itemRect.w = 30;
        itemRect.h = 30;

        Entity itemEntity(curItem.getItemName(), itemRect, itemTexture);
        graphics.addEntity(itemEntity);
    }

    //graphics.render();

    std::tuple<int, int> location = std::tuple<int, int>{0, 1}; //location

    Protagonist player(100, inventory, 1, location); 

    // for (int i = 0; i < (player.getHealth())/100; i++) {
    //     SDL_Rect healthRectangle = {(i*10),10,30,30};
    //     Entity Health
    // }

    /* Health functionality: player health in hearts */
    SDL_Rect health1Rec = {10,10,30,30};
    SDL_Rect health2Rec = {20,10,30,30};
    SDL_Rect health3Rec = {30,10,30,30};
    SDL_Rect health4Rec = {40,10,30,30};
    SDL_Rect health5Rec = {50,10,30,30};
    SDL_Rect health6Rec = {60,10,30,30};
    SDL_Rect health7Rec = {70,10,30,30};
    SDL_Rect health8Rec = {80,10,30,30};
    SDL_Rect health9Rec = {90,10,30,30};
    SDL_Rect health10Rec = {100,10,30,30};
    /* Health texture */
    SDL_Texture *healthTexture = graphics.createTexture("images/heart.png");
    /* Render health into the board */
    Entity health1("health1", health1Rec, healthTexture);
    Entity health2("health2", health2Rec, healthTexture);
    Entity health3("health3", health3Rec, healthTexture);
    Entity health4("health4", health4Rec, healthTexture);
    Entity health5("health5", health5Rec, healthTexture);
    Entity health6("health6", health6Rec, healthTexture);
    Entity health7("health7", health7Rec, healthTexture);
    Entity health8("health8", health8Rec, healthTexture);
    Entity health9("health9", health9Rec, healthTexture);
    Entity health10("health10", health10Rec, healthTexture);
    
    std::vector<Entity> lives;
    graphics.addEntity(health1);
    lives.push_back(health1);
    graphics.addEntity(health2);
    lives.push_back(health2);
    graphics.addEntity(health3);
    lives.push_back(health3);
    graphics.addEntity(health4);
    lives.push_back(health4);
    graphics.addEntity(health5);
    lives.push_back(health5);
    graphics.addEntity(health6);
    lives.push_back(health6);
    graphics.addEntity(health7);
    lives.push_back(health7);
    graphics.addEntity(health8);
    lives.push_back(health8);
    graphics.addEntity(health9);
    lives.push_back(health9);
    graphics.addEntity(health10);
    lives.push_back(health10);
    graphics.render();

    Timer *timer = Timer::instance();
    
    /**
     * Event handling
     * Queue of user actions e.g. mouse click, keyboard press, joy stick movement
     */
    SDL_Event e;

    int updatelevelto = level;

    /* main loop, handles user input */
    while(running) {
        timer->update();

        if(timer->getDeltaTime() >= (1.0f / FRAME_RATE)) {
            std::vector<Bot> currentBots = curLevel.getBots();
            for(std::vector<Bot>::iterator it = currentBots.begin(); it != currentBots.end(); ++it) {
                Bot currentBot = *it;
                if(graphics.isIntersecting(currentBot.getName(), "protagonist")) {
                    continue;
                }

                std::tuple<int, int> startLoc = currentBot.getStartRoute();
                std::tuple<int, int> endLoc = currentBot.getEndRoute();
                std::tuple<int, int> currentLoc = currentBot.getLocation();

                int xStart = std::get<0>(startLoc);
                int xEnd = std::get<0>(endLoc);
                int xCurrent = std::get<0>(currentLoc);

                int xMoveVal = 0, yMoveVal = 0;

                // decide to move left or right
                if(xStart < xEnd) {
                    if(!currentBot.getSwitchDirection()) {
                        if(xCurrent + 10 <= xEnd) {
                            xMoveVal = 10;
                        } else {
                            xMoveVal = xEnd - xCurrent;
                        }
                    } else {
                        if(xCurrent - 10 >= xStart) {
                            xMoveVal = -10;
                        } else {
                            xMoveVal = xStart - xCurrent;
                        }
                    }
                } else {
                    if(!currentBot.getSwitchDirection()) {
                        if(xCurrent - 10 >= xEnd) {
                            xMoveVal = -10;
                        } else {
                            xMoveVal = xEnd - xCurrent;
                        }
                    } else {
                        if(xCurrent + 10 <= xStart) {
                            xMoveVal = 10;
                        } else {
                            xMoveVal = xStart - xCurrent;
                        }
                    }
                }

                if(xMoveVal != 0) {
                    std::tuple<int, int> newLoc = std::make_tuple(xCurrent + xMoveVal, std::get<1>(currentLoc));
                    graphics.move(currentBot.getName(), xMoveVal, 0);
                    if(newLoc == startLoc || newLoc == endLoc) {
                        currentBot.setSwitchDirection(!currentBot.getSwitchDirection());
                    }
                    currentBot.setLocation(newLoc);
                    int botIndex = it - currentBots.begin();
                    currentBots.erase(currentBots.begin() + botIndex);
                    currentBots.insert(currentBots.begin() + botIndex, currentBot);
                    curLevel.setBots(currentBots);
                    graphics.render();
                    continue;
                }

                int yStart = std::get<1>(startLoc);
                int yEnd = std::get<1>(endLoc);
                int yCurrent = std::get<1>(currentLoc);

                // if bot did not move left or right, decide to move up or down
                if(yStart < yEnd) {
                    if(!currentBot.getSwitchDirection()) {
                        if(yCurrent + 10 <= yEnd) {
                            yMoveVal = 10;
                        } else {
                            yMoveVal = yEnd - yCurrent;
                        }
                    } else {
                        if(yCurrent - 10 >= yStart) {
                            yMoveVal = -10;
                        } else {
                            yMoveVal = yStart - yCurrent;
                        }
                    }
                } else {
                    if(!currentBot.getSwitchDirection()) {
                        if(yCurrent - 10 >= yEnd) {
                            yMoveVal = -10;
                        } else {
                            yMoveVal = yEnd - yCurrent;
                        }
                    } else {
                        if(yCurrent + 10 <= yStart) {
                            yMoveVal = 10;
                        } else {
                            yMoveVal = yStart - yCurrent;
                        }
                    }
                }
                if(yMoveVal != 0) {
                    std::tuple<int, int> newLoc = std::make_tuple(xCurrent, yCurrent + yMoveVal);
                    graphics.move(currentBot.getName(), 0, yMoveVal);
                    if(newLoc == startLoc || newLoc == endLoc) {
                        currentBot.setSwitchDirection(!currentBot.getSwitchDirection());
                    }
                    currentBot.setLocation(newLoc);
                    int botIndex = it - currentBots.begin();
                    currentBots.erase(currentBots.begin() + botIndex);
                    currentBots.insert(currentBots.begin() + botIndex, currentBot);
                    curLevel.setBots(currentBots);
                    graphics.render();
                }
                
            }
        
               
            //check if you win level
            if (numofitems == 0){
                if (level == 10){
                    //win the game
                } else {
                    updatelevelto += 1;
                    cout << updatelevelto << "updatelevelto" << endl;
                }
            }

            /* every time you progress to a new level this executes */
            if(updatelevelto != level){
                player.getInventory().clear();

                graphics.clearEntities();

                graphics.render();

                level = updatelevelto;

                graphics.addEntity(protagonistEntity);

                switch(level){
                    case 1:
                        curLevel = lvl1;
                        break;
                    case 2:
                        curLevel = lvl2;
                        break;
                    case 3:
                        curLevel = lvl3;
                        break;
                    case 4:
                        curLevel = lvl4;
                        break;
                    case 5:
                        curLevel = lvl5;
                        break;
                    case 6:
                        curLevel = lvl6;
                        break;
                    case 7:
                        curLevel = lvl7;
                        break;
                    case 8:
                        curLevel = lvl8;
                        break;
                    case 9:
                        curLevel = lvl9;
                        break;
                    case 10:
                        curLevel = lvl10;
                        break;
                    default:
                        //won the game?
                        break;
                }

                numofitems = curLevel.getItems().size();
            
                /* place bots for current level */
                for(int i = 0; i < curLevel.getBots().size(); i++){
                    Bot curBot = curLevel.getBots().at(i);

                    SDL_Texture *botTexture = graphics.createTexture("images/covid.png");
                    SDL_Rect botRectangle;

                    botRectangle.w = 30;
                    botRectangle.h = 30;
                    
                    botRectangle.x = get<0>(curBot.getLocation());
                    botRectangle.y = get<1>(curBot.getLocation());

                    Entity botEntity(curBot.getName(), botRectangle, botTexture);
                    graphics.addEntity(botEntity);
                }

                /*place items for current level */
                for(int i = 0; i < curLevel.getItems().size(); i++){

                    Item curItem = curLevel.getItems().at(i);

                    SDL_Texture *itemTexture = graphics.createTexture(&curItem.getTextureFilename()[0]);
                    SDL_Rect itemRect;

                    itemRect.x = get<0>(curItem.getLocation());
                    itemRect.y = get<1>(curItem.getLocation());
                    itemRect.w = 30;
                    itemRect.h = 30;

                    Entity itemEntity(curItem.getItemName(), itemRect, itemTexture);
                    graphics.addEntity(itemEntity);
                }
            
            /* Hearts need to be added in order and MUST BE LAST OF .addEntity */
            graphics.addEntity(health1);
            graphics.addEntity(health2);
            graphics.addEntity(health3);
            graphics.addEntity(health4);
            graphics.addEntity(health5);
            graphics.addEntity(health6);
            graphics.addEntity(health7);
            graphics.addEntity(health8);
            graphics.addEntity(health9);
            graphics.addEntity(health10);

            graphics.render();
            
           
            }
            /* while event queue is not empty */
            SDL_PollEvent(&e);
            if(e.type == SDL_QUIT) {
                running = false;
                break;
            /* if a key is pressed */
            } else if(e.type == SDL_KEYDOWN) {

                if (player.getHealth() <= 0) {
                running = false;
                    break;
                }
                
                int speed = player.getSpeed();

                /* applies all the inventory items */
                for(int i = 0; i < player.getInventory().size(); i++){
                    Item item = player.getInventory().at(i);
                    int curhealth = player.getHealth();
                    int curspeed = player.getSpeed();
                    
                    /* Apply the upgrade values (equip the item) if not already applied/equipped */
                    if(!item.isEquipped()){
                        if (item.getItemType() == "health"){
                            player.setHealth(curhealth + item.getUpgradeQuantity());
                        } else if (item.getItemType() == "speed"){
                            player.setSpeed(curspeed + item.getUpgradeQuantity());
                        }
                        player.equip(item);
                        std::cout << player.getInventory().at(i).isEquipped() << std::endl;
                    }
                }
                
                /* Timer functionality */
                Entity collision;
                switch(e.key.keysym.sym) {
                    case SDLK_UP:
                        collision = graphics.move("protagonist", 0, (-10*speed));
                        player.setLocation(std::tuple<int, int>(protagonistEntity.getDestinationRectangle().x, protagonistEntity.getDestinationRectangle().y));     
                        if(debug) std::cout << "up\n" << player.getHealth() << " = current health" << std::endl;
                        break;
                    case SDLK_DOWN:
                        collision = graphics.move("protagonist", 0, (10*speed));
                        player.setLocation(std::tuple<int, int>(protagonistEntity.getDestinationRectangle().x, protagonistEntity.getDestinationRectangle().y));
                        if(debug) std::cout << "down\n"<< player.getHealth() << " = current health" << std::endl;
                        break;
                    case SDLK_LEFT:
                        collision = graphics.move("protagonist", (-10*speed), 0);
                        player.setLocation(std::tuple<int, int>(protagonistEntity.getDestinationRectangle().x, protagonistEntity.getDestinationRectangle().y));
                        if(debug) std::cout << "left\n"<< player.getHealth() << " = current health" << std::endl;
                        break;
                    case SDLK_RIGHT:
                        collision = graphics.move("protagonist", (10*speed), 0);
                        player.setLocation(std::tuple<int, int>(protagonistEntity.getDestinationRectangle().x, protagonistEntity.getDestinationRectangle().y));
                        if(debug) std::cout << "right\n"<< player.getHealth() << " = current health" << std::endl;
                        break;
                    case SDLK_i:
                        graphics.accessInventory(player.getInventory());
                        break;
                }

                //check protagonist location against current location of all bots
                //remove health according to the damage of the specified bot if they are overlapping
                //check every time either a bot or the protagonist moves
                
                
                
                // for (int i=0;i<curLevel.getBots().size();i++) {
                //     if (curLevel.getBots().at(i).getLocation() == player.getLocation()) {
                //         player.setHealth(player.getHealth() - curLevel.getBots().at(i).getDamage());

                //         //Subtract the bot damage from health entity, if bot damage = 20, then remove 2 hearts
                //         for(int j = 0; j < curLevel.getBots().at(i).getDamage()/10;i++) {
                //             graphics.removeEntity();
                //         }
                //         //Add functionality for getting health from items
                //     }       
                // }
                if(collision.getName() != "protagonist"){
 
                    for(int j = 0; j < curLevel.getItems().size(); j++){
                        if(collision.getName().compare(curLevel.getItems().at(j).getItemName()) == 0){
                            graphics.removeEntityByEntity(collision);
                            std::vector<Item> tempInventory = player.getInventory();
                            tempInventory.push_back(curLevel.getItems().at(j));
                            player.setInventory(tempInventory);
                            numofitems -= 1;
                            cout << numofitems << endl;
                            break;
                        }
                    }
                    /* Remove player health when collision with enemy occurs */
                    for(int k = 0; k < curLevel.getBots().size(); k++) {
                        if(collision.getName().compare(curLevel.getBots().at(k).getName()) == 0) {
                            player.setHealth(player.getHealth() - curLevel.getBots().at(k).getDamage());
                            if (player.getHealth() <= 100) {
                                for (int h = 0; h < curLevel.getBots().at(k).getDamage()/10; h++) {
                                    graphics.removeEntityByEntity(lives.at(lives.size()-1));
                                    lives.pop_back();
                                }
                            }
                        }
                    }
                    //Adding items to inventory
                    // if(name == "sanitizer" || name == "energybar" || name == "toiletpaper" || name == "mask" || name == "vaccine" || name == "gloves"){
                    //     graphics.removeEntityByEntity(collided);
                    //     for(int j = 0; j < curLevel.getItems().size(); j++){
                    //         Item current = curLevel.getItems().at(j);
                    //         player.getInventory().push_back(current);
                    //     }
                    // }

                    //Removing health from player
                    // if (name == "bot1" || name == "bot2" || name == "bot3") {
                    //     player.setHealth(player.getHealth() - 10);
                    //     for (int i = 0; i<(10 - (player.getHealth()/10)); i++) {
                    //         graphics.removeEntity();
                    //     }
                    // }

                    /* Update all entities in the game window */
                    

                }
                graphics.render();
            }
            timer->reset();
        
        
        }
    }

    return 0;
};