//
// Created by student on 02.06.2021.
//

#include "IdCard.h"
#include "exceptions.h"

IdCard::IdCard( std::string personalId, std::string nationality) : personalId(personalId), nationality(nationality){
    if(personalId.empty())
        throw exceptions("Error");
    if(nationality.empty())
        throw exceptions("Error");
}

IdCard::~IdCard() {}

void IdCard::setPersonalId(const std::string newPersonalId) {
    if(!newPersonalId.empty())
        personalId = newPersonalId;
}

void IdCard::setNationality(const std::string newNationality) {
    if(!newNationality.empty())
        nationality = newNationality;
}

const std::string IdCard::getPersonalId() const{
    return personalId;
}

const std::string IdCard::getNationality() const{
    return nationality;
}


