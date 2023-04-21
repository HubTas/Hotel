//
// Created by student on 02.06.2021.
//

#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H
#include <string>
#include "typedefs.h"
#include "IdCard.h"

class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    bool currentClient = false;
    IdCardPtr idCard;

public:
    Client(std::string firstName, std::string lastName, std::string phoneNumber, IdCardPtr idCard);
    ~Client();
    void setFirstName(std::string newFirstName);
    void setLastName(std::string newLastName);
    void setPhoneNumber(std::string newPhoneNumber);
    void setCurrentClient(bool CurrentClient);
    std::string getFirstName();
    std::string getLastName();
    std::string getPhoneNumber();
    bool isNotCurrentClient();
    std::string getClientInfo()const;
    std::string getInfo()const;
};


#endif //PROJECT_CLIENT_H
