//
//  physics.cpp
//  Wall_Jumper
//
//  Created by Samuel on 3/14/23.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include "physics.h"

// Newton's Second Law of Motion
// F = m * a

double Physics::calculateForce(double m, double a)
{
    return m * a;
}

double Physics::calculateAcceleration(double f, double m)
{
    return f / m;
}

double Physics::calculateHorizontalComponent(double a, double s)
{
    return s * sin(a);
}

double Physics::calculateVerticalComponent(double a, double s)
{
    return s * cos(a);
}

double Physics::calculateAngleFromComponents(double dx, double dy)
{
    return atan(dx / dy);
}

// pythagorean theorem
// s^2 = dx^2 + dy^2

double Physics::calculateTotalVelocity(double dx, double dy)
{
    return sqrt((dx * dx) + (dy * dy));
}

double Physics::calculateDistance(double s, double v, double a, double t)
{
    return s + v * t + 0.5 * a * t * t;
}

double Physics::kinematicsEquation(double s, double a, double t)
{
    // s1
    return s + (a * t);
}

double Physics::linearInterpolationX(double y0, double y1, double x0, double x1, double y)
{
    if (y0 == y1)
    {
        return (x0 + x1) / 2.0;
    }
    else
    {
        return x0 + ((y - y0) * (x1 - x0) / (y1 - y0));
    }
}

double Physics::linearInterpolationY(double x0, double x1, double y0, double y1, double x)
{
    if (x0 == x1)
    {
        return (y0 + y1) / 2.0;
    }
    else
    {
        return y0 + ((x - x0) * (y1 - y0) / (x1 - x0));
    }
}
