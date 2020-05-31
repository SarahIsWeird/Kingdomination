#if !defined(CAMERA_HPP)
#define CAMERA_HPP

#include <SFML/Graphics.hpp>

#include <cmath>

class Camera {
private:
    sf::View* _view;
    sf::RenderWindow* _window;

    sf::Vector2f _startingMousePos;
    sf::Vector2f _startingViewCenter;

    sf::Vector2f _oldWindowSize;
    sf::Vector2f _oldViewSize;

    static const float SCROLL_FACTOR = 10.f;

public:
    Camera();
    Camera(sf::RenderWindow *window);

    void setRenderWindow(sf::RenderWindow *window);

    void onMousePressed(sf::Event &event);
    void onMouseWheelScrolled(sf::Event &event);
    void onWindowResized(sf::Event &event);
    
    void updateView();
};

#endif // CAMERA_HPP
