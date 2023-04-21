//
// Created by student on 10.06.2021.
//
/*
#include <boost/test/unit_test.hpp>
#include "Room.h"
#include "TypeOfRoom.h"
#include "SingleRoom.h"

struct TestSuiteRoomFixture {
    const int testRoomNumber = 3;
    bool testIsAvailable = true;
    TypeOfRoomPtr testTypeOfRoom = std::make_shared<SingleRoom>();
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRoom, TestSuiteRoomFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        Room testRoom(testRoomNumber);
        BOOST_TEST_REQUIRE(testRoom.getRoomNumber() == testRoomNumber);
    }

    BOOST_AUTO_TEST_CASE(ConstructorTestExceptions) {
        BOOST_REQUIRE_THROW(Room testRoom(0), std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(SetTypeOfRoomTest) {
        Room testRoom(testRoomNumber);
        testRoom.setTypeOfRoom(testTypeOfRoom);
        BOOST_TEST(testRoom.getTypeOfRoom() == testTypeOfRoom);

        Room testRoom_emptyString(testRoomNumber);
        testRoom_emptyString.setTypeOfRoom(nullptr);
        BOOST_TEST(testRoom_emptyString.getTypeOfRoom() == testTypeOfRoom);
    }

    BOOST_AUTO_TEST_CASE(GetRoomInfoTest) {
        Room testRoom(testRoomNumber);

        std::string available;
        if(testIsAvailable == true)
            available = "yes";
        else
            available = "no";

        BOOST_TEST(testRoom.getRoomInfo() == "Room number: " + std::to_string(testRoomNumber) + ", price: " + std::to_string(testRoom.getTypeOfRoom()->getBasePrice()) + ", capacity: " + std::to_string(testRoom.getTypeOfRoom()->getCapacity()) + ", available: " + available);
    }

BOOST_AUTO_TEST_SUITE_END()*/