#ifndef __VISITOR__TESTS__HPP
#define __VISITOR__TESTS__HPP

#include "gtest/gtest.h"
#include "Employee.h"
#include "Date.h"
#include "Visitor.h"

TEST(VisitorTest, SingleVisitorTest) {
    Employee a("Bob", "Builder", "001");

    PrintVisitor visitor;
    testing::internal::CaptureStdout();

    a.accept(&visitor);

    std::string output = testing::internal::GetCapturedStdout();
   
    EXPECT_EQ(output, "Bob Builder 001 - 0 points total in last 75 days.\n");
}

TEST(VisitorTest, TwoVisiteesTest) {
    Employee a("Bob", "Builder", "001");
    Employee b("Sunny", "Wang", "002");
 

    PrintVisitor visitor;
    testing::internal::CaptureStdout();

    a.accept(&visitor);

    std::string output = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();

    b.accept(&visitor);

    std::string output2 = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Bob Builder 001 - 0 points total in last 75 days.\n");
    EXPECT_EQ(output2, "Sunny Wang 002 - 0 points total in last 75 days.\n");
}

TEST(VisitorTest, TwoVisiteesWithPointsTest) {
    Employee a("Bob", "Builder", "001");
    Employee b("Sunny", "Wang", "002");

    a.addPoint("June", "30", "2020", 3, "Ross");
    b.addPoint("July", "1", "2020", 1, "Mark");

    PrintVisitor visitor;
    testing::internal::CaptureStdout();

    a.accept(&visitor);

    std::string output = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();

    b.accept(&visitor);

    std::string output2 = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Bob Builder 001 - 3 points total in last 75 days.\n");
    EXPECT_EQ(output2, "Sunny Wang 002 - 1 points total in last 75 days.\n");
}

TEST(VisitorTest, ManyVisiteesWithPointsTest) {
    Employee a("Bob", "Builder", "001");
    Employee b("Sunny", "Wang", "002");
    Employee c("Falling", "Sky", "010");
    Employee d("Aging", "Liang", "050");
    Employee e("Rohab", "Patri", "060");

    a.addPoint("June", "30", "2020", 3, "Ross");
    b.addPoint("July", "1", "2020", 1, "Mark");
    c.addPoint("June", "30", "2020", 2, "Grock");
    d.addPoint("July", "15", "2020", 1, "Moses");
    a.addPoint("June", "30", "2020", 2, "Tammy");
    b.addPoint("July", "7", "2020", 1, "Robert");

    PrintVisitor visitor;

    testing::internal::CaptureStdout();
    a.accept(&visitor);
    std::string output = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    b.accept(&visitor);
    std::string output2 = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    c.accept(&visitor);
    std::string output3 = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    d.accept(&visitor);
    std::string output4 = testing::internal::GetCapturedStdout();
    
    testing::internal::CaptureStdout();
    e.accept(&visitor);
    std::string output5 = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Bob Builder 001 - 5 points total in last 75 days.\n");
    EXPECT_EQ(output2, "Sunny Wang 002 - 2 points total in last 75 days.\n");
    EXPECT_EQ(output3, "Falling Sky 010 - 2 points total in last 75 days.\n");
    EXPECT_EQ(output4, "Aging Liang 050 - 1 points total in last 75 days.\n");
    EXPECT_EQ(output5, "Rohab Patri 060 - 0 points total in last 75 days.\n");
}
#endif
