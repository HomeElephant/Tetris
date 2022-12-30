#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 600), "SFML works!");
    sf::CircleShape shape(150.f);
   // shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);

        Texture texture;
        window.draw(shape);
        window.display();
    }

    return 0;
}