#include "factorial.h"

#include "gtest/gtest.h"

#include <math.h>
namespace {

TEST(FactorialSpec, Negative) {

  EXPECT_EQ(1, Factorial(-5));
}

TEST(FactorialSpec, Zero) {
  EXPECT_EQ(1, Factorial(0));
}

TEST(FactorialSpec, positive) {
  EXPECT_EQ(6, Factorial(3));
  EXPECT_EQ(120, Factorial(5));
  EXPECT_EQ(4294967296, pow(2, 32));
  EXPECT_EQ(3628800, Factorial(10));
}

TEST(FactorialSpec, sizeoftype) {
  int* pointer_int = NULL;
  EXPECT_EQ(1, sizeof(char));
  EXPECT_EQ(2, sizeof(short));
  EXPECT_EQ(4, sizeof(int));
  EXPECT_EQ(4, sizeof(float));
  EXPECT_EQ(8, sizeof(long));
  EXPECT_EQ(8, sizeof(double));

  EXPECT_EQ(8, sizeof(pointer_int));
}


}  // namespace



GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from factorial.cc\n");
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
