#include <map.hpp>

void Map::addTerritory(Territory territory) {
    this->territories.push_back(territory);
}

// Territory Map::getTerritoryFromMouse(sf::Window *window) {
//     sf::Vector2i mousePos = sf::Mouse::getPosition();

//     for (auto it = this->territories.begin(); it != this->territories.end(); it++) {
//         if ((*it).getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*window)))
//             return *it;
//     }

//     return TERRITORY_NULL;
// }