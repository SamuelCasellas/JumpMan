//
//  uiDraw.cpp
//  Wall_Jumper
//
//  Created by Samuel on 3/7/23.
//

#include "uiDraw.h"

#include <string>  // need you ask?
#include <sstream> // convert an integer into text
#include <cassert> // I feel the need... the need for asserts
#include <time.h>  // for clock

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <openGL/gl.h> // Main OpenGL library
#include <GLUT/glut.h> // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_18
#endif // __APPLE__

#ifdef __linux__
#include <GL/gl.h>   // Main OpenGL library
#include <GL/glut.h> // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // __linux__

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h> // OpenGL library we copied
#define _USE_MATH_DEFINES
#include <math.h>
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // _WIN32

#include "position.h"
#include "uiDraw.h"

using namespace std;

/*************************************************************************
 * GL RESET COLOR
 * Just a more convenient way to reset the color
 *************************************************************************/
inline void glResetColor()
{
   glColor3f((GLfloat)0.0 /* red % */, (GLfloat)0.0 /* green % */, (GLfloat)0.0 /* blue % */);
}

/*************************************************************************
 * GL VERTEXT POINT
 * Just a more convenient format of glVertext2f
 *************************************************************************/
inline void glVertexPoint(const Position &pos)
{
   glVertex2f((GLfloat)pos.getX(), (GLfloat)pos.getY());
}

/*************************************************************************
 * DISPLAY the results on the screen
 *************************************************************************/
void ogstream ::flush()
{
   string sOut;
   string sIn = str();

   // copy everything but the newlines
   for (auto it = sIn.begin(); it != sIn.end(); ++it)
      // newline triggers an buffer flush and a move down
      if (*it == '\n')
      {
         drawText(pos, sOut.c_str());
         sOut.clear();
         pos.addX(-18);
      }
      // othewise append
      else
         sOut += *it;

   // put the text on the screen
   if (!sOut.empty())
   {
      drawText(pos, sOut.c_str());
      pos.addY(-18);
   }

   // reset the buffer
   str("");
}

/*************************************************************************
 * DRAW TEXT
 * Draw text using a simple bitmap font
 *   INPUT  topLeft   The top left corner of the text
 *          text      The text to be displayed
 ************************************************************************/
void ogstream ::drawText(const Position &topLeft, const char *text)
{
   void *pFont = GLUT_TEXT;

   // prepare to draw the text from the top-left corner
   glRasterPos2f((GLfloat)topLeft.getX(), (GLfloat)topLeft.getY());

   // loop through the text
   for (const char *p = text; *p; p++)
      glutBitmapCharacter(pFont, *p);
}

/************************************************************************
 * DRAW LINE
 * Draw a line on the screen from the beginning to the end.
 *   INPUT  begin     The position of the beginning of the line
 *          end       The position of the end of the line
 *          r/g/b     The color of the line to be drawn
 *************************************************************************/
void ogstream ::drawLine(const Position &begin, const Position &end,
                         double red, double green, double blue)
{
   // Get ready...
   glBegin(GL_LINES);
   glColor3f((GLfloat)red, (GLfloat)green, (GLfloat)blue);

   // Draw the actual line
   glVertexPoint(begin);
   glVertexPoint(end);

   // Complete drawing
   glResetColor();
   glEnd();
}

/************************************************************************
 * DRAW RECTRANGLE
 * Draw a rectangle on the screen from the beginning to the end.
 *   INPUT  begin     The position of the beginning of the line
 *          end       The position of the end of the line
 *          r/g/b     The color of the line to be drawn
 *************************************************************************/


void ogstream ::drawRectangle(const Position &begin, const Position &end,
                              double red, double green, double blue)
{
   // Get ready...
   glBegin(GL_QUADS);
   glColor3f((GLfloat)red, (GLfloat)green, (GLfloat)blue);

   // Draw the actual line
   glVertex2f((GLfloat)begin.getX(), (GLfloat)begin.getY());
   glVertex2f((GLfloat)begin.getX(), (GLfloat)end.getY());
   glVertex2f((GLfloat)end.getX(), (GLfloat)end.getY());
   glVertex2f((GLfloat)end.getX(), (GLfloat)begin.getY());

   // Complete drawing
   glResetColor();
   glEnd();
}

void ogstream::drawPlayer(const Position &begin, const Position &end,
                          double red, double green, double blue) {
    this->drawRectangle(begin, end, red, green, blue);
}

/***********************************************************************
 * DRAW Target
 * Draw a target on the screen at a given point
 *    point    The position of the target on the screen
 ***********************************************************************/
void ogstream ::drawTarget(const Position &pos)
{
   double size = 10.0;

   // set up to draw a solid rectangle
   glBegin(GL_QUADS);
   glColor3f((GLfloat)0.2 /* red % */, (GLfloat)0.75 /* green % */, (GLfloat)0.2 /* blue % */);

   // specify the corners
   glVertex2f((GLfloat)(pos.getX() - size / 2.0), (GLfloat)(pos.getY() - size / 2.0));
   glVertex2f((GLfloat)(pos.getX() - size / 2.0), (GLfloat)(pos.getY() + size / 2.0));
   glVertex2f((GLfloat)(pos.getX() + size / 2.0), (GLfloat)(pos.getY() + size / 2.0));
   glVertex2f((GLfloat)(pos.getX() + size / 2.0), (GLfloat)(pos.getY() - size / 2.0));

   // done
   glResetColor();
   glEnd();
}

/******************************************************************
 * RANDOM
 * This function generates a random number.
 *
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the integer
 ****************************************************************/
int random(int min, int max)
{
   assert(min < max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);

   return num;
}
