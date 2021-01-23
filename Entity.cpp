/**
 * @brief Entity Class
 * @details Each entity on the screen is represented by a rectangle. Entities can be identified by name and have a texture.
 * @author Suseela Chinniah
 */

/*
-----------------------------------------------------
 INCLUDES
-----------------------------------------------------
*/
#include "Entity.h"

/**
 * @brief Construct a new Entity:: Entity object
 * @details Create an Entity object that contains name, destination SDL rectangle, SDL texture
 */
Entity::Entity() {}
Entity::Entity(std::string newName, SDL_Rect destinationRect, SDL_Texture *newTexture) {
    name = newName;
    dRect = destinationRect;
    texture = newTexture;
}

/**
 * @brief Destroy the Entity:: Entity object
 * @details This is the destructor for the Entity object
 */
Entity::~Entity() {}

/**
 * @brief Getter function for Entity
 * @details Get destination rectangle for Entity
 * 
 * @return SDL_Rect 
 */
SDL_Rect Entity::getDestinationRectangle() {
    return dRect;
}

/**
 * @brief Setter function for Entity
 * @details Set destination rectangle for Entity
 * 
 * @param newRectangle 
 */
void Entity::setDestinationRectangle(SDL_Rect newRectangle) {
    dRect = newRectangle;
}

/**
 * @brief Getter function for Entity
 * @details Get the name of the Entity
 * 
 * @return std::string 
 */
std::string Entity::getName() {
    return name;
}

/**
 * @brief Setter function for Entity
 * @details Set the name of the Entity
 * 
 * @param newName 
 */
void Entity::setName(std::string newName) {
    name = newName;
}

/**
 * @brief Getter function for Entity
 * @details Get the texture of the Entity
 * 
 * @return SDL_Texture* 
 */
SDL_Texture* Entity::getTexture() {
    return texture;
}

/**
 * @brief Setter function for Entity
 * @details Set the texture of the Entity
 * 
 * @param newTexture 
 */
void Entity::setTexture(SDL_Texture *newTexture) {
    texture = newTexture;
}