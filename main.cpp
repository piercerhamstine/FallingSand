#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "FluidSim.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Particles");
    sf::Clock clock;
    FluidSim f(100, 100, 1);

    sf::Time totalTime;
    sf::Time timeSinceLastFrame;
    while (window.isOpen())
    {
        timeSinceLastFrame = clock.restart();
        totalTime += timeSinceLastFrame;

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