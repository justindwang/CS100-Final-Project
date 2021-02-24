#ifndef __FACTORY__TESTS__HPP
#define __FACTORY__TESTS__HPP

#include "gtest/gtest.h"
#include "Employee.h"
#include "Date.h"

TEST(FactoryTest, TardyFactoryTest) {
    Employee a("Bob", "Builder", "001");
    a.addPoint("January", "1", "2000", 1, "Janet");


    Point p1;
    p1 = a.points.at(0);
    EXPECT_EQ(p1.amount, 1);
    EXPECT_EQ(p1.reason, "T (Tardy up to 15 minutes)");
}

TEST(FactoryTest, LateFactoryTest) {
    Employee a("Dan", "Dog", "002");
    a.addPoint("February", "2", "2005", 2, "Ferb");


    Point p1;
    p1 = a.points.at(0);
    EXPECT_EQ(p1.amount, 2);
    EXPECT_EQ(p1.reason, "L (Late 15+ minutes)");
}

TEST(FactoryTest, AbsentFactoryTest) {
    Employee a("Sam", "Seanman", "003");
    a.addPoint("March", "3", "2010", 3, "Mack");


    Point p1;
    p1 = a.points.at(0);
    EXPECT_EQ(p1.amount, 3);
    EXPECT_EQ(p1.reason, "A (Absent/No Show)");
}

TEST(FactoryTest, AllDiffPointsTest) {
    Employee a("Ashley", "Johnson", "004");
    a.addPoint("January", "5", "2010", 1, "Walls");
    a.addPoint("February", "6", "2010", 2, "Walls");
    a.addPoint("March", "7", "2010", 3, "Walls");


    Point p1;
    Point p2;
    Point p3;
    p1 = a.points.at(0);
    p2 = a.points.at(1);
    p3 = a.points.at(2);

    EXPECT_EQ(p1.amount, 1);
    EXPECT_EQ(p1.reason, "T (Tardy up to 15 minutes)");
    EXPECT_EQ(p2.amount, 2);
    EXPECT_EQ(p2.reason, "L (Late 15+ minutes)");
    EXPECT_EQ(p3.amount, 3);
    EXPECT_EQ(p3.reason, "A (Absent/No Show)");
}

#endif
