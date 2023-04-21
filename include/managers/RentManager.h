//
// Created by student on 07.06.2021.
//

#ifndef PROJECT_RENTMANAGER_H
#define PROJECT_RENTMANAGER_H
#include <iostream>
#include <repositories/RentRepository.h>
#include <Rent.h>
#include <Client.h>
#include <Room.h>
#include <boost/date_time.hpp>
#include "typedefs.h"

class RentManager {
    RentRepositoryPtr rentRepository;
public:
    RentManager(const RentRepositoryPtr &rentRepository);
    virtual ~RentManager();
    void rentRoom(int rentId, boost::posix_time::ptime beginTime, boost::posix_time::ptime endTime, ClientPtr client, RoomPtr room);
    void endRent(Rent rent);
    RentPtr getRent(int rentId);
    std::string getAllRents();
};


#endif //PROJECT_RENTMANAGER_H
