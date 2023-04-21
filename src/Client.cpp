//
// Created by student on 02.06.2021.
//

#include "Client.h"
#include "exceptions.h"

Client::Client(std::string firstName, std::string lastName, std::string phoneNumber, IdCardPtr idCard) : firstName(firstName), lastName(lastName), phoneNumber(phoneNumber), idCard(idCard) {
    if(firstName.empty())
        throw exceptions("Error");
    if(lastName.empty())
        throw exceptions("Error");
    if(phoneNumber.empty())
        throw exceptions("Error");
    if(idCard == nullptr)
        throw exceptions("Error");
}

Client::~Client() {}

void Client::setFirstName(std::string newFirstName) {
    if(!newFirstName.empty())
        firstName = newFirstName;
}

void Client::setLastName(std::string newLastName) {
    if(!newLastName.empty())
        lastName = newLastName;
}

void Client::setPhoneNumber(std::string newPhoneNumber) {
    if(!newPhoneNumber.empty())
        phoneNumber = newPhoneNumber;
}

void Client::setCurrentClient(bool currentClient) {
    if(currentClient == true)
        Client::currentClient = true;
    else
        Client::currentClient = false;
}

std::string Client::getFirstName() {
    return firstName;
}

std::string Client::getLastName() {
    return lastName;
}

std::string Client::getPhoneNumber() {
    return phoneNumber;
}

bool Client::isNotCurrentClient() {
    if(Client::currentClient == true)
        return true;
    else
        return false;
}

std::string Client::getClientInfo() const{
    std::string isCurrentClient;
    if(currentClient == true)
        isCurrentClient = "yes";
    else
        isCurrentClient = "no";

    return "First name: " + firstName + ", last name: " + lastName + ", phone number: " + phoneNumber + ", current client: " + isCurrentClient + ", personal id: " + idCard->getPersonalId() + ", nationality: " + idCard->getNationality();
}

std::string Client::getInfo() const{
    return Client::getClientInfo();
}


