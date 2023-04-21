//
// Created by student on 10.06.2021.
//

#include <boost/test/unit_test.hpp>
#include "Client.h"
#include "IdCard.h"

struct TestSuiteClientFixture {
    const std::string testFirstName = "Adam";
    const std::string testLastName = "Nowak";
    const std::string testPhoneNumber = "246813579";
    const IdCardPtr testIdCard = std::make_shared<IdCard>("22446688", "Poland");
    bool testIsCurrentClient = false;

    const std::string testFirstName2 = "John";
    const std::string testLastName2 = "Smith";
    const std::string testPhoneNumber2 = "123456789";
    const IdCardPtr testIdCard2 = std::make_shared<IdCard>("21436587", "England");
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        Client testClient(testFirstName, testLastName, testPhoneNumber, testIdCard);
        BOOST_TEST_REQUIRE(testClient.getFirstName() == testFirstName);
        BOOST_TEST_REQUIRE(testClient.getLastName() == testLastName);
        BOOST_TEST_REQUIRE(testClient.getPhoneNumber() == testPhoneNumber);
    }

    BOOST_AUTO_TEST_CASE(ConstructorTestExceptions) {
        BOOST_REQUIRE_THROW(Client testClient("", testLastName, testPhoneNumber, testIdCard), std::logic_error);
        BOOST_REQUIRE_THROW(Client testClient(testFirstName, "", testPhoneNumber, testIdCard), std::logic_error);
        BOOST_REQUIRE_THROW(Client testClient(testFirstName, testLastName, "", testIdCard), std::logic_error);
        BOOST_REQUIRE_THROW(Client testClient(testFirstName, testLastName, testPhoneNumber, nullptr), std::logic_error);
     }

    BOOST_AUTO_TEST_CASE(SetFirstNameTest) {
        Client testClient(testFirstName, testLastName, testPhoneNumber, testIdCard);
        testClient.setFirstName(testFirstName2);
        BOOST_TEST(testClient.getFirstName() == testFirstName2);

        Client testClient_emptyString(testFirstName, testLastName, testPhoneNumber, testIdCard);
        testClient_emptyString.setFirstName("");
        BOOST_TEST(testClient_emptyString.getFirstName() == testFirstName);
    }

    BOOST_AUTO_TEST_CASE(SetLastNameTest) {
        Client testClient(testFirstName, testLastName, testPhoneNumber, testIdCard);
        testClient.setLastName(testLastName2);
        BOOST_TEST(testClient.getLastName() == testLastName2);

        Client testClient_emptyString(testFirstName, testLastName, testPhoneNumber, testIdCard);
        testClient_emptyString.setLastName("");
        BOOST_TEST(testClient_emptyString.getLastName() == testLastName);
    }

    BOOST_AUTO_TEST_CASE(SetPhoneNumberTest) {
        Client testClient(testFirstName, testLastName, testPhoneNumber, testIdCard);
        testClient.setPhoneNumber(testPhoneNumber2);
        BOOST_TEST(testClient.getPhoneNumber() == testPhoneNumber2);

        Client testClient_emptyString(testFirstName, testLastName, testPhoneNumber, testIdCard);
        testClient_emptyString.setPhoneNumber("");
        BOOST_TEST(testClient_emptyString.getPhoneNumber() == testPhoneNumber);
    }

    BOOST_AUTO_TEST_CASE(GetClientInfoTest) {
        Client testClient(testFirstName, testLastName, testPhoneNumber, testIdCard);

        std::string isCurrentClient;
        if(testIsCurrentClient == true)
            isCurrentClient = "yes";
        else
            isCurrentClient = "no";

        BOOST_TEST(testClient.getClientInfo() == "First name: " + testFirstName + ", last name: " + testLastName + ", phone number: " + testPhoneNumber + ", current client: " + isCurrentClient + ", personal id: " + testIdCard->getPersonalId() + ", nationality: " + testIdCard->getNationality());
    }

BOOST_AUTO_TEST_SUITE_END()