/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Position.h
 * Author: Jbonnett
 *
 * Created on 10 March 2016, 16:43
 */

#ifndef POSITION_H
#define POSITION_H

class Position {
    public:
        Position();
        Position(const Position& orig);
        virtual ~Position();
        
        Position(double x, double y, int yaw);
        void setX(double x);
        double getX();
        void setY(double y);
        double getY();
        void setYaw(int yaw);
        int getYaw();
    private:
        double x;
        double y;
        int yaw;
};

#endif /* POSITION_H */

