//
// Created by student on 11.06.2021.
//

#ifndef PROJECT_EXCEPTIONS_H
#define PROJECT_EXCEPTIONS_H

#include <stdexcept>

class exceptions : public std::logic_error {
public:
    explicit exceptions(const std::string error):std::logic_error(error){}
};

#endif //PROJECT_EXCEPTIONS_H
