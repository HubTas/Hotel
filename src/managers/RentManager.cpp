//
// Created by student on 07.06.2021.
//

#include "managers/RentManager.h"
#include <Exceptions.h>

RentManager::RentManager(const RentRepositoryPtr &rentRepository): rentRepository(rentRepository) {
    if (rentRepository == nullptr) { throw Exception("Missing of Repository<Rent>");}
}

RentManager::~RentManager() {

}

void
RentManager::rentRoom(int rentId, boost::posix_time::ptime beginTime, boost::posix_time::ptime endTime, ClientPtr client,RoomPtr room) {
    RentPtr RentCheck = getRent(rentId);
    RentPredicate predicate = [rentId](const RentPtr ptr) {
        return ptr->getRentID() == rentId;
    };
    if (RentCheck == nullptr)
    {
        RentPtr newRent = std::make_shared<Rent>(rentId,beginTime,endTime,client,room);
        if(!room->checkAvailability())                  //nie mozna wyporzyczyc pokoju w ktorym juz ktos jest
        {
            throw Exception("Cannot rent Room that is already rented");
        }
        rentRepository->add(newRent);

    }
    else if (rentRepository->find(predicate))         //nie mozna dodac renta ktory juz istnieje
    {
        throw Exception("Cannot add Rent with the same rent Id!");
    }
}

void RentManager::endRent(Rent rent) {

}

RentPtr RentManager::getRent(int rentId) {  RentPredicate predicate = [rentId](const RentPtr& ptr) {
        return ptr->getRentID() == rentId;
    };
    return rentRepository->find(predicate);
}

std::string RentManager::getAllRents() {
    return rentRepository->report();
}




