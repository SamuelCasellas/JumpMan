//
//  door.h
//  JumpMan
//
//  Created by Samuel on 4/3/23.
//

#ifndef door_h
#define door_h

#include <stdio.h>

#include "tangibleobject.h"

class Door: public TangibleObject {
public:
    Door(double x, double y);
    
    void updateAppearance() override;
    void openDoor();
    bool isOpen()const { return open; }

private:
    bool open = false;
};

#endif /* door_h */
