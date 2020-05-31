#if !defined(TERRITORY_HPP)
#define TERRITORY_HPP

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

class Territory  {
private:
    // std::string name;
    // sf::VertexArray vertices = sf::VertexArray(sf::TriangleStrip, 0);
    // sf::Texture texture;

    // virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
    //     states.transform *= getTransform();
    //     states.texture = &this->texture;
    //     target.draw(this->vertices, states);
    // }

    std::string name;
    sf::Vector2f position;
    std::vector<sf::Vector2f> pixels;
public:
    // Territory();
    // explicit Territory(std::string name);
    // Territory(std::string name, std::string texturePath);

    // void setName(std::string);

    // void loadTexture(const std::string texturePath);

    // void addVertex(sf::Vertex vertex);
    // void addVertex(sf::Vector2f position);
    // void addVertex(sf::Vector2f position, sf::Vector2f texCoords);

    // size_t getPointCount() const;
    // sf::Vector2f getPoint(size_t index) const;

    void setName(std::string);
    void setPosition(sf::Vector2f position);
    void addPixel(sf::Vector2f pixel);
    void addPixels(std::vector<sf::Vector2f> pixels);
};

#endif // TERRITORY_HPP
