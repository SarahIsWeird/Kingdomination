#if !defined(EDITOR_HPP)
#define EDITOR_HPP

#include <SFML/Graphics.hpp>

#include <territory.hpp>

struct territoryData_s {
    Territory territory;

    std::vector<sf::Vector2f> assignedPixels;
};

class Editor {
private:
    sf::Texture map_texture;
    sf::Sprite map_sprite;

    territoryData_s *territories;

public:
    void loadTexture(const std::string path);

    void draw(sf::RenderWindow &window);
};

#endif // EDITOR_HPP
