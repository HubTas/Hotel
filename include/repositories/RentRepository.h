//
// Created by student on 05.06.2021.
//

#ifndef PROJECT_RENTREPOSITORY_H
#define PROJECT_RENTREPOSITORY_H
#include "Repository.h"
#include <typedefs.h>
#include <Rent.h>


class RentRepository: public Repository<Rent> {
RentRepositoryPtr rents;
public:
    RentPtr findByRentId(int rentId);
};


#endif //PROJECT_RENTREPOSITORY_H
