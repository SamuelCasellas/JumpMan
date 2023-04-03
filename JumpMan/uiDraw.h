//
//  uiDraw.h
//  Wall_Jumper
//
//  Created by Samuel on 3/7/23.
//

#ifndef uiDraw_h
#define uiDraw_h
/***********************************************************************
 * Header File:
 *    User Interface Draw : put pixels on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This is the code necessary to draw on the screen. We have a collection
 *    of procedural functions here because each draw function does not
 *    retain state. In other words, they are verbs (functions), not nouns
 *    (variables) or a mixture (objects)
 ************************************************************************/

#pragma once

#include <string>
#include <cmath>
#include <algorithm>
#include "position.h"

using std::max;
using std::min;
using std::string;

/*************************************************************************
 * DRAW TEXT
 * Draw text using a simple bitmap font
 ************************************************************************/

#include <sstream>

/*************************************************************************
 * GRAPHICS STREAM
 * A graphics stream that behaves much like COUT except on a drawn screen
 *************************************************************************/
class ogstream : public std::ostringstream
{
public:
   ogstream() : pos() {}
   ogstream(const Position &pos) : pos(pos) {}
   ~ogstream() { flush(); }

   // Methods specific to drawing text on the screen
   virtual void flush();
   void setPosition(const Position &pos)
   {
      flush();
      this->pos = pos;
   }
   ogstream &operator=(const Position &pos)
   {
      setPosition(pos);
      return *this;
   }

   // Specific methods for the game
   virtual void drawLine(const Position &begin, const Position &end,
                         double red = 0.0, double green = 0.0, double blue = 0.0);
   virtual void drawRectangle(const Position &begin, const Position &end,
                              double red = 0.0, double green = 0.0, double blue = 0.0);
   virtual void drawPlayer(const Position &begin, const Position &end,
                           double red = 0.0, double green = 0.0, double blue = 0.0);
   virtual void drawTarget(const Position &pos);
   virtual void drawText(const Position &topLeft, const char *text);

private:
   Position rotate(const Position &origin, double x, double y, double rotation);
   Position pos;
};

/******************************************************************
 * RANDOM
 * This function generates a random number.  The user specifies
 * The parameters
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the integer/double
 ****************************************************************/
int random(int min, int max);
double random(double min, double max);

#include <cassert>

/*************************************************************************
 * GRAPHICS STREAM DUMMY
 * A dummy graphics scream provided for the purpose of creating unit tests
 *************************************************************************/
class ogstreamDummy : public ogstream
{
public:
   ogstreamDummy() {}
   ~ogstreamDummy() { str(""); }
   void flush() { assert(false); }
   void drawLine(const Position &begin, const Position &end,
                 double red = 0.0, double green = 0.0, double blue = 0.0) { assert(false); }
   void drawRectangle(const Position &begin, const Position &end,
                      double red = 0.0, double green = 0.0, double blue = 0.0) { assert(false); }
   void drawProjectile(const Position &pos, double age = 0.0) { assert(false); }
   void drawPlayer(const Position &pos, double angle, double age) { assert(false); }
   void drawTarget(const Position &pos) { assert(false); }
   void drawText(const Position &topLeft, const char *text) { assert(false); }
};

#include <stdio.h>

#endif /* uiDraw_h */
