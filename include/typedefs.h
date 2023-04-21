#ifndef PROJECT_TYPEDEFS_H
#define PROJECT_TYPEDEFS_H

#include <memory>
#include <functional>

class Client;
class Room;
class Rent;
class IdCard;
class TypeOfRoom;
template<class T>
class Repository;

class ClientManager;
class RoomManager;
class RentManager;

typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Room> RoomPtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<IdCard> IdCardPtr;
typedef std::shared_ptr<TypeOfRoom> TypeOfRoomPtr;

typedef std::shared_ptr<Repository<ClientPtr>> ClientRepositoryPtr;
typedef std::shared_ptr<Repository<RoomPtr>> RoomRepositoryPtr;
typedef std::shared_ptr<Repository<RentPtr>> RentRepositoryPtr;

typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(RoomPtr)> RoomPredicate;
typedef std::function<bool(RentPtr)> RentPredicate;

typedef std::shared_ptr<ClientManager> ClientManagerPtr;
typedef std::shared_ptr<RoomManager> RoomManagerPtr;
typedef std::shared_ptr<RentManager> RentManagerPtr;


#endif //PROJECT_TYPEDEFS_H
