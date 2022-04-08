#include "FluidSim.hpp"

FluidSim::FluidSim(int width, int height, int cellSize)
{
    cells = new Cell[width*height]; 
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width*height*4);
    this->width = width;
    this->height = height;

    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            cells[i+j*width] = Empty;

            sf::Vertex* quad = &vertices[(i+j*width)*4];

            // Top left
            quad[0].position = sf::Vector2f(i*cellSize, j*cellSize);
            // Top right
            quad[1].position = sf::Vector2f((i+1)*cellSize, j*cellSize);
            // Bottom right
            quad[2].position = sf::Vector2f((i+1)*cellSize, (j+1)*cellSize);
            // Bottom left
            quad[3].position = sf::Vector2f(i*cellSize, (j+1)*cellSize);
        };
    };
};

void FluidSim::Simulate()
{
    // Simulate particles
    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            // Get Cell
            Cell& c = cells[i+j*width];

            // Quick implementation 
            if(c.type == CellType::Sand)
            {
                // move down
                if(ValidCellBounds(i, j+1) && EmptyCell(i, j+1))
                {
                    SetCell(i, j, CellType::Empty);
                    SetCell(i, j+1, CellType::Sand);
                };
                //if not then move left
                //if not then move right.

            };
            //
        };
    };

    // Update cells
    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            // Get Cell
            auto c = cells[i+j*width];
            sf::Vertex* quad = &vertices[(i+j*width)*4];

            // Color cell
            quad[0].color = quad[1].color = quad[2].color = quad[3].color = c.color;
        };
    }
};

void FluidSim::SetCell(int x, int y, CellType c)
{
    if(ValidCellBounds(x, y))
    {
        Cell& cell = cells[x+y*width];

        switch(c)
        {
            case CellType::Sand:
            {
                cell = Sand;
                break;
            };
            case CellType::Empty:
            {
                cell = Empty;
                break;
            };
        };
    };
};

bool FluidSim::ValidCellBounds(int x, int y)
{
    if((x >= 0 && x < width) && (y >= 0 && y < height))
        return true;
    return false;
};

bool FluidSim::EmptyCell(int x, int y)
{
    Cell& cell = cells[x+y*width];
    if(cell.type == CellType::Empty)
        return true;
    return false;
};

void FluidSim::draw(sf::RenderTarget& rTarget, sf::RenderStates rStates) const
{
    rTarget.draw(vertices, rStates);
};