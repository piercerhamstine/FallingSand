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
            auto c = cells[i+j*width];
        };
    }

    // Update World
    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            // Get Cell
            auto c = cells[i+j*width];
            sf::Vertex* quad = &vertices[(i+j*width)*4];

            // Color tile
        };
    }
};

void FluidSim::draw(sf::RenderTarget& rTarget, sf::RenderStates rStates) const
{
    rTarget.draw(vertices, rStates);
};