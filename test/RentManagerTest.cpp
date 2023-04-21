//
// Created by student on 11.06.2021.
//

#include <boost/test/unit_test.hpp>
#include <repositories/Repository.h>
#include <managers/RentManager.h>

namespace btt = boost::test_tools;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
struct TestSuiteRentManagerFixture {
    std::string testFirstName = "testFirstName";
    std::string testLastName = "testLastName";
    std::string testPhoneNumber = "testPhoneNumber";
    std::string testAnotherPhoneNumber = "testAnotherPhoneNumber";
    std::string testPersonalId = "testPersonalId";
    std::string testNationality = "testNationality";
    int testRoomNumber=1;
    int testRentId=1;

pt::ptime testBeginTime = pt::ptime(gr::date(2021,6,13),pt::hours(9)+pt::minutes(0));
pt::ptime testEndTime = pt::ptime(gr::date(2021,6,20),pt::hours(9)+pt::minutes(0));

    RentRepositoryPtr testRentRepository;
    IdCardPtr testIdCardPtr;
    ClientPtr testClientPtr;
    ClientPtr testAnotherClientPtr;
    RoomPtr testRoomPtr;

    TestSuiteRentManagerFixture() {
        testIdCardPtr = std::make_shared<IdCard>(testPersonalId, testNationality);
        testClientPtr = std::make_shared<Client>(testFirstName,testLastName,testPhoneNumber,testIdCardPtr);
        testAnotherClientPtr = std::make_shared<Client>(testFirstName,testLastName,testAnotherPhoneNumber,testIdCardPtr);
        testRoomPtr = std::make_shared<Room>(testRoomNumber);
        testRentRepository = std::make_shared<Repository<RentPtr>>();
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentManager, TestSuiteRentManagerFixture)

    BOOST_AUTO_TEST_CASE(ContructorException) {
        BOOST_REQUIRE_THROW(new RentManager(nullptr), std::logic_error);
    }
    BOOST_AUTO_TEST_CASE(RentRoomTest) {
        RentManager rentManager(testRentRepository);
        rentManager.rentRoom(testRentId, testBeginTime, testEndTime, testClientPtr, testRoomPtr);

        BOOST_TEST(testRentRepository->get(0) == rentManager.getRent(testRentId));
    }
    BOOST_AUTO_TEST_CASE(RentTheSameRoomTest) {
        RentManager rentManager(testRentRepository);

        rentManager.rentRoom(testRentId, testBeginTime, testEndTime, testClientPtr, testRoomPtr);
        BOOST_REQUIRE_THROW(rentManager.rentRoom(testRentId, testBeginTime, testEndTime, testAnotherClientPtr, testRoomPtr),std::logic_error);

        BOOST_TEST(testRentRepository->size()==1);
    }


BOOST_AUTO_TEST_SUITE_END();