//
// Created by student on 02.06.2021.
//

#ifndef PROJECT_DOUBLEROOM_H
#define PROJECT_DOUBLEROOM_H
#include <TypeOfRoom.h>

class DoubleRoom : public TypeOfRoom{
private:
    float basePrice;
    int capacity;

public:
    float getBasePrice() override;
    int getCapacity() override;
};


#endif //PROJECT_DOUBLEROOM_H
