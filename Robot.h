/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Robot.h
 * Author: Jbonnett
 *
 * Created on 10 March 2016, 15:27
 */

#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include "Sensor.h"
#include "Grid.h"
#include "Position.h"

using namespace std;

class Robot {
    public:
        // added automatically
        Robot();
        Robot(const Robot& orig);
        virtual ~Robot();
        
        // added by jbonnett
        
        /*! New Robot object.
          \sa Robot()
          \param posX the position of the robot on the grid x axis.
          \param posY the position of the robot on the grid y axis.
          \param yaw the rotation of the robot.
        */
        Robot(int posX, int posY, int yaw);
        void setPositionX(double posX);
        double getPositionX();
        void setPositionY(double posY);
        double getPositionY();
        void setYaw(double yaw);
        int getYaw();
        void setSensorValue(int sensor, double sensorValue);
        double getSensorValue(int sensor);
        Sensor* getSensor(int sensor);
        void setSensorYaw(int sensor, int sensorValue);
        int getSensorYaw(int sensor);
        void setSensor(int sensor, Sensor* newSensor);
        int countSensors();
        void detect(Grid* grid);
        void moveRobot(Grid* grid);
        void addRobotPositionToGrid(Grid* grid);
        void setPoses(vector<Position*> poses);
        vector<Position*> getPoses();
        void getData(string posesFileLocation, string rangesFileLocation);
        
    private:
        double posX;
        double posY;
        int yaw;
        vector<Sensor*> sensors;
        vector<Position*> posesArr;
        vector<vector<double> > rangesArr;
        int moves;
        
        double degreesToRadians(double degrees);

};

#endif /* ROBOT_H */

