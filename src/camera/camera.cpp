#include <camera.hpp>

Camera::Camera() {
    this->_view = new sf::View();
}

Camera::Camera(sf::RenderWindow *window) {
    Camera();

    this->setRenderWindow(window);
}

void Camera::setRenderWindow(sf::RenderWindow *window) {
    this->_window = window;

    sf::Vector2f windowSize = (sf::Vector2f) window->getSize();

    this->_view->setSize(windowSize);
    this->_view->setCenter(windowSize / 2.f);

    this->_oldWindowSize = (sf::Vector2f) window->getSize();
    this->_oldViewSize = windowSize;
}

void Camera::onMousePressed(sf::Event &event) {
    if (event.mouseButton.button == sf::Mouse::Middle) {
        this->_startingMousePos = (sf::Vector2f) sf::Mouse::getPosition(*this->_window);
        this->_startingViewCenter = this->_window->getView().getCenter();
    }
}

void Camera::onMouseWheelScrolled(sf::Event &event) {
     // Zoom in and out of the view
    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
        sf::View view = this->_window->getView();

        view.zoom(std::exp(-event.mouseWheelScroll.delta / SCROLL_FACTOR)); // Exponential function to normalize input to 0 to inf

        this->_window->setView(view);

        this->_oldViewSize = view.getSize();
    }
}

void Camera::onWindowResized(sf::Event &event) {
    // Change the view accordingly to show the same scale

    sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
    this->_window->setView(sf::View(visibleArea));
}

void Camera::updateView() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) { // View movement
        sf::View view = this->_window->getView();

        sf::Vector2f currMousePos = (sf::Vector2f) sf::Mouse::getPosition(*this->_window);
        sf::Vector2f vectorStartToNow = currMousePos - this->_startingMousePos;

        vectorStartToNow.x *= view.getSize().x / (float) this->_window->getSize().x; // Scale the movement because of the zoom
        vectorStartToNow.y *= view.getSize().y / (float) this->_window->getSize().y;

        view.setCenter(this->_startingViewCenter - vectorStartToNow);

        this->_window->setView(view);
    }
}