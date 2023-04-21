//
// Created by student on 05.06.2021.
//

#ifndef PROJECT_REPOSITORY_H
#define PROJECT_REPOSITORY_H
#include <memory>
#include <vector>
#include <string>
#include <typedefs.h>
#include <Client.h>
#include <Rent.h>
#include <Room.h>
#include <Exceptions.h>


template <class T> class Repository
{
protected:
    std::vector<T> elements;
public:
    T get( unsigned int id);
    void add(T newElement);
    void remove(T element);
    std::string report();
    int size();
    T find(std::function<bool(T)> &predicate);

};


//implementacja metod

template<class T>
T Repository<T>::get(unsigned int id) {
    if(id<size())
       return elements[id];
}

template<class T>
void Repository<T>::add(T newElement) {
        if(newElement == nullptr) {throw Exception("Element you try to add doesn't exist");}
        elements.push_back(newElement);
}

template<class T>
void Repository<T>::remove(T element) {
    for (int i = 0; i < size(); ++i) {
        if (element == get(i)) {
            elements.erase(elements.begin() + i);
        }
    }
}

template<class T>
std::string Repository<T>::report() {
    std::string element;
    for(int i =0; i<elements.size(); i++)
    {

    }
    return element;
}

template<class T>
int Repository<T>::size()  {
    return elements.size();
}


template<class T>
T Repository<T>::find(std::function<bool(T)> &predicate)  {
    for (int i = 0; i < size(); i++) {
        T element = get(i);
        if (predicate(element)) {
            return element;
        }
    }
    return nullptr;
}

template
class Repository<ClientPtr>;

template
class Repository<RoomPtr>;

template
class Repository<RentPtr>;

#endif //PROJECT_REPOSITORY_H