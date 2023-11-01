// Engine Bing X2d.cpp: 定义应用程序的入口点。
//

#include "main.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    std::cout << a(50, 60) << std::endl;
    sf::RenderWindow window(sf::VideoMode(200, 200), L"我是标题");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
