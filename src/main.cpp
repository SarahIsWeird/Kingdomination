#include <SFML\Graphics.hpp>
#include <string>

#include <iostream>
#include <cmath>

#include <map.hpp>
#include <editor.hpp>

enum gameModes {
    menuMode,
    normalMode,
    editorMode
};

static const float MOVEMENT_FACTOR = 2.f;

static gameModes gameMode;

sf::RenderWindow window(sf::VideoMode(800, 600), "Kingdomination");

sf::Vector2f startingMousePos;
sf::Vector2f startingViewCenter;

int main(int argc, char *argv[]) {

    gameMode = editorMode;

    Editor editor;

    editor.loadTexture("assets/map_test.png");

    window.setView(sf::View(sf::FloatRect(0.f, 0.f, 800.f, 600.f)));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::Resized) { // Change the view accordingly to show the same scale
                sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }

            if (event.type == sf::Event::MouseWheelScrolled) { // Zoom in and out of the view
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                    sf::View view = window.getView();

                    view.zoom(std::exp(-event.mouseWheelScroll.delta / 20)); // Exponential function to normalize input to 0 to inf

                    window.setView(view);
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Middle) {
                    startingMousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
                    startingViewCenter = window.getView().getCenter();
                }
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) { // View movement
            sf::View view = window.getView();

            sf::Vector2f currMousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
            sf::Vector2f vectorStartToNow = currMousePos - startingMousePos;

            vectorStartToNow.x *= view.getSize().x / (float) window.getSize().x; // Scale the movement because of the zoom
            vectorStartToNow.y *= view.getSize().y / (float) window.getSize().y;

            view.setCenter(startingViewCenter - vectorStartToNow);

            window.setView(view);
        }

        window.clear();

        if (gameMode == editorMode) {
            editor.draw(window);
        }

        window.display();
    }
}