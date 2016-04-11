/* 
 * File:   Position.cpp
 * Author: Jab124@aber.ac.uk
 * 
 * Created on 10 March 2016, 16:43
 */

#include "Position.h"

/*
 * Constructors
 */

Position::Position() {
}

Position::Position(const Position& orig) {
}

Position::~Position() {
}

/*
 * Position(double, double, int)
 * 
 * initiates a new position with x, y coordinates along with yaw / rotation.
 * 
 */
Position::Position(double x, double y, int yaw) {
    this->x = x;
    this->y = y;
    this->yaw = yaw;
};

/*
 * setX(double)
 * 
 * Changes the x axis position.
 * 
 */
void Position::setX(double x) {
    this->x = x;
};

/*
 * getX()
 * 
 * Gets the x axis position.
 * 
 */
double Position::getX() {
    return x;
};

/*
 * setY(double)
 * 
 * Changes the y axis position.
 * 
 */
void Position::setY(double y) {
    this->y = y;
};

/*
 * getY()
 * 
 * Gets the y axis position.
 * 
 */
double Position::getY() {
    return y;
};

/*
 * setYaw(double)
 * 
 * Changes the yaw / rotation.
 * 
 */
void Position::setYaw(int yaw) {
    this->yaw = yaw;
};

/*
 * getYaw()
 * 
 * Gets the yaw / rotation.
 * 
 */
int Position::getYaw() {
    return yaw;
};
