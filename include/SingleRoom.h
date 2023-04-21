//
// Created by student on 02.06.2021.
//

#ifndef PROJECT_SINGLEROOM_H
#define PROJECT_SINGLEROOM_H
#include <TypeOfRoom.h>

class SingleRoom : public TypeOfRoom{
private:
    float basePrice;
    int capacity;

public:
    float getBasePrice() override;
    int getCapacity() override;
};


#endif //PROJECT_SINGLEROOM_H
