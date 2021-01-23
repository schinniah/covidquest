/**
 * @brief Graphics class
 * @details
 * @authors Ibai Seco, Lucas Fraulin, Suseela Chinniah
 */

/*
-----------------------------------------------------
 INCLUDES
-----------------------------------------------------
*/
#include "Graphics.h"

Graphics *Graphics::sInstance = NULL;

Graphics *Graphics::instance() {
    if(sInstance == NULL) {
        sInstance = new Graphics();
    }
    return sInstance;
}

using namespace std;

/**
 * @brief Construct a new Graphics:: Graphics object
 * @details This is the contructor for a Graphics object
 */
Graphics::Graphics() {
    SDL_Init(SDL_INIT_EVERYTHING);
    
    window = SDL_CreateWindow("Covid Quest", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

/**
 * @brief Destroy the Graphics:: Graphics object
 * @details This is the destructor for a Graphics object
 */
Graphics::~Graphics() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/**
 * @brief Move an entity's location. e.g. move("protagonist", 0, -10)
 * @details Moves the protagonist entity up by 10 pixels
 */
Entity Graphics::move(std::string name, int x, int y) {
    int index = findEntityIndex(name);
    if(index >= 0) {
        Entity entity = entities.at(index);
        // SDL_Rect sRect = entity.getSourceRectangle();
        SDL_Rect dRect = entity.getDestinationRectangle();
        dRect.x += x;
        dRect.y += y;
        entity.setDestinationRectangle(dRect);
        if(!collides(entity)) {            
            entities.erase(entities.begin() + index);
            entities.push_back(entity);
            return entity;
        } else {
            return collidesWith(entity);
        }
    }
}

/**
 * @brief Draw the map and all entities
 * @details Insert black background, loop through vector of entities and draw them
 */
void Graphics::render() {
    SDL_RenderClear(renderer);
    char *backgroundTextureFilename = "images/shop.png";
    SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, IMG_Load(backgroundTextureFilename));
    background.x = 0;
    background.y = 0;
    background.w = WIDTH;
    background.h = HEIGHT;
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &background);

    for(int i = 0; i < entities.size(); i++) {
        Entity entity = entities.at(i);
        SDL_Rect entityDestRect = entity.getDestinationRectangle();
        SDL_Texture *entityTexture = entity.getTexture();
        SDL_RenderCopy(renderer, entityTexture, &background, &entityDestRect);
    }
    SDL_RenderPresent(renderer);
}

/**
 * @brief Add function
 * @details Push back an entity in to entities
 * 
 * @param entity 
 */
void Graphics::addEntity(Entity entity) {
    entities.push_back(entity);
}

/**
 * @brief Getter function
 * @details Get entities
 * 
 * @return vector<Entity> 
 */
vector<Entity> Graphics::getEntities(){
    return entities;
}

/**
 * @brief Remove function
 * @details Remove the lastest entity that was pushed back
 */
void Graphics::removeEntity() {
    entities.pop_back();
}

// void Graphics::removeEntity(std::string name){
//     int index = findEntityIndex(name);
//     entities.erase(entities.begin() + index);
// }

/**
 * @brief Remove function
 * @details Find the entity index using the findEntityIndexByLocation function and remove it from entities
 * 
 * @param ent 
 */
void Graphics::removeEntityByEntity(Entity ent){
    int index = findEntityIndexByEntity(ent);
    entities.erase(entities.begin() + index);
}

/**
 * @brief Clear entities
 * @details Clear all entities in entities
 */
void Graphics::clearEntities(){
    entities.clear();
}

/**
 * @brief Finds entity object by name
 * @details Go through the entities using for loop to find the corresponding entity
 * 
 * @param name 
 * @return * finds 
 */
int Graphics::findEntityIndex(std::string name) {
    for(int i = 0; i < entities.size(); i++) {
        Entity entity = entities.at(i);
        if(name.compare(entity.getName()) == 0) {
            return i;
        }
    }
    std::cout << "Entity with name " << name << " was not found" << std::endl;
    return -1;
}

/**
 * @brief Find entity index by location
 * @details Find the index of the entity by looping through entities and get the index of the entity
 * 
 * @param rect 
 * @return int 
 */
int Graphics::findEntityIndexByEntity(Entity entity){
    string name = entity.getName();
    int index = -1;
    int dup = 0;
    for(int i = 0; i < entities.size(); i++) {
        Entity entity = entities.at(i);
        if(name.compare(entity.getName()) == 0) {
            index = i;
            dup++;
        }
    }

    if(dup > 1){
        for(int i = 0; i < entities.size(); i++){
            if(entity.getDestinationRectangle().x == entities.at(i).getDestinationRectangle().x){
                if (entity.getDestinationRectangle().y == entities.at(i).getDestinationRectangle().y)
                    index = i;
            }
        }
    }
    return index;
}

/**
 * @brief Access inventory function
 * @details Inside access inventory method
 * 
 * @param inventory 
 */
void Graphics::accessInventory(std::vector<Item> inventory) {
    std::cout << "inside access inventory method" << std::endl;
    int slotPointer = 0;
    bool exit = false;
    SDL_Event inventoryEvent;
    renderInventory(inventory, slotPointer);
    while(!exit) {
        SDL_WaitEvent(&inventoryEvent);
        if(inventoryEvent.type == SDL_QUIT) {
            break;
        } else if(inventoryEvent.type == SDL_KEYDOWN) {
            switch(inventoryEvent.key.keysym.sym) {
                case SDLK_RETURN:
                {
                    if(slotPointer < inventory.size()) {
                        Item itemToEquip = inventory.at(slotPointer);
                        itemToEquip.equipItem();
                        inventory.at(slotPointer) = itemToEquip;
                        renderInventory(inventory, slotPointer);
                    }
                    break;
                }
                case SDLK_UP:
                    if(slotPointer > 3) {
                        slotPointer -= 4;
                        renderInventory(inventory, slotPointer);
                    }
                    break;
                case SDLK_DOWN:
                    if(slotPointer < 12) {
                        slotPointer += 4;
                        renderInventory(inventory, slotPointer);
                    }
                    break;
                case SDLK_LEFT:
                    if(slotPointer > 0) {
                        slotPointer -= 1;
                        renderInventory(inventory, slotPointer);
                    }
                    break;
                case SDLK_RIGHT:
                    if(slotPointer < 15) {
                        slotPointer += 1;
                        renderInventory(inventory, slotPointer);
                    }
                    break;
                case SDLK_i:
                    std::cout << "returning\n";
                    exit = true;
                    render();
                    break;
            }
        }
    }
}

/**
 * @brief Render inventory
 * @details 
 * 
 * @param inventory 
 * @param slotPointer 
 */
void Graphics::renderInventory(std::vector<Item> inventory, int slotPointer) {

    std::vector<Item> inventoryCopy = inventory;

    SDL_Rect inventoryBackgroundRect;
    inventoryBackgroundRect.x = 188;
    inventoryBackgroundRect.y = 7;
    inventoryBackgroundRect.w = 440;
    inventoryBackgroundRect.h = 610;

    SDL_Texture *inventoryBackgroundTexture = SDL_CreateTextureFromSurface(renderer, IMG_Load("images/inventory.png"));
    SDL_RenderCopy(renderer, inventoryBackgroundTexture, &background, &inventoryBackgroundRect);

    SDL_Texture *selectedSlotTexture = SDL_CreateTextureFromSurface(renderer, IMG_Load("images/selected.png"));
    SDL_Rect selectedSlotRect;
    selectedSlotRect.w = 70;
    selectedSlotRect.h = 70;

    if (slotPointer % 4 == 0) {
        selectedSlotRect.x = 235;
    } else if (slotPointer % 4 == 1) {
        selectedSlotRect.x = 327;
    } else if (slotPointer % 4 == 2) {
        selectedSlotRect.x = 419;
    } else if (slotPointer % 4 == 3) {
        selectedSlotRect.x = 511;
    }

    if(slotPointer < 4) {
        selectedSlotRect.y = 54;
    } else if (slotPointer < 8) {
        selectedSlotRect.y = 146;
    } else if (slotPointer < 12) {
        selectedSlotRect.y = 238;
    } else {
        selectedSlotRect.y = 330;
    }
    SDL_RenderCopy(renderer, selectedSlotTexture, &background, &selectedSlotRect);

    int x = 241, y = 60;

    SDL_Texture *equippedTexture = SDL_CreateTextureFromSurface(renderer, IMG_Load("images/equipped.png"));

    for(std::vector<Item>::iterator it = inventoryCopy.begin(); it != inventoryCopy.end(); ++it) {
        std::string filename = (*it).getTextureFilename();
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = 56;
        rect.h = 56;
        SDL_Surface *itemSurface = IMG_Load(&filename[0]);
        SDL_Texture *itemTexture = SDL_CreateTextureFromSurface(renderer, IMG_Load(&filename[0]));
        SDL_FreeSurface(itemSurface);
        SDL_RenderCopy(renderer, itemTexture, &background, &rect);

        if((*it).isEquipped()) {
            SDL_RenderCopy(renderer, equippedTexture, &background, &rect);
        }

        if(x + INVENTORY_SPACING > (INVENTORY_SPACING * 3 + 241)) {
            x = 241;
            y += INVENTORY_SPACING;
        } else {
            x += INVENTORY_SPACING;
        }
    }
    SDL_RenderPresent(renderer);   
}

/**
 * @brief Create texture
 * @details
 * 
 * @param filePath 
 * @return SDL_Texture* 
 */
SDL_Texture* Graphics::createTexture(char *filePath) {
    return SDL_CreateTextureFromSurface(renderer, IMG_Load(filePath));
}

/**
 * @brief Collision check function
 * @details Loop through entities to see if the input entity collides with any other one in the list
 * 
 * @param entity 
 * @return true 
 * @return false 
 */
bool Graphics::collides(Entity entity) {
    SDL_Rect entityRect = entity.getDestinationRectangle();
    std::string entityName = entity.getName();
    bool value = false;
    for(int i = 0; i < entities.size(); i++){
        Entity curEntity = entities.at(i);
        SDL_Rect comparedRect = curEntity.getDestinationRectangle();
        string comparedName = curEntity.getName();
        if (entityName != comparedName && SDL_HasIntersection(&entityRect, &comparedRect) == SDL_TRUE){
            cout << "collision with " << curEntity.getName() << " graphics-collides" << endl;
            value = true;
        }
    }
    return value;

}
bool Graphics::isValid(int x, int y){
    //checking borders first
    if ((x <50) || (x>770)){
        return false;
    }
    if(y < 145){
        return false;
    }
    if ((x < 360)&& (y> 480)){
        return false;
    }
    if ((x > 480)&&(y > 480)){
        return false;
    }
    //checking the objects on the map
    if ((x<95)&&(y<190)){
        return false;
    }
    if((x>190)&&(x<240)&&((y <190))){
        return false;
    }
    if ((x> 330)&&(x<480)&&(y>190)&&(y<245)){
        return false;
    }
    if((x>525)&&(x<720)&&(y>190)&&(y<290)){
        return false;
    }
    if ((x>95)&&(x<290)&&(y>295)&&(y<330)){
        return false;
    }
    if ((x>525)&&(x<720)&&(y>335)&&(y<382)){
        return false;
    }
    if ((x>720)&&(x<770)&&(y>435)&&(y<480)){
        return false;
    }
    return true;
}

/**
 * @brief What the input entity collides against
 * @details If there is collision it returns entity that parameter entity collides against. If not, it returns the parameter entity
 * 
 * @param entity 
 * @return Entity 
 */
Entity Graphics::collidesWith(Entity entity) {

    SDL_Rect entityRect = entity.getDestinationRectangle();
    std::string entityName = entity.getName();
    
    for(int i = 0; i < entities.size(); i++){
        Entity curEntity = entities.at(i);
        SDL_Rect comparedRect = curEntity.getDestinationRectangle();
        string comparedName = curEntity.getName();
        if (entityName != comparedName && SDL_HasIntersection(&entityRect, &comparedRect) == SDL_TRUE){
            cout << "collision with " << curEntity.getName() << " graphics-collides" << endl;
            return curEntity;
        }
    }
    return entity;
}

/**
 * @brief Getter function
 * @details Get the location of the entity. If not, return (-1,-1)
 * 
 * @param entityName 
 * @return std::tuple<int, int>
 */
std::tuple<int, int> Graphics::getEntityLocation(std::string entityName) {
    int index = findEntityIndex(entityName);
    if(index != -1) {
        SDL_Rect rect = entities.at(index).getDestinationRectangle();
        return std::make_tuple(rect.x, rect.y);
    }
    std::cout << "entity not found, returning (-1, -1)\n";
    return std::make_tuple(-1, -1);
}

bool Graphics::collides(std::string entityName) {
    return collides(entities.at(findEntityIndex(entityName)));
}

bool Graphics::isIntersecting(std::string firstEntityName, std::string secondEntityName) {
    Entity firstEntity = entities.at(findEntityIndex(firstEntityName));
    Entity secondEntity = entities.at(findEntityIndex(secondEntityName));

    SDL_Rect firstRect = firstEntity.getDestinationRectangle();
    SDL_Rect secondRect = secondEntity.getDestinationRectangle();

    return SDL_HasIntersection(&firstRect, &secondRect);
}

