//
//  key.h
//  JumpMan
//
//  Created by Samuel on 4/3/23.
//

#ifndef key_h
#define key_h

#include <stdio.h>

#include "tangibleobject.h"
#include "door.h"

class Key: public TangibleObject {
public:
    Key(double x, double y);
    
    void updateAppearance() override;
    
    void openDoor(Door &d);
};

#endif /* key_h */
