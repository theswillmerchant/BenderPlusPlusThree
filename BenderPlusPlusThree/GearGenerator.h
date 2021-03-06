//
//  GearGenerator.h
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 4/26/16.
//  Copyright (c) 2016 Ben Lewson. All rights reserved.
//

#ifndef __BenderPlusPlusThree__GearGenerator__
#define __BenderPlusPlusThree__GearGenerator__

#include <iostream>
#include "SvgPacker.h"

//Stores gear profile and size info
struct gear_t
{
    int numberOfTeeth;
    double toothHeight;
    double rootRadius;
};

class GearGenerator
{
public:
    //Constructor
    GearGenerator(bool pressureAngleTwenty = true);
    
    //Sets shaft diameter (and minimum gear diameter) for further calculations until changed
    void setShaftDiameter(double shaftDiameter);
    
    //Sets gear pitch
    void setGearPitch(int pitch);
    
    //Generates tooth counts from center to center distance and
    vector<int> calcToothCounts(double centerDistance, double desiredRatio);
    
    //Generates gear profile parameters based on distance from center to center
    //and desired gear ratio. Ratio is Driving:Driven. Return is <Driving, Driven>
    vector<gear_t> calculateTooth(double centerDistance, double desiredRatio);
    
    //Creates a gear struct from number of teeth and preset info
    gear_t generateGear(int numberOfTeeth);
    
    //Calls SvgPacker to draw completed gear
    string drawGear (gear_t profile);
    
    
private:
    //Pitch for gear system
    int _pitch;
    //Shaft Diameter
    double _shaftDiameter;
    //Pressure angle, true = 20, false = 14.5
    bool _pressureAngle;
    //Temporary storage vector
    vector<double> _tempStorage;
    
};


#endif /* defined(__BenderPlusPlusThree__GearGenerator__) */
