#include <territory.hpp>

void Territory::setName(std::string name) {
    this->name = name;
}

void Territory::setPosition(sf::Vector2f position) {
    this->position = position;
}

void Territory::addPixel(sf::Vector2f pixel) {
    this->pixels.push_back(pixel);
}

void Territory::addPixels(std::vector<sf::Vector2f> pixels) {
    for (std::vector<sf::Vector2f>::iterator it = pixels.begin(); it != pixels.end(); it++) {
        this->pixels.push_back(*it);
    }
}

// Territory::Territory(std::string name) {
//     this->name = name;
// }

// Territory::Territory(std::string name, std::string texturePath) {
//     this->name = name;
//     this->texture.loadFromFile(texturePath);
// }

// void Territory::loadTexture(const std::string texturePath) {
//     this->texture.loadFromFile(texturePath);
// }

// void Territory::addVertex(sf::Vertex vertex) {
//     this->vertices.append(vertex);
// }

// void Territory::addVertex(sf::Vector2f position) {
//     this->addVertex(position, position);
// }

// void Territory::addVertex(sf::Vector2f position, sf::Vector2f texCoords) {
//     this->vertices.append(sf::Vertex(position, texCoords));
// }

// size_t Territory::getPointCount() const {
//     return this->vertices.getVertexCount();
// }

// sf::Vector2f Territory::getPoint(size_t index) const {
//     return this->vertices[index].position;
// }

