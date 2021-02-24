#ifndef __DECORATOR__TESTS__HPP
#define __DECORATOR__TESTS__HPP

#include "gtest/gtest.h"
#include "Employee.h"
#include "Date.h"
#include "Decorator.hpp"

TEST(DecoratorTest, SingleDecoratorTest) {
    Employee a("Bob", "Builder", "001");
    
    GoodEmployee goodA = GoodEmployee(a);

    string message = goodA.displayGoodEmployeeMsg();

    EXPECT_EQ(message, "Bob Builder is an outstanding employee!\n");
}

TEST(DecoratorTest, OneGoodOneBadEmployeeTest) {
    Employee a("Joel", "Kenning", "001");
    Employee b("Sam", "Dover", "002");
    
    b.addPoint("June", "17", "2012", 2, "Jake");
    GoodEmployee goodA = GoodEmployee(a);
    
    string message = goodA.displayGoodEmployeeMsg();

    EXPECT_EQ(message, "Joel Kenning is an outstanding employee!\n");
    EXPECT_NE(message, "Sam Dover is an outstanding employee!\n");
}

#endif
