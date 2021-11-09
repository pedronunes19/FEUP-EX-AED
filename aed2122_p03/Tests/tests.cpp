#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funSearchProblem.h"

using testing::Eq;

TEST(test, facingsun){
    FunSearchProblem p1;
    ASSERT_EQ(0, p1.facingSun({}));  // test empty vector
    ASSERT_EQ(4, p1.facingSun({1, 5, 4, 7, 2, 2, 2, 5, 8}));
    ASSERT_EQ(2,p1.facingSun({4, 4, 4, 9}));
}

TEST(test, squareR){
    FunSearchProblem p2;
    ASSERT_EQ(5, p2.squareR(25));
    ASSERT_EQ(6, p2.squareR(38));
    ASSERT_EQ(2, p2.squareR(4));
    ASSERT_EQ(1, p2.squareR(2));
    ASSERT_EQ(70, p2.squareR(5000));
}

TEST(test, missingvalue){
    FunSearchProblem p2;
    ASSERT_EQ(0, p2.smallestMissingValue({0, 0, 0, 0, -20}));
    ASSERT_EQ(2, p2.smallestMissingValue({1, 0, 0, 0, -20}));
    ASSERT_EQ(1, p2.smallestMissingValue({15, 0, 2, 3, -20}));
    ASSERT_EQ(0, p2.smallestMissingValue({}));

}

TEST(test, minPages){
    FunSearchProblem p2;
    ASSERT_EQ(200, p2.minPages({100, 100, 100, 100}, 2));
    ASSERT_EQ(550, p2.minPages({100, 500, 100, 150, 100, 200}, 3));
}
