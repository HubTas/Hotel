    //
// Created by student on 05.06.2021.
//

#ifndef PROJECT_CLIENTREPOSITORY_H
#define PROJECT_CLIENTREPOSITORY_H
#include "Repository.h"
#include <typedefs.h>
#include <Client.h>


class ClientRepository: public Repository<Client> {
ClientRepositoryPtr clientsPtr;
public:
    ClientPtr findByPhoneNumber(std::string phoneNumber);

};


#endif //PROJECT_CLIENTREPOSITORY_H
