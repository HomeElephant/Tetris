#include <SFML/Graphics.hpp>
using namespace sf;

//make a game field
int const H = 20;
int const W = 30;
int gameField[H][W] = { 0 };

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
    sprite.setTextureRect(IntRect(0, 0,18 , 18));
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        int n = 3;
        for (int i = 0;i<4;i++)
        {
            a[i].x = Figures[n][i] % 2;
            a[i].x = Figures[n][i] / 2;

        }
        window.clear(Color::White);

        for (int i=0;i<4;i++)
        {
            sprite.setPosition(a[i].x * 18, a[i].y * 18);

            window.draw(sprite);

        }
        // texture.setRepeated(true);
        
        window.display();
    }

    return 0;
}