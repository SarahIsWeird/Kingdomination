#include <SFML\Graphics.hpp>
#include <string>

#include <iostream>

#include <map.hpp>
#include <editor.hpp>
#include <camera.hpp>

enum gameModes {
    menuMode,
    normalMode,
    editorMode
};

static gameModes gameMode;

sf::RenderWindow window(sf::VideoMode(800, 600), "Kingdomination");

int main(int argc, char *argv[]) {

    gameMode = editorMode;

    Editor editor;

    editor.loadTexture("assets/map_test.png");

    Camera camera(&window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::Resized) {
                camera.onWindowResized(event);
            }

            if (event.type == sf::Event::MouseWheelScrolled) {
                camera.onMouseWheelScrolled(event);
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                camera.onMousePressed(event);
            }
        }

        camera.updateView();

        window.clear();

        if (gameMode == editorMode) {
            editor.draw(window);
        }

        window.display();
    }
}