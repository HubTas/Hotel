cmake_minimum_required(VERSION 3.10)

#Configuration parameters of cmake
set(CMAKE_CXX_COMPILER g++)#requires g++ to be available on PATH
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Project)
enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

#Source files here
set(SOURCE_FILES
        src/main.cpp
        include/typedefs.h
        src/Room.cpp include/Room.h
        include/Rent.h src/Rent.cpp
        src/TypeOfRoom.cpp include/TypeOfRoom.h
        src/SingleRoom.cpp include/SingleRoom.h
        src/DoubleRoom.cpp include/DoubleRoom.h
        src/TripleRoom.cpp include/TripleRoom.h
        src/Client.cpp include/Client.h
        src/IdCard.cpp include/IdCard.h
        src/repositories/RoomRepository.cpp
        include/repositories/RoomRepository.h
        src/repositories/ClientRepository.cpp
        include/repositories/ClientRepository.h
        src/repositories/RentRepository.cpp
        include/repositories/RentRepository.h
        include/repositories/Repository.h
        src/managers/ClientManager.cpp
        include/managers/ClientManager.h
        src/managers/RoomManager.cpp
        include/managers/RoomManager.h
        src/managers/RentManager.cpp
        include/managers/RentManager.h include/Exceptions.h)

add_executable(Project ${SOURCE_FILES})

target_include_directories(Project PUBLIC include)

#TESTs
find_package(Boost 1.65 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

#Test source files here
set(SOURCE_TEST_FILES
        test/master.cpp
        include/typedefs.h
        src/Room.cpp include/Room.h
        include/Rent.h src/Rent.cpp
        src/TypeOfRoom.cpp include/TypeOfRoom.h
        src/SingleRoom.cpp include/SingleRoom.h
        src/DoubleRoom.cpp include/DoubleRoom.h
        src/TripleRoom.cpp include/TripleRoom.h
        src/Client.cpp include/Client.h
        src/IdCard.cpp include/IdCard.h
        src/repositories/RoomRepository.cpp
        include/repositories/RoomRepository.h
        src/repositories/ClientRepository.cpp
        include/repositories/ClientRepository.h
        src/repositories/RentRepository.cpp
        include/repositories/RentRepository.h
        include/repositories/Repository.h
        src/managers/ClientManager.cpp
        include/managers/ClientManager.h
        src/managers/RoomManager.cpp
        include/managers/RoomManager.h
        src/managers/RentManager.cpp
        include/managers/RentManager.h

test/IdCardTests.cpp test/ClientTest.cpp test/DoubleRoomTest.cpp test/RentTest.cpp test/RoomTest.cpp test/SingleRoomTest.cpp test/TripleRoomTest.cpp test/RentRepositoryTest.cpp test/ClientRepositoryTest.cpp test/ClientRepositoryTest.cpp test/RoomRepositoryTest.cpp test/RepositoryTest.cpp test/RoomManagerTest.cpp test/ClientManagerTest.cpp test/RentManagerTest.cpp)

add_executable(TestProject ${SOURCE_TEST_FILES})

target_include_directories(TestProject PUBLIC include)

target_link_libraries(TestProject
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

enable_testing()

add_test(NAME Test COMMAND TestProject
        --report_level=detailed
        --log_level=all
        --color_output=yes)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})