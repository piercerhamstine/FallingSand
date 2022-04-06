#ifndef FLUIDSIM_HPP
#define FLUIDSIM_HPP

#include "SFML/Graphics.hpp"

class FluidSim : public sf::Drawable
{
public:
    FluidSim();
    FluidSim(int width, int height);

    void Simulate();
private:
    virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates rStates) const;

    sf::Vector2f cellSize;
    
    sf::VertexArray vertices;

    // Cell Colors

};

#endif