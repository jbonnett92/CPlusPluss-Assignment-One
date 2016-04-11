/* 
 * File:   Grid.cpp
 * Author: Jab124@aber.ac.uk
 * 
 * Created on 10 March 2016, 16:08
 */

#include "Grid.h"

/*
 * Constructors
 */

Grid::Grid() { };

Grid::Grid(const Grid& orig) { };

Grid::~Grid() { };

/*
 * Grid(int, double)
 * 
 * initiates a new grid with a set width and height that are the same.
 * the cell width and height size will also be the same
 * 
 */
Grid::Grid(int widthAndHeight, double cellSize) {
    this->width = widthAndHeight;
    this->height = widthAndHeight;
    this->cellSizeX = cellSize;
    this->cellSizeY = cellSize;
    grid.resize(height, std::vector<const char*>(width));
};

/*
 * Grid(int, int, double)
 * 
 * initiates a new grid with a set width and height that are different.
 * the cell width and height size will be the same
 * 
 */
Grid::Grid(int width, int height, double cellSize) {
    this->width = width;
    this->height = height;
    this->cellSizeX = cellSize;
    this->cellSizeY = cellSize;
    grid.resize(height, std::vector<const char*>(width));
};

/*
 * Grid(int, int, double, double)
 * 
 * initiates a new grid with a set width and height that are different.
 * the cell width and height size that are different.
 * 
 */
Grid::Grid(int width, int height, double cellSizeX, double cellSizeY) {
    this->width = width;
    this->height = height;
    this->cellSizeX = cellSizeX;
    this->cellSizeY = cellSizeY;
    grid.resize(height, std::vector<const char*>(width));
};
    
/*
 * functions
 */

/*
 * setWidth(int)
 * 
 * Change the width of the grid.
 * 
 */
void Grid::setWidth(int width) {
    this->width = width;
    grid.resize(height, std::vector<const char*>(width));
};

/*
 * getWidth(int)
 * 
 * Get the width of the grid.
 * 
 */
int Grid::getWidth() {
    return width;
};

/*
 * setHeight(int)
 * 
 * Change the height of the grid.
 * 
 */
void Grid::setHeight(int height) {
    this->height = height;
    grid.resize(height, std::vector<const char*>(width));
};

/*
 * getHeight(int)
 * 
 * Get the height of the grid.
 * 
 */
int Grid::getHeight() {
    return height;
};

/*
 * setCellSizeX(double)
 * 
 * Change the width of the cell size.
 * 
 */
void Grid::setCellSizeX(double cellSize) {
    this->cellSizeX = cellSize;
};

/*
 * getCellSizeX(double)
 * 
 * Get the width of the cell size.
 * 
 */
double Grid::getCellSizeX() {
    return cellSizeX;
};

/*
 * setCellSizeY(double)
 * 
 * Change the height of the cell size.
 * 
 */
void Grid::setCellSizeY(double cellSize) {
    this->cellSizeX = cellSize;
};

/*
 * getCellSizeY(double)
 * 
 * Get the height of the cell size.
 * 
 */
double Grid::getCellSizeY() {
    return cellSizeY;
};

/*
 * getXDimensionsMin()
 * 
 * Gets the real coordinates of the X axis.
 * e.g. 50 cells at a cell size of 0.2 would be -0.1.
 * 
 */
double Grid::getXDimensionsMin() {
    return 0 - (cellSizeX / 2);
};

/*
 * getXDimensionsMax()
 * 
 * Gets the real coordinates of the X axis.
 * e.g. 50 cells at a cell size of 0.2 would be 9.9.
 * 
 */
double Grid::getXDimensionsMax() {
    return (width * cellSizeX) - (cellSizeX / 2);
};

/*
 * getYDimensionsMin()
 * 
 * Gets the real coordinates of the Y axis.
 * e.g. 50 cells at a cell size of 0.2 would be -0.1.
 * 
 */
double Grid::getYDimensionsMin() {
    return 0 - (cellSizeY / 2);
};

/*
 * getYDimensionsMax()
 * 
 * Gets the real coordinates of the X axis.
 * e.g. 50 cells at a cell size of 0.2 would be 9.9.
 * 
 */
double Grid::getYDimensionsMax() {
    return (height * cellSizeY) - (cellSizeY / 2);
};

/*
 * getCell(int, int)
 * 
 * Gets the current value of a cell.
 * 
 */
const char* Grid::getCell(int x, int y) {
    return grid.at(y).at(x);
};

/*
 * writeToGrid(int, int, const char*)
 * 
 * Sets a value of a cell.
 * 
 */
void Grid::writeToGrid(int x, int y, const char* value) {
    grid.at(y).at(x) = value;
};

/*
 * printGrid()
 * 
 * Prints the 2d array in a grid format.
 * 
 */
void Grid::printGrid() {
    // generate first line
    std::cout << "+";
    for(int i = 0; i < width; i++) std::cout << "-";
    std::cout << "+" << std::endl;
    
    // generate everything in between
    for(int x = grid.size() - 1; x >= 0; x--) {
        std::cout << "|";
        for(int y = 0; y < grid.at(x).size(); y++) {
            if(grid.at(x).at(y)) {
                std::cout << grid.at(x).at(y);
            } else {
                std::cout << " ";
            }
        }
        std::cout << "|" << std::endl;
    }
    
    // generate last line
    std::cout << "+";
    for(int i = 0; i < width; i++) std::cout << "-";
    std::cout << "+" << std::endl;
    tsleep(500);
};

/*
 * tsleep(unsigned int)
 * 
 * Delays the program x milliseconds.
 * 
 */
void Grid::tsleep(unsigned int mseconds) {
    clock_t goal = (mseconds * 1000) + clock();
    while(goal > clock());
}
