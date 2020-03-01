#include <gtest/gtest.h>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "stargrade/gtest/gradescope_test_listener.h"

#include "submission/submission.h"

ABSL_FLAG(bool, gradescope, false,
          "Defines whether to output the results for Gradescope or not.");

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
  absl::ParseCommandLine(argc, argv);
  testing::InitGoogleTest(&argc, argv);
  if (absl::GetFlag(FLAGS_gradescope)) {
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
