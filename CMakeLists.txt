CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    unit_test.cpp
    Employee.cpp
    Date.cpp
    Visitor.cpp
)

ADD_EXECUTABLE(application
    main.cpp
    Employee.cpp
    Date.cpp
    Visitor.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
