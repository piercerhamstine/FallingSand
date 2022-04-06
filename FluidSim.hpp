#ifndef FLUIDSIM_HPP
#define FLUIDSIM_HPP

#include "SFML/Graphics.hpp"

enum class CellType
{
    Empty,
    Sand
};

struct Cell
{
    CellType type;
    sf::Color c;
};

class FluidSim : public sf::Drawable
{
public:
    FluidSim();
    FluidSim(int width, int height, int cellSize);

    void Simulate();
private:
    virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates rStates) const;

    int width;
    int height;

    sf::VertexArray vertices;

    Cell* cells;
};

#endif