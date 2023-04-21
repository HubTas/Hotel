//
// Created by student on 09.06.2021.
//

#ifndef PROJECT_RENT_H
#define PROJECT_RENT_H
#include <string>
#include <boost/date_time.hpp>
#include "typedefs.h"

class Client;
class Room;

class Rent {
private:
    int rentID;
    boost::posix_time::ptime beginTime;
    boost::posix_time::ptime endTime;
    float rentTotalCost;
    ClientPtr client;
    RoomPtr room;

public:
    Rent(int rentID, boost::posix_time::ptime beginTime, boost::posix_time::ptime endTime, ClientPtr client, RoomPtr room);
    ~Rent();
    int getRentID();
    boost::posix_time::ptime getBeginTime();
    boost::posix_time::ptime getEndTime();
    float getRentTotalCost();
    const ClientPtr &getClient() const;
    const RoomPtr &getRoom() const;
    std::string getRentInfo()const;
    std::string getInfo() const;
};


#endif //PROJECT_RENT_H
