#include <gtest/gtest.h>

#include "stargrade/gtest/gradescope_test_listener.h"

#include "submission/submission.h"

TEST(Foo, PrimeTest) {
  EXPECT_TRUE(prime(5));
  EXPECT_TRUE(prime(11));
  EXPECT_FALSE(prime(12));
  EXPECT_FALSE(prime(15));
}

TEST(Foo, ReverseTest) {
  EXPECT_EQ("abc", reverse("cba"));
  EXPECT_EQ("a", reverse("a"));
  EXPECT_EQ("123 abc", reverse("cba 321"));
}

int main(int argc, char **argv) {
  bool gradescope = false;
  if (argc >= 2) {
    gradescope = strcmp(argv[1], "--gradescope") == 0;
  }
  testing::InitGoogleTest(&argc, argv);
  if (gradescope) {
    testing::TestEventListeners &listeners =
        testing::UnitTest::GetInstance()->listeners();
    delete listeners.Release(listeners.default_result_printer());
    listeners.Append(new stargrade::GradescopeTestListener(std::cout));
    RUN_ALL_TESTS();
    return 0;
  } else {
    return RUN_ALL_TESTS();
  }
}
