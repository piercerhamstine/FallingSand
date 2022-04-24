#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "FluidSim.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Particles");
    sf::Clock clock;
    FluidSim f(200, 200, 1);

    f.SetCell(10,0, CellType::Sand);

    sf::Time totalTime;
    sf::Time timeSinceLastFrame;


    CellType currType = CellType::Sand;
    while (window.isOpen())
    {
        timeSinceLastFrame = clock.restart();
        totalTime += timeSinceLastFrame;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1)
            {
                currType = CellType::Sand;
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2)
            {
                currType = CellType::Water;
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num3)
            {
                currType = CellType::Stone;
            }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            f.SetCell(pos.x, pos.y, currType);
        };

        f.Simulate();        

        window.clear();
        window.draw(f);
        window.display();
    }

    return 0;
}