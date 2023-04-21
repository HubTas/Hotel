//
// Created by student on 09.06.2021.
//

#include "Rent.h"
#include "exceptions.h"
#include "Room.h"

Rent::Rent(int rentID, boost::posix_time::ptime beginTime, boost::posix_time::ptime endTime, ClientPtr client, RoomPtr room) : rentID(rentID), beginTime(beginTime), endTime(endTime), client(client), room(room) {
    if(beginTime == boost::posix_time::not_a_date_time) {
        Rent::beginTime = boost::posix_time::second_clock::local_time();
    }
    endTime = boost::posix_time::not_a_date_time;
    if(client == nullptr)
        throw exceptions("Error");
    if(room == nullptr)
        throw exceptions("Error");
    if(rentID==0)
        throw exceptions("Error");
}

Rent::~Rent(){}

int Rent::getRentID() {
    return rentID;
}

boost::posix_time::ptime Rent::getBeginTime() {
    return beginTime;
}

boost::posix_time::ptime Rent::getEndTime() {
    return endTime;
}

float Rent::getRentTotalCost() {
    rentTotalCost = room->getActualPrice();
    return rentTotalCost;
}

const RoomPtr &Rent::getRoom() const {
    return room;
}

const ClientPtr &Rent::getClient() const {
    return client;
}

std::string Rent::getRentInfo() const{
    std::stringstream ssBeginTime, ssEndTime;
    ssBeginTime << beginTime;
    ssEndTime << endTime;
    std::string rentBeginTime = ssBeginTime.str();
    std::string rentEndTime=ssEndTime.str();
    return "Rent ID: " + std::to_string(rentID) + ", begin time: " + rentBeginTime + ", end time: " + rentEndTime + ", rent total cost: " + std::to_string(room->getActualPrice());
}

std::string Rent::getInfo() const{
    return Rent::getRentInfo();
}