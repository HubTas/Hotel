//
// Created by student on 05.06.2021.
//

#include "repositories/RoomRepository.h"
#include <typedefs.h>

RoomPtr RoomRepository::findByRoomNumber(int roomNumber) {
    RoomPtr found;
    for ( unsigned int i = 0; i < elements.size(); i++) {

        if(rooms->get(i)->getRoomNumber()==roomNumber)
            found = rooms->get(i);
    }
    return found;
}
