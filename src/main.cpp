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

const sf::Vector2f VECTOR_NOT_SET;

sf::Vector2f lastMousePos;

int main(int argc, char *argv[]) {

    gameMode = editorMode;

    Editor editor;

    lastMousePos = VECTOR_NOT_SET;

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

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Middle) {
                    lastMousePos = VECTOR_NOT_SET;
                }
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) { // View movement
            if (lastMousePos == VECTOR_NOT_SET) {
                lastMousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            } else {
                sf::View view = window.getView();

                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                sf::Vector2f moveVector = lastMousePos - mousePos;

                view.move(moveVector);
                window.setView(view);

                lastMousePos = mousePos;
            }

            // sf::View view = window.getView();
            // sf::Vector2u size = window.getSize();

            // sf::Vector2f mousePos(sf::Mouse::getPosition(window));



            // sf::Vector2f movement(mousePos.x / size.x / MOVEMENT_FACTOR - (.5f / MOVEMENT_FACTOR),
            //                         mousePos.y / size.y / MOVEMENT_FACTOR - (.5f / MOVEMENT_FACTOR));
            // view.move(movement);

            // window.setView(view);
        }

        std::cout << window.getView().getCenter().x << ", " << window.getView().getCenter().y << std::endl;

        window.clear();

        if (gameMode == editorMode) {
            editor.draw(window);
        }

        window.display();
    }
}