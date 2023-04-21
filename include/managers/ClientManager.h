//
// Created by student on 07.06.2021.
//

#ifndef PROJECT_CLIENTMANAGER_H
#define PROJECT_CLIENTMANAGER_H
#include <repositories/Repository.h>
#include <Client.h>
#include "typedefs.h"

class ClientManager {
    ClientRepositoryPtr clientRepository;
public:
    ClientManager(const ClientRepositoryPtr &clientRepository);
    virtual ~ClientManager();
    void registerClient(std::string &firstName, std::string &lastName, std::string &phoneNumber, IdCardPtr &idCard);
    void unregisterClient(const ClientPtr &client);
    ClientPtr getClient(std::string phoneNumber);
    std::string getAllClients();
};


#endif //PROJECT_CLIENTMANAGER_H
