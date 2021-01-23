/**
 * Author: Suseela Chinniah
 * Date: Nov 11th, 2020
 * 
 * Defines Graphics class which contains methods to create
 * and move entities in the game window
 */

#ifndef GRAPHICS_H
#define GRAPHICS_H

#define WIDTH 816
#define HEIGHT 624
#define INVENTORY_SPACING 92

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <tuple>
#include "Item.h"
#include "Entity.h"

class Graphics {
    private:
        static Graphics *sInstance;
        SDL_Texture *playerTexture;
        SDL_Rect background;
        SDL_Window *window;
        SDL_Renderer *renderer;
        std::vector<Entity> entities;
        std::vector<Entity> walls;

    public:
        Graphics();
        ~Graphics();
        static Graphics *instance();
        Entity move(std::string entityName, int x, int y);
        void render();
        void addEntity(Entity entity);
        std::vector<Entity> getEntities();
        void removeEntity();
        void removeEntityByEntity(Entity entity);
        int findEntityIndexByEntity(Entity entity);
        void clearEntities();
        int findEntityIndex(std::string name);
        void accessInventory(std::vector<Item> inventory);
        void renderInventory(std::vector<Item> inventory, int slotPointer);
        SDL_Texture* createTexture(char *filePath);
        bool collides(Entity entity);
        bool collides(std::string entityName);
        bool isValid(int x, int y);
        Entity collidesWith(Entity entity);
        bool isIntersecting(std::string firstEntityName, std::string secondEntityName);
        void renderHPBar(int playerHealth);
        std::tuple<int,int> getEntityLocation(std::string entityName);

};

#endif
