//
// Created by student on 05.06.2021.
//

#include "repositories/ClientRepository.h"
#include <typedefs.h>


ClientPtr ClientRepository::findByPhoneNumber(std::string phoneNumber) {
    ClientPtr found;
    for ( unsigned int i = 0; i < elements.size(); i++) {

        if(clientsPtr->get(i)->getPhoneNumber()==phoneNumber)
            found = clientsPtr->get(i);
    }
    return found;
}
