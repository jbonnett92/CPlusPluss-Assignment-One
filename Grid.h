/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grid.h
 * Author: Jbonnett
 *
 * Created on 10 March 2016, 16:08
 */

#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class Grid {
    public:
        //
        Grid();
        Grid(const Grid& orig);
        virtual ~Grid();
        
        // added by jbonnett
        Grid(int widthAndHeight, double cellSize);
        Grid(int width, int height, double cellSize);
        Grid(int width, int height, double cellSizeX, double cellSizeY);
        void setWidth(int width);
        int getWidth();
        void setHeight(int height);
        int getHeight();
        void setCellSizeX(double cellSize);
        double getCellSizeX();
        void setCellSizeY(double cellSize);
        double getCellSizeY();
        double getXDimensionsMin();
        double getXDimensionsMax();
        double getYDimensionsMin();
        double getYDimensionsMax();
        const char* getCell(int x, int y);
        void writeToGrid(int x, int y, const char* value);
        void printGrid();
        
    private:
        int width;
        int height;
        double cellSizeX;
        double cellSizeY;
        vector<vector<const char*> > grid;
        
        void tsleep(unsigned int mseconds);
};

#endif /* GRID_H */

