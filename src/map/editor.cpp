#include <editor.hpp>

void Editor::loadTexture(const std::string path) {
    this->map_texture.loadFromFile(path);
    this->map_sprite.setTexture(this->map_texture);
}

void Editor::draw(sf::RenderWindow &window) {
    window.draw(this->map_sprite);
}