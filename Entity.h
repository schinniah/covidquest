#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity {
    private:
        std::string name;
        SDL_Rect dRect;
        SDL_Texture *texture;
    public:
        Entity();
        Entity(std::string newName, SDL_Rect destinationRect, SDL_Texture *newTexture);
        ~Entity();
        SDL_Rect getDestinationRectangle();
        void setDestinationRectangle(SDL_Rect newRectangle);
        std::string getName();
        void setName(std::string newName);
        SDL_Texture* getTexture();
        void setTexture(SDL_Texture *newTexture);
        // bool collides(Entity entity);
};

#endif