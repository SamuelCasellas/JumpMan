//
//  position.hpp
//  Wall_Jumper
//
//  Created by Samuel on 3/7/23.
//

#ifndef position_hpp
#define position_hpp

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
   double getMetersX() const { return x; }
   double getMetersY() const { return y; }
   double getPixelsX() const { return x / metersFromPixels; }
   double getPixelsY() const { return y / metersFromPixels; }

   // setters
   void setMeters(double xMeters, double yMeters)
   {
      x = xMeters;
      y = yMeters;
   }
   void setMetersX(double xMeters) { x = xMeters; }
   void setMetersY(double yMeters) { y = yMeters; }
   void setPixelsX(double xPixels) { x = xPixels * metersFromPixels; }
   void setPixelsY(double yPixels) { y = yPixels * metersFromPixels; }
   void addMetersX(double dxMeters) { setMetersX(getMetersX() + dxMeters); }
   void addMetersY(double dyMeters) { setMetersY(getMetersY() + dyMeters); }
   void addPixelsX(double dxPixels) { setPixelsX(getPixelsX() + dxPixels); }
   void addPixelsY(double dyPixels) { setPixelsY(getPixelsY() + dyPixels); }

   // deal with the ratio of meters to pixels
   void setZoom(double metersFromPixels)
   {
      this->metersFromPixels = metersFromPixels;
   }
   double getZoom() const { return metersFromPixels; }

private:
   double x; // horizontal position
   double y; // vertical position
   inline static double metersFromPixels = 0.1;
};

/*********************************************
 * COMPUTE DISTANCE
 * Find the distance between two positions
 *********************************************/
inline double computeDistance(const Position &pos1, const Position &pos2)
{
   return sqrt((pos1.getMetersX() - pos2.getMetersX()) * (pos1.getMetersX() - pos2.getMetersX()) +
               (pos1.getMetersY() - pos2.getMetersY()) * (pos1.getMetersY() - pos2.getMetersY()));
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


#endif /* position_hpp */
