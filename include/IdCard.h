//
// Created by student on 02.06.2021.
//

#ifndef PROJECT_IDCARD_H
#define PROJECT_IDCARD_H
#include <string>

class IdCard {
private:
    mutable std::string personalId;
    mutable std::string nationality;
public:
    IdCard( std::string personalId, std::string nationality);
    ~IdCard();
    void setPersonalId(const std::string PersonalId);
    void setNationality(const std::string Nationality);
    const std::string getPersonalId() const;
    const std::string getNationality() const;
};


#endif //PROJECT_IDCARD_H
