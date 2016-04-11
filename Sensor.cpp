/* 
 * File:   Sensor.cpp
 * Author: Jab124@aber.ac.uk
 * 
 * Created on 10 March 2016, 15:38
 */

#include "Sensor.h"

/*
 * Constructors
 */

Sensor::Sensor() { };

Sensor::Sensor(const Sensor& orig) { };

Sensor::~Sensor() { };

/*
 * Sensor(double, int)
 * 
 * initiates a new sensor with a value and direction.
 * 
 */
Sensor::Sensor(double value, int directionYaw) {
    this->value = value;
    this->directionYaw = directionYaw;
    //this->viewWidth = viewWidth;
};
    
/*
 * functions
 */

/*
 * setValue(double)
 * 
 * Changes the value of a sensor.
 * 
 */
void Sensor::setValue(double value) {
    this->value = value;
};
    
/*
 * getValue(double)
 * 
 * Gets the value of a sensor.
 * 
 */
double Sensor::getValue() {
    return value;
};

/*
 * setValue(double)
 * 
 * Changes the direction of a sensor.
 * 
 */
void Sensor::setYaw(int yaw) {
    this->directionYaw = yaw;
};

/*
 * getValue(double)
 * 
 * Get the direction of a sensor.
 * 
 */
int Sensor::getYaw() {
    return directionYaw;
};
