//
// Created by student on 05.06.2021.
//

#include "repositories/RentRepository.h"
#include <typedefs.h>


RentPtr RentRepository::findByRentId(int rentId) {
    RentPtr found;
    for ( unsigned int i = 0; i < elements.size(); i++) {

        if(rents->get(i)->getRentID()==rentId)
            found = rents->get(i);
    }
    return found;
}
