#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "FluidSim.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    FluidSim f(50, 50);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        f.Simulate();

        window.clear();
        window.draw(f);
        window.display();
    }

    return 0;
}