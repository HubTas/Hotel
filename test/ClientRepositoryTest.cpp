//
// Created by student on 10.06.2021.
//

#include <boost/test/unit_test.hpp>
#include "repositories/ClientRepository.h"
#include <Client.h>
#include <IdCard.h>
#include <vector>
#include <algorithm>

struct TestSuiteRepositoryFixture {
    const std::string testFirstName = "Jan";
    const std::string testLastName = "Nowak";
    const std::string testPhoneNumber1 = "testNumber1";
    const std::string testPhoneNumber2 = "testNumber2";
    IdCardPtr testIdCard;

    TestSuiteRepositoryFixture() {
        testIdCard = std::make_shared<IdCard>("testPersonalId","testNationality");
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientRepository, TestSuiteRepositoryFixture)

    BOOST_AUTO_TEST_CASE(FindByPhoneNumberTest) {
        Repository<ClientPtr> cRepo;
        int size = 5;
        ClientPtr clients[size];

            clients[1] = std::make_shared<Client>(testFirstName, testLastName, testPhoneNumber1, testIdCard);
            clients[2] = std::make_shared<Client>(testFirstName, testLastName, testPhoneNumber2, testIdCard);
            cRepo.add(clients[1]);
            cRepo.add(clients[2]);

           // BOOST_TEST()

    }
    BOOST_AUTO_TEST_SUITE_END()