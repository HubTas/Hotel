//
// Created by student on 02.06.2021.
//

#ifndef PROJECT_TRIPLEROOM_H
#define PROJECT_TRIPLEROOM_H
#include <TypeOfRoom.h>

class TripleRoom : public TypeOfRoom{
private:
    float basePrice;
    int capacity;

public:
    float getBasePrice() override;
    int getCapacity() override;
};

#endif //PROJECT_TRIPLEROOM_H

