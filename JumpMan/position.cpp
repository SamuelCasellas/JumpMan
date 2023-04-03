//
//  position.cpp
//  Wall_Jumper
//
//  Created by Samuel on 3/7/23.
//

#include "position.h"

Position::Position(double x, double y) : x(x), y(y) {}

/******************************************
 * POINT : ASSIGNMENT
 * Assign a point
 *****************************************/
Position &Position::operator=(const Position &pt)
{
   x = pt.x;
   y = pt.y;
   return *this;
}

Position::Position(Position&& other)
    : x(std::exchange(other.x, 0.0)),
      y(std::exchange(other.y, 0.0)) {}

/******************************************
 * For debugging
 *****************************************/
std::ostream &operator<<(std::ostream &out, const Position &pt) {
    out << "(" << pt.getX() << "," << pt.getY() << ")" << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, Position &pt) {
   double x;
   double y;
   in >> x >> y;

   pt.setX(x);
   pt.setY(y);

   return in;
}
