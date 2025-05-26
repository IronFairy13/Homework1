#include "lib.h"
#include <gtest/gtest.h>

TEST(test_version, test_valid_version) {
    EXPECT_GT(version(), 0);
}