//
// Created by student on 10.06.2021.
//

#include <boost/test/unit_test.hpp>
#include "Rent.h"
#include "Client.h"
#include "Room.h"
#include <boost/date_time.hpp>
#include "SingleRoom.h"

namespace btt = boost::test_tools;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

struct TestSuiteRentFixture {
    const int testRentID = 1769;
    pt::ptime testBeginTime =  pt::ptime(gr::date(2021,6,11),pt::hours(9)+pt::minutes(0));
    pt::ptime testEndTime =  pt::ptime(gr::date(2021,6,25),pt::hours(9)+pt::minutes(0));
    float testRentTotalCost = 170;
    ClientPtr testClient;
    RoomPtr testRoom;
    IdCardPtr testIdCard;
    TypeOfRoomPtr testTypeOfRoom = std::make_shared<SingleRoom>();

    TestSuiteRentFixture() {
        testIdCard = std::make_shared<IdCard>("22446688", "Poland");
        testClient = std::make_shared<Client>("Adam", "Nowak", "246813579", testIdCard);
        testRoom = std::make_shared<Room>(3);
    }
};


BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        Rent testRent(testRentID, testBeginTime, testEndTime, testClient, testRoom);
        BOOST_TEST_REQUIRE(testRent.getRentID() == testRentID);
        BOOST_TEST_REQUIRE(testRent.getBeginTime() == testBeginTime);
        BOOST_TEST_REQUIRE(testRent.getEndTime() == testEndTime);
        BOOST_TEST_REQUIRE(testRent.getClient() == testClient);
        BOOST_TEST_REQUIRE(testRent.getRoom() == testRoom);
    }

    BOOST_AUTO_TEST_CASE(ConstructorTestExceptions) {
        BOOST_REQUIRE_THROW(Rent testRent(0, testBeginTime, testEndTime, testClient, testRoom), std::logic_error);
        BOOST_REQUIRE_THROW(Rent testRent(testRentID, testBeginTime, testEndTime, nullptr, testRoom), std::logic_error);
        BOOST_REQUIRE_THROW(Rent testRent(testRentID, testBeginTime, testEndTime, testClient, nullptr), std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(GetRentInfoTest) {
        Rent testRent(testRentID, testBeginTime, testEndTime, testClient, testRoom);

        std::stringstream ssBeginTime, ssEndTime;
        ssBeginTime << testBeginTime;
        ssEndTime << testEndTime;
        std::string rentBeginTime = ssBeginTime.str();
        std::string rentEndTime=ssEndTime.str();

        testRoom->setTypeOfRoom(testTypeOfRoom);

        BOOST_TEST(testRent.getRentInfo() == "Rent ID: " + std::to_string(testRentID) + ", begin time: " + rentBeginTime + ", end time: " + rentEndTime + ", rent total cost: " + std::to_string(testRentTotalCost));
    }

BOOST_AUTO_TEST_SUITE_END()

