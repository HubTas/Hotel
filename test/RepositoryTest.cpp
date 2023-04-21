//
// Created by student on 10.06.2021.
//
#include <boost/test/unit_test.hpp>
#include <repositories/Repository.h>
#include <Client.h>
#include <IdCard.h>
#include <algorithm>

struct TestSuiteRepositoryFixture {
    const std::string testFirstName = "Jan";
    const std::string testLastName = "Nowak";
    const std::string testPhoneNumber = "012345678";
    IdCardPtr testIdCard;

    TestSuiteRepositoryFixture() {
        testIdCard = std::make_shared<IdCard>("testPersonalId","testNationality");
    }
};


BOOST_FIXTURE_TEST_SUITE(TestSuiteRepository, TestSuiteRepositoryFixture)

    BOOST_AUTO_TEST_CASE(GetTest) {
        Repository<ClientPtr> cRepo;
        int size = 5;
        ClientPtr clients[size];

        for (int i = 0; i < size; i++) {
            clients[i] = std::make_shared<Client>(testFirstName, testLastName, testPhoneNumber, testIdCard);
            cRepo.add(clients[i]);
        }

        for (int i = 0; i < size; i++) {
            BOOST_TEST(cRepo.get(i) == clients[i]);
        }
    }
    BOOST_AUTO_TEST_CASE(AddTest) {
        Repository<ClientPtr> cRepo;
        int size = 5;
        ClientPtr clients[size];

        for (int i = 0; i < size; i++) {
            cRepo.add(std::make_shared<Client>(testFirstName, testLastName,  testPhoneNumber, testIdCard));
        }

        BOOST_TEST(cRepo.size() == size);
    }


    BOOST_AUTO_TEST_CASE(SizeTest) {
        Repository<ClientPtr> cRepo;
        int size = 5;
        for (int i = 0; i < size; i++) {
            cRepo.add(std::make_shared<Client>(testFirstName, testLastName,  testPhoneNumber, testIdCard));
        }

        BOOST_TEST(cRepo.size() == size);
    }

    BOOST_AUTO_TEST_CASE(RemoveTest) {
        Repository<ClientPtr> cRepo;
        int size = 5;
        ClientPtr clients[size];
        for (int i = 0; i < size; i++) {
            clients[i] = std::make_shared<Client>(testFirstName, testLastName,  testPhoneNumber, testIdCard);
            cRepo.add(clients[i]);
        }
        cRepo.remove(clients[1]);
        cRepo.remove(clients[4]);

        BOOST_TEST(cRepo.size() == size - 2);
    }


BOOST_AUTO_TEST_SUITE_END()