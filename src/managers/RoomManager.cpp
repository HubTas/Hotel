//
// Created by student on 07.06.2021.
//

#include "managers/RoomManager.h"
#include <Exceptions.h>

RoomManager::RoomManager(const RoomRepositoryPtr &roomRepository): roomRepository(roomRepository) {
    if (roomRepository == nullptr) { throw Exception("Missing of Repository<Room>"); }
}

RoomManager::~RoomManager() {

}

void RoomManager::addRoom(int &roomNumber) {
    RoomPredicate predicate = [roomNumber](const RoomPtr ptr) {
        return ptr->getRoomNumber() == roomNumber;
    };
    if(roomRepository->find(predicate))         //nie mozna dodac pokoju ktory juz istnieje
    {
        throw Exception("Cannot add existing room!");
    }
    else {
        RoomPtr newRoom = std::make_shared<Room>(roomNumber);
        roomRepository->add(newRoom);
        newRoom->setAvailability(false);
    }
}

RoomPtr RoomManager::getRoom(int &roomNumber) {
    RoomPredicate predicate = [roomNumber](const RoomPtr ptr) {
        return ptr->getRoomNumber() == roomNumber;
    };
    return roomRepository->find(predicate);
}

std::string RoomManager::getAllRooms() {
    return roomRepository->report();
}
