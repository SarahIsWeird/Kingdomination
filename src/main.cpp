#include <SFML\Graphics.hpp>
#include <string>

#include <map.hpp>

sf::RenderWindow window(sf::VideoMode(800, 600), "Kingdomination");

int main(int argc, char *argv[]) {
    Map map;

    Territory testTerritory("Test", "assets/test.png");
    testTerritory.addVertex(sf::Vector2f(104,  36));
    testTerritory.addVertex(sf::Vector2f(147,  52));
    testTerritory.addVertex(sf::Vector2f(120, 144));
    testTerritory.addVertex(sf::Vector2f( 44, 143));
    testTerritory.addVertex(sf::Vector2f( 26, 114));
    testTerritory.addVertex(sf::Vector2f( 37,  66));
    testTerritory.addVertex(sf::Vector2f( 74,  78));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(testTerritory);

        window.display();
    }
}