/* 
 * File:   main.cpp
 * Author: Jab124@aber.ac.uk
 *
 * Created on 10 March 2016, 11:25
 */

#include <cstdlib>
#include "Grid.h"
#include "Robot.h"

/*
 * main()
 * 
 * runs the program in a specific order.
 * 
 */
int main(int argc, char** argv) {
    //Grid mainGrid(100, 50, 0.1, 0.2); // create a custom sized grid to print
    Grid mainGrid(50, 0.2); // create a square grid
    mainGrid.printGrid(); // print blank grid
    
    Robot mainRobot; // initiate the robot object
    mainRobot.getData("poses.txt", "ranges.txt");
    
    // get data and move robot as many times as there are lines in poses.txt and print grid at each stage
    for(int i = 0; i < mainRobot.getPoses().size(); i++) {
        mainRobot.moveRobot(&mainGrid); // moves the robot to the next position
        //mainRobot.addRobotPositionToGrid(&mainGrid); // adds the robots position to the grid
        mainRobot.detect(&mainGrid); // detects obstacles around the robot by reading all the sensors
        mainGrid.printGrid(); // print grid for each move for animated grid
    }
    
    //mainGrid.printGrid(); // print the full grid after all obstacles have been detected
    
    return 0;
}
