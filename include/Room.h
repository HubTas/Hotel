//
// Created by student on 01.06.2021.
//

#ifndef PROJECT_ROOM_H
#define PROJECT_ROOM_H
#include <string>
#include "typedefs.h"

class TypeOfRoom;

class Room {
private:
    int roomNumber;
    bool isAvailable = true;
    TypeOfRoomPtr typeOfRoom;

public:
    Room(int roomNumber);
    ~Room();
    int getRoomNumber();
    bool checkAvailability();
    void setAvailability(bool status);
    const float getActualPrice();
    std::string getRoomInfo() const;
    std::string getInfo() const;
    const TypeOfRoomPtr &getTypeOfRoom() const;
    void setTypeOfRoom(TypeOfRoomPtr newTypeOfRoom);
};



#endif //PROJECT_ROOM_H
