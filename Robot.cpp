/* 
 * File:   Robot.cpp
 * Author: Jbonnett
 * 
 * Created on 10 March 2016, 15:27
 */

#include "Robot.h"

/*
 * Constructors
 */

Robot::Robot() { 
    moves = 0; // initiate the moves variable
};

Robot::Robot(const Robot& orig) { };

Robot::~Robot() { };
    
/*
 * Robot(int, int, int)
 * 
 * initiates a new robot with a position x, y and a yaw / rotation.
 * 
 */
Robot::Robot(int posX, int posY, int yaw) {
    this->posX = posX;
    this->posY = posY;
    this->yaw = yaw;
    moves = 0;
};
    
/*
 * functions
 */

/*
 * setPositionX(double)
 * 
 * Changes the position of the robot on the X axis.
 * 
 */
void Robot::setPositionX(double posX) {
    this->posX = posX;
};

/*
 * getPositionX(double)
 * 
 * Gets the position of the robot on the X axis.
 * 
 */
double Robot::getPositionX() {
    return posX;
};

/*
 * setPositionY(double)
 * 
 * Changes the position of the robot on the Y axis.
 * 
 */
void Robot::setPositionY(double posY) {
    Robot::posY = posY;
};

/*
 * getPositionY(double)
 * 
 * Gets the position of the robot on the Y axis.
 * 
 */
double Robot::getPositionY() {
    return posY;
};

/*
 * setYaw()
 * 
 * Changes the yaw / rotation of the robot.
 * 
 */
void Robot::setYaw(double yaw) {
    this->yaw = yaw;
};

/*
 * getYaw()
 * 
 * Gets the yaw / rotation of the robot.
 * 
 */
int Robot::getYaw() {
    return yaw;
};

/*
 * setSensorValue(int, double)
 * 
 * Changes a particular sensors value / range.
 * 
 */
void Robot::setSensorValue(int sensor, double sensorValue) {
    sensors.at(sensor)->setValue(sensorValue);
};

/*
 * getSensorValue(int)
 * 
 * Gets a particular sensors value / range.
 * 
 */
double Robot::getSensorValue(int sensor) {
    return sensors.at(sensor)->getValue();
};

/*
 * setSensorYaw(int, int)
 * 
 * Changes a particular sensors yaw / rotation.
 * 
 */
void Robot::setSensorYaw(int sensor, int sensorYaw) {
    sensors.at(sensor)->setValue(sensorYaw);
};

/*
 * getSensorYaw(int)
 * 
 * Gets a particular sensors yaw / rotation.
 * 
 */
int Robot::getSensorYaw(int sensor) {
    return sensors.at(sensor)->getYaw();
};

/*
 * getSensor(int)
 * 
 * Gets a particular sensor object.
 * 
 */
Sensor* Robot::getSensor(int sensor) {
    return sensors.at(sensor);
};

/*
 * setSensor(int, Sensor*)
 * 
 * Changes / creates a particular sensor object.
 * 
 */
void Robot::setSensor(int sensor, Sensor* newSensor) {
    if(sensors.empty()) {
        sensors.push_back(newSensor); // add new sensor object
    } else if(!(sensor >= sensors.size())) {
        // replace sensor object
        sensors.erase((sensors.begin() + sensor) - 1); // delete object position
        sensors.insert(sensors.begin() + sensor, newSensor); // add new object to that position
    } else {
        sensors.push_back(newSensor); // Add a new sensor object
    }
};

/*
 * countSensors()
 * 
 * Counts sensor objects.
 * 
 */
int Robot::countSensors() {
    return sensors.size();
}

/*
 * degreesToRadians(double)
 * 
 * Converts degrees to radians.
 * 
 */
double Robot::degreesToRadians(double degrees) {
    return degrees * (M_PI / 180.0);
};

/*
 * detect(Grid*)
 * 
 * Detects obstacles via all sensor objects.
 * 
 */
void Robot::detect(Grid* grid) {
    double robotx = posX / grid->getCellSizeX(); // robot position x
    double roboty = posY / grid->getCellSizeY(); // robot position y
    double robotYawRad = degreesToRadians(yaw); // robot yaw / rotation
    
    // loop sensors vector
    for(int i = 0; i < sensors.size(); i++) {
        double sensorValueX = sensors.at(i)->getValue() / grid->getCellSizeX(); // sensor value / range on the x axis
        double sensorValueY = sensors.at(i)->getValue() / grid->getCellSizeY(); // sensor value / range on the Y axis
        double sensorYawRad = degreesToRadians(sensors.at(i)->getYaw()); // sensor yaw / rotation

        int x = floor(robotx + sensorValueX * cos(sensorYawRad + robotYawRad)); // calculate triggernometry for the x axis
        int y = floor(roboty + sensorValueY * sin(sensorYawRad + robotYawRad)); // calculate triggernometry for the y axis

        // check if obstacle in bounds of the grid and less that 2.5 distance
        if(getSensorValue(i) < 2.5 && 
                x >= 0 && y >= 0 && 
                x < grid->getWidth() && y < grid->getHeight()) 
        {
            const char* c = "*";
            grid->writeToGrid(x, y, c); // add obstacle to grid
        }
    }
};

/*
 * moveRobot(Grid*)
 * 
 * Sets up the robot data for the next lot of values.
 * 
 */
void Robot::moveRobot(Grid* grid) {
    // loops through the positions vector
    if(moves < posesArr.size()) {
        // set robot positions
        Position* pos = posesArr.at(moves); // Gets the present position from the positions vector
        setPositionX(pos->getX()); // sets the new robots position on the x axis
        setPositionY(pos->getY()); // sets the new robots position on the y axis
        setYaw(pos->getYaw()); // sets the new robots yaw / rotation
        
        // set sensors
        sensors.clear(); // delete all object from the sensors vector
        vector<double> d = rangesArr.at(moves); // Gets the present sensor ranges from the ranges vector
        
        // loops through the present sensor ranges
        for(int i = 0; i < d.size(); i++) {
            setSensor(i, new Sensor(d.at(i), ((360 / d.size()) * i))); // add sensor data to the sensors vector
        }
        
        moves++; // increment amount of moves
    }
};

/*
 * addRobotPositionToGrid(Grid*)
 * 
 * Adds a robot char to the grid for viewing.
 * 
 */
void Robot::addRobotPositionToGrid(Grid* grid) {
    int x = floor(posX / grid->getCellSizeX()); // get x axis coordinate
    int y = floor(posY / grid->getCellSizeY()); // get y axis coordinate
    
    const char* c = "\u23B5"; // set the char to add the grid
    //char c = '\u23B5';
    
    grid->writeToGrid(x, y, c); // add it to the grid
};

/*
 * setPoses(vector<Position*>)
 * 
 * Replaces the positions vector with a new vector.
 * 
 */
void Robot::setPoses(vector<Position*> poses) {
    this->posesArr = poses;
};

/*
 * getPoses()
 * 
 * Gets the positions vector.
 * 
 */
vector<Position*> Robot::getPoses() {
    return posesArr;
};

/*
 * getData(string, string)
 * 
 * Gets all new robot / sensor data from text file and stores it into objects.
 * 
 */
void Robot::getData(string posesFileLocation, string rangesFileLocation) {
    // read and store poses file
    ifstream poses;
    poses.open(posesFileLocation, ifstream::in);
    double x, y;
    int yaw;
    while(!poses.eof()) {
        if(poses.eof()){
            break;
        }
        poses >> x >> y >> yaw;
        Position* pos = new Position(x, y, yaw);
        posesArr.push_back(pos);
    }
    
    // read and store ranges file
    ifstream ranges;
    ranges.open(rangesFileLocation, ifstream::in); // open new stream for reading file
    double sensorValue; // temp sensor value variable
    while(!ranges.eof()) {
        // check that we are not at the end of the file
        if(ranges.eof()){
            break;
        }
        
        string line; // temp line 
        getline(ranges, line); // read the line
        int numOfSensors = count(line.begin(), line.end(), ' '); // count number of sensors on current line
        istringstream lineOfSensors(line); // make new stream of for the current line to get types
        vector<double> tempVector; // create a tempory vector array

        // read values of each sensor and add them to the vector array
        for(int i = 0; i <= numOfSensors; i++) {
            lineOfSensors >> sensorValue;
            tempVector.push_back(sensorValue);
        }

        rangesArr.push_back(tempVector); // add temp vector array to main vector array
    }
}