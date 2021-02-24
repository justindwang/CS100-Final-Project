#include "gtest/gtest.h"
#include "Factory_tests.hpp"
#include "Decorator_tests.hpp"
#include "Visitor_tests.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
