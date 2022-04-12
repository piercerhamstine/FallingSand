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
            cells[GetIndex(i,j)] = Empty;

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

int FluidSim::GetIndex(int x, int y)
{
    return (x+y*width);
}

void FluidSim::Simulate()
{
    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            Cell& c = cells[GetIndex(i,j)];

            // Quick implementation 
            if(c.type == CellType::Sand)
            {
                // move down
                if(ValidCellBounds(i, j+1) && EmptyCell(i, j+1))
                {
                    cellMoves.emplace_back(GetIndex(i, j), GetIndex(i, j+1));
                }
                //if not then move down left
                else if(ValidCellBounds(i-1, j+1) && EmptyCell(i-1, j+1))
                {
                    cellMoves.emplace_back(GetIndex(i, j), GetIndex(i-1, j+1));
                }
                //if not then move down right.
                else if(ValidCellBounds(i+1, j+1) && EmptyCell(i+1, j+1))
                {
                    cellMoves.emplace_back(GetIndex(i, j), GetIndex(i+1, j+1));
                }
            };
            //
        };
    };
    
    for(int i = 0; i < cellMoves.size(); ++i)
    {
        SwapCells(cellMoves[i].first, cellMoves[i].second);
    }
    cellMoves.clear();

    // Update cells
    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            auto c = cells[GetIndex(i, j)];
            sf::Vertex* quad = &vertices[(i+j*width)*4];

            quad[0].color = quad[1].color = quad[2].color = quad[3].color = c.color;
        };
    }
};

void FluidSim::SwapCells(int ndxa, int ndxb)
{
    auto temp = cells[ndxb];
    cells[ndxb] = cells[ndxa];
    cells[ndxa] = temp;
};

void FluidSim::SetCell(int x, int y, CellType c)
{
    if(ValidCellBounds(x, y))
    {
        Cell& cell = cells[GetIndex(x,y)];

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
    Cell& cell = cells[GetIndex(x,y)];
    if(cell.type == CellType::Empty)
        return true;
    return false;
};

void FluidSim::draw(sf::RenderTarget& rTarget, sf::RenderStates rStates) const
{
    rTarget.draw(vertices, rStates);
};