//
// Created by student on 05.06.2021.
//

#ifndef PROJECT_ROOMREPOSITORY_H
#define PROJECT_ROOMREPOSITORY_H
#include "Repository.h"
#include <typedefs.h>
#include <Room.h>

class RoomRepository: public Repository<Room> {
    RoomRepositoryPtr rooms;
public:
    RoomPtr findByRoomNumber(int roomNumber);
};


#endif //PROJECT_ROOMREPOSITORY_H
