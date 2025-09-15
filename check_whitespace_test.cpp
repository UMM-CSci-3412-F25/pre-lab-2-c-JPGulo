#include <gtest/gtest.h>
#include <cstdlib> 
#include "check_whitespace.h"

TEST(strip, EmptyString) {
    char *s = strip("");
    ASSERT_STREQ("", s);
    free(s);
}

TEST(strip, NoWhitespace) {
    char *s = strip("frog");
    ASSERT_STREQ("frog", s);
    free(s);
}

TEST(strip, WhitespaceOnFront) {
    char *s = strip("   frog");
    ASSERT_STREQ("frog", s);
    free(s);
}

TEST(strip, WhitespaceOnBack) {
    char *s = strip("frog  ");
    ASSERT_STREQ("frog", s);
    free(s);
}

TEST(strip, WhitespaceOnBothEnds) {
    char *s = strip("  frog     ");
    ASSERT_STREQ("frog", s);
    free(s);
}

TEST(is_clean, EmptyString) {
    ASSERT_TRUE(is_clean(""));
}

TEST(is_clean, NoWhitespace) {
    ASSERT_TRUE(is_clean("University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnFront) {
    ASSERT_FALSE(is_clean("   University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnBack) {
    ASSERT_FALSE(is_clean("University of Minnesota Morris  "));
}

TEST(is_clean, WhitespaceOnBothEnds) {
    ASSERT_FALSE(is_clean(" University of Minnesota Morris"    ));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}