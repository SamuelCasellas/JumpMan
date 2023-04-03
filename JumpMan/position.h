//
//  position.h
//  Wall_Jumper
//
//  Created by Samuel on 3/7/23.
//

#ifndef position_h
#define position_h

#pragma once

#include <iostream>
#include <cmath>

/*********************************************
 * Position
 * A single position on the field in Meters
 *********************************************/
class Position
{
public:
   

   // constructors
   Position() : x(0.0), y(0.0) {}
   Position(double x, double y);
   Position(const Position &pt) : x(pt.x), y(pt.y) {}
   Position(Position&& other);
    
   Position &operator=(const Position &pt);

   // getters
    double getX() const { return x; }
    double getY() const { return y;}

   // setters
   void setPosition(double x, double y)
   {
      this->x = x;
      this->y = y;
   }
   void setX(double x) { this->x = x; }
   void setY(double y) { this->y = y; }

   void addX(double x) { this->x += x; }
   void addY(double y) { this->y += y; }
    
private:
   double x; // horizontal position
   double y; // vertical position
};

/*********************************************
 * COMPUTE DISTANCE
 * Find the distance between two positions
 *********************************************/
inline double computeDistance(const Position &pos1, const Position &pos2)
{
   return sqrt((pos1.getX() - pos2.getX()) * (pos1.getX() - pos2.getX()) +
               (pos1.getY() - pos2.getY()) * (pos1.getY() - pos2.getY()));
}

void move();

// stream I/O useful for debugging
std::ostream &operator<<(std::ostream &out, const Position &pt);
std::istream &operator>>(std::istream &in, Position &pt);

/*********************************************
 * PT
 * Trivial point
 *********************************************/
struct PT
{
   double x;
   double y;
};


#endif /* position_h */
