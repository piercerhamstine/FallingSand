#ifndef FLUIDSIM_HPP
#define FLUIDSIM_HPP

#include "SFML/Graphics.hpp"

#include <vector>
#include <utility>
#include <iostream>

enum class CellType
{
    Empty,
    Sand
};

struct Cell
{
    CellType type;
    sf::Color color;
};

class FluidSim : public sf::Drawable
{
public:
    FluidSim();
    FluidSim(int width, int height, int cellSize);

    void SetCell(int x, int y, CellType c);

    void Simulate();
private:
    virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates rStates) const;

    void SwapCells(int ndxa, int ndxb);
    // Returns the cell index at specified X and Y values.
    int GetIndex(int x, int y);
    // Returns if we are within the bounds of the world.
    bool ValidCellBounds(int x, int y);
    // Returns if the cell is empty.
    bool EmptyCell(int x, int y);

    int width;
    int height;

    sf::VertexArray vertices;

    std::vector<std::pair<int,int>> cellMoves;

    Cell* cells;
    Cell Sand={CellType::Sand, sf::Color(237,223,28)};
    Cell Empty={CellType::Empty, sf::Color(0,0,0)};
};

#endif