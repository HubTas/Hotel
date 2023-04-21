//
// Created by student on 07.06.2021.
//

#ifndef PROJECT_ROOMMANAGER_H
#define PROJECT_ROOMMANAGER_H
#include <repositories/RoomRepository.h>
#include <Room.h>
#include "typedefs.h"

class RoomManager {
    RoomRepositoryPtr roomRepository;
public:
    RoomManager(const RoomRepositoryPtr &roomRepository);
    virtual ~RoomManager();
    void addRoom(int &roomNumber);
    RoomPtr getRoom(int &roomNumber);
    std::string getAllRooms();

};


#endif //PROJECT_ROOMMANAGER_H
