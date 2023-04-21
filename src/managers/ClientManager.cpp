//
// Created by student on 07.06.2021.
//

#include "managers/ClientManager.h"
#include <Exceptions.h>

ClientManager::ClientManager(const ClientRepositoryPtr &clientRepository) : clientRepository(clientRepository) {
    if (clientRepository == nullptr) { throw Exception("Missing of Repository<Client>");}
}

ClientManager::~ClientManager() {

}


void ClientManager::registerClient( std::string &firstName,  std::string &lastName,  std::string &phoneNumber, IdCardPtr &idCard) {
    ClientPtr clientCheck = getClient(phoneNumber);
    ClientPredicate predicate = [phoneNumber](const ClientPtr ptr) {
        return ptr->getPhoneNumber() == phoneNumber;
    };
    if (clientCheck == nullptr) {
        ClientPtr newClient = std::make_shared<Client>(firstName, lastName, phoneNumber, idCard);
        clientRepository->add(newClient);
    }
    else if (clientRepository->find(predicate))         //nie mozna dodac pokoju ktory juz istnieje
    {
        throw Exception("Cannot add Client with the same phoneNumber!");
    }
    else
        clientCheck->setCurrentClient(true);
}

void ClientManager::unregisterClient(const ClientPtr &client) {
    if (client== nullptr) {throw Exception("You cannot unregister client that doesn't exist");}
    clientRepository->remove(client);
}

ClientPtr ClientManager::getClient(std::string phoneNumber) {
    ClientPredicate predicate = [phoneNumber](const ClientPtr ptr) {
        return ptr->getPhoneNumber() == phoneNumber;
    };
    return clientRepository->find(predicate);
}

std::string ClientManager::getAllClients() {
    return clientRepository->report();;
}

