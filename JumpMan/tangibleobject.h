//
//  tangibleobject.h
//  JumpMan
//
//  Created by Samuel on 4/3/23.
//

#ifndef tangibleobject_h
#define tangibleobject_h
#include <stdio.h>

#include "position.h"

class TangibleObject {
public:
    TangibleObject(double x, double y);
    TangibleObject(double x, double y, double r, double g, double b);
    
    bool touches(const Position & other, double offset);
    virtual void updateAppearance() = 0;
    
    void setLength(double l) { length = l; }
    
    std::tuple<double, double, double> getColor() { return objectsColors; }
    double getLength()const { return length; }
    const Position getBottomLeft();
    const Position getUpperRight();
    
protected:
    void changeColor(double r, double g, double b);
    
private:
    std::tuple<double, double, double> objectsColors;
    Position ptObj;
    double length;
};

#endif /* tangibleobject_h */
