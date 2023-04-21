//
// Created by student on 02.06.2021.
//

#ifndef PROJECT_TYPEOFROOM_H
#define PROJECT_TYPEOFROOM_H
#include <string>
#include "typedefs.h"
#include <Client.h>


class TypeOfRoom {
public:
    virtual float getBasePrice() = 0;
    virtual int getCapacity() = 0;
};

#endif //PROJECT_TYPEOFROOM_H
