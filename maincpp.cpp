#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 600), "Tetris_Try");
   // sf::CircleShape shape(150.f);
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
        texture.loadFromFile("C:\\Users\\ƒмитрий\\Desktop\\C++(+MVS)_обучение\\Tetris\\SpriteTry.bmp");
        
        texture.setRepeated(true);

        Sprite sprite(texture,IntRect(0,0,400,198));
        window.draw(sprite);
        window.display();
    }

    return 0;
}