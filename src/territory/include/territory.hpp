#if !defined(TERRITORY_HPP)
#define TERRITORY_HPP

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

class Territory : public sf::Shape {
private:
    std::string name;
    sf::VertexArray vertices = sf::VertexArray(sf::TriangleStrip, 0);
    sf::Texture texture;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = &this->texture;
        target.draw(this->vertices, states);
    }
public:
    Territory();
    explicit Territory(std::string name);
    Territory(std::string name, std::string texturePath);

    void setName(std::string);

    void loadTexture(const std::string texturePath);

    void addVertex(sf::Vertex vertex);
    void addVertex(sf::Vector2f position);
    void addVertex(sf::Vector2f position, sf::Vector2f texCoords);

    size_t getPointCount() const;
    sf::Vector2f getPoint(size_t index) const;
};

#endif // TERRITORY_HPP
