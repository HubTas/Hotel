//
// Created by student on 02.06.2021.
//

#include <boost/test/unit_test.hpp>
#include <IdCard.h>

struct TestSuiteIdCardFixture {
    const std::string testPersonalId = "22446688";
    const std::string testNationality = "Poland";

    const std::string testPersonalId2 = "21436587";
    const std::string testNationality2 = "England";
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteIdCard, TestSuiteIdCardFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        IdCard testIdCard(testPersonalId, testNationality);
        BOOST_TEST_REQUIRE(testIdCard.getPersonalId() == testPersonalId);
        BOOST_TEST_REQUIRE(testIdCard.getNationality() == testNationality);
    }

    BOOST_AUTO_TEST_CASE(ConstructorTestExceptions) {
        BOOST_REQUIRE_THROW(IdCard testIdCard("", testNationality), std::logic_error);
        BOOST_REQUIRE_THROW(IdCard testIdCard(testPersonalId, ""), std::logic_error);
     }

    BOOST_AUTO_TEST_CASE(SetPersonalIdTest) {
        IdCard testIdCard(testPersonalId, testNationality);
        testIdCard.setPersonalId(testPersonalId2);
        BOOST_TEST(testIdCard.getPersonalId() == testPersonalId2);

        IdCard testIdCard_emptyString(testPersonalId, testNationality);
        testIdCard_emptyString.setPersonalId("");
        BOOST_TEST(testIdCard_emptyString.getPersonalId() == testPersonalId);
    }

    BOOST_AUTO_TEST_CASE(SetNationalityTest) {
        IdCard testIdCard(testPersonalId, testNationality);
        testIdCard.setNationality(testNationality2);
        BOOST_TEST(testIdCard.getNationality() == testNationality2);

        IdCard testIdCard_emptyString(testPersonalId, testNationality);
        testIdCard_emptyString.setNationality("");
        BOOST_TEST(testIdCard_emptyString.getNationality() == testNationality);
    }

BOOST_AUTO_TEST_SUITE_END()