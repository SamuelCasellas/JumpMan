//
//  Physics.h
//  Lab07
//
//  Created by Samuel on 3/14/23.
//

#ifndef Physics_h
#define Physics_h

#include "position.h"

/**************************************************
 *
 *                 PHYSICS CLASS
 *
 * All functions are static since there are no member variables.
 *********************************************************************************/
class Physics
{
public:
    static double calculateAcceleration(double f, double m);
    static double calculateForce(double m, double a);
    static double calculateHorizontalComponent(double a, double s);
    static double calculateVerticalComponent(double a, double s);
    static double calculateAngleFromComponents(double dx, double dy);
    static double calculateTotalVelocity(double dx, double dy);
    static double calculateDistance(double s, double v, double a, double t);

    static double kinematicsEquation(double s, double a, double t);
};

#endif /* Physics_h */
