//
// Created by student on 11.06.2021.
//
#include <boost/test/unit_test.hpp>
#include <repositories/Repository.h>
#include <managers/RoomManager.h>

struct TestSuiteRoomManagerFixture {
    int testRoomNumber = 1;
    int testAnotherRoomNumber = 1;
    RoomRepositoryPtr testRoomRepository;

    TestSuiteRoomManagerFixture() {
        testRoomRepository = std::make_shared<Repository<RoomPtr>>();
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRoomManager, TestSuiteRoomManagerFixture)

    BOOST_AUTO_TEST_CASE(ContructorException) {
        BOOST_REQUIRE_THROW(new RoomManager(nullptr), std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(AddGetRoomTest) {
        RoomManager roomManager(testRoomRepository);

        roomManager.addRoom(testRoomNumber);

        BOOST_TEST(testRoomRepository->get(0) == roomManager.getRoom(testRoomNumber));
    }


    BOOST_AUTO_TEST_CASE(AddingTwoSameRoomsTest) {
        RoomManager roomManager(testRoomRepository);

        roomManager.addRoom(testRoomNumber);
        BOOST_REQUIRE_THROW(roomManager.addRoom(testAnotherRoomNumber), std::logic_error);

        BOOST_TEST(testRoomRepository->size()==1);

    }

BOOST_AUTO_TEST_SUITE_END()
