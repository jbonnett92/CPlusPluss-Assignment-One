/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sensor.h
 * Author: Jbonnett
 *
 * Created on 10 March 2016, 15:38
 */

#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
    public:
        // added automatically
        Sensor();
        Sensor(const Sensor& orig);
        virtual ~Sensor();
        
        // added by jbonnett
        Sensor(double value, int directionYaw);
        void setValue(double value);
        double getValue();
        void setYaw(int value);
        int getYaw();
        
    private:
        double value;
        int directionYaw; // in degrees
        int viewWidth; // in degrees
};

#endif /* SENSOR_H */

