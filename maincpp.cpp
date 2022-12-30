#include <SFML/Graphics.hpp>
using namespace sf;

//make a game field
int const N = 20;
int const M = 30;
int gameField[N][M] = { 0 };

//make an arrow for tetramino
int Figures[7][4] =
{
    2,3,4,5,       //O
    3,4,5,7,       //T
    3,4,5,6,       //Z
    3,5,7,6,       //J
    2,4,6,7,       //L
    2,4,5,7,       //S
    0,2,4,6        //I
};
 
class Point
{
public:
    int x, y;
};
Point a[10], b[10];

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 600), "Tetris_Try");
  
    Texture texture;
    texture.loadFromFile("C:\\Users\\ƒмитрий\\Desktop\\C++(+MVS)_обучение\\Tetris\\SpriteTry.bmp");

    Sprite sprite(texture);
    sprite.setTextureRect(IntRect(0, 0, 18, 18));
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);

        texture.setRepeated(true);
        window.draw(sprite);
        window.display();
    }

    return 0;
}