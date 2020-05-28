#include <territory.hpp>

Territory::Territory(std::string name) {
    this->name = name;
}

Territory::Territory(std::string name, std::string texturePath) {
    this->name = name;
    this->texture.loadFromFile(texturePath);
}

void Territory::setName(std::string name) {
    this->name = name;
}

void Territory::loadTexture(const std::string texturePath) {
    this->texture.loadFromFile(texturePath);
}

void Territory::addVertex(sf::Vertex vertex) {
    this->vertices.append(vertex);
}

void Territory::addVertex(sf::Vector2f position) {
    this->addVertex(position, position);
}

void Territory::addVertex(sf::Vector2f position, sf::Vector2f texCoords) {
    this->vertices.append(sf::Vertex(position, texCoords));
}

size_t Territory::getPointCount() const {
    return this->vertices.getVertexCount();
}

sf::Vector2f Territory::getPoint(size_t index) const {
    return this->vertices[index].position;
}
