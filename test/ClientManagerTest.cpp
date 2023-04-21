//
// Created by student on 11.06.2021.
//

#include <boost/test/unit_test.hpp>
#include <repositories/Repository.h>
#include <managers/ClientManager.h>


struct TestSuiteClientManagerFixture {
    std::string testFirstName = "testFirstName";
    std::string testLastName = "testLastName";
    std::string testPhoneNumber = "testPhoneNumber";
    std::string testAnotherPhoneNumber = "testPhoneNumber";
    std::string testPersonalId = "testPersonalId";
    std::string testNationality = "testNationality";
    ClientRepositoryPtr testClientRepository;
    IdCardPtr testIdCardPtr;


    TestSuiteClientManagerFixture() {
        testIdCardPtr = std::make_shared<IdCard>(testPersonalId, testNationality);
        testClientRepository = std::make_shared<Repository<ClientPtr>>();
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager, TestSuiteClientManagerFixture)

    BOOST_AUTO_TEST_CASE(ContructorException) {
        BOOST_REQUIRE_THROW(new ClientManager(nullptr), std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(RegisterClientTest) {
        ClientManager cManager(testClientRepository);
         cManager.registerClient(testFirstName, testLastName, testPhoneNumber,testIdCardPtr);

        BOOST_TEST(testClientRepository->get(0) == cManager.getClient(testPhoneNumber));
    }

    BOOST_AUTO_TEST_CASE(RegisterClientTestTheSamePhoneNumber) {
        ClientManager cManager(testClientRepository);

        cManager.registerClient(testFirstName, testLastName, testPhoneNumber,testIdCardPtr);
        BOOST_REQUIRE_THROW(cManager.registerClient(testFirstName, testLastName,testAnotherPhoneNumber,testIdCardPtr), std::logic_error);

        BOOST_TEST(testClientRepository->size()==1);
    }

BOOST_AUTO_TEST_SUITE_END();

