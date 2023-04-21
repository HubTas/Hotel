//
// Created by student on 01.06.2021.
//

#include "Room.h"
#include "TypeOfRoom.h"
#include "exceptions.h"

Room::Room(int roomNumber) : roomNumber(roomNumber) {
    if(roomNumber==0)
        throw exceptions("Error");
}

Room::~Room() {}

const TypeOfRoomPtr &Room::getTypeOfRoom() const {
    return typeOfRoom;
}

void Room::setAvailability(bool status) {
    if(status == true)
        Room::isAvailable = true;
    else
        Room::isAvailable = false;
}

bool Room::checkAvailability() {
    if(isAvailable == true)
        return true;
    else
        return false;
}

const float Room::getActualPrice() {
    return getTypeOfRoom()->getBasePrice();
}

int Room::getRoomNumber() {
    return roomNumber;
}

std::string Room::getRoomInfo() const {
    std::string available;
    if(isAvailable == true)
        available = "yes";
    else
        available = "no";

    return "Room number: " + std::to_string(roomNumber) + ", price: " + std::to_string(getTypeOfRoom()->getBasePrice()) + ", capacity: " + std::to_string(getTypeOfRoom()->getCapacity()) + ", available: " + available;
}

std::string Room::getInfo() const{
    return Room::getRoomInfo();
}

void Room::setTypeOfRoom(TypeOfRoomPtr newTypeOfRoom) {
    if(newTypeOfRoom != nullptr)
        typeOfRoom = newTypeOfRoom;
}




