#if !defined(MAP_HPP)
#define MAP_HPP

#include <SFML/Graphics.hpp>

#include <cstddef>
#include <string>

#include <territory.hpp>
#include <territory_null.hpp>

class Map {
    private:
        std::vector<Territory> territories;
    public:
        void addTerritory(Territory territory);

        Territory getTerritoryFromMouse(sf::Window *window);
};

#endif // MAP_HPP
