#include<iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

//make a game field
int const Height = 20;
int const Weidth = 30;
int gameField[Height][Weidth] = { 0 };

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
    texture.loadFromFile("C:\\Users\\Дмитрий\\Desktop\\C++(+MVS)_обучение\\Tetris\\SpriteTry.bmp");

    Sprite sprite(texture);
    sprite.setTextureRect(IntRect(0, 0,18 , 18));

    int dx = 0;
    bool rotate = 0;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed);

            if (event.key.code == Keyboard::Up) rotate = true;

            if (event.key.code == Keyboard::Down);

            else if (event.key.code == Keyboard::Left) dx = -1;
            
            else if (event.key.code == Keyboard::Right) dx = 1;

        }

        for (int i=0;i<4;i++)
        {
            a[i].x += dx;
        }
        if (rotate)
        {
            Point p = a[2]; //the center of rotation

          

            for (int i=0;i<4;i++)
            {
                int x = a[i].y - p.y; // y - y0 
                int y = a[i].x - p.x; // x - x0
                a[i].x = p.x - x;
                a[i].y = p.y + y;
                /*
				   X = x_0 + (x − x_0) * cos⁡(a) −(y − y_0) * sin⁡(a);
				   Y = y_0 + (y − y_0) * cos⁡(a) + (x − x_0) * sin⁡(a);
				   a=90
				*/
            }
        }

        int n = 5;// type of tetramino, based on arrow Figures

        if(a[0].x == 0)
        
	        for (int i = 0;i<4;i++)
	        {
	        	a[i].x = Figures[n][i] % 2;
	        	a[i].y = Figures[n][i] / 2;

	        }
            dx = 0;
            rotate = 0;
        
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