#include "gtest/gtest.h"
#include "Vector.hpp"

class VectorTests : public ::testing::Test {
protected:
    Vector<int> vector{};
    int dato{};
};

TEST_F(VectorTests, Add) {
    vector.add(1);
    EXPECT_EQ(vector[0], 1);

    vector.add(2);
    EXPECT_EQ(vector[1], 2);
}

TEST_F(VectorTests, IndexAdd) {
    vector.add(1, 0);
    EXPECT_EQ(vector[0], 1);

    vector.add(2, 0);
    EXPECT_EQ(vector[0], 2);
}

TEST_F(VectorTests, IndexAddHandlesIndexOutOfBounds) {
    EXPECT_THROW(vector.add(1, 1), IndexException);
}


TEST_F(VectorTests, Remove) {
    vector.add(1);

    dato = vector.remove();
    EXPECT_EQ(dato, 1);
}

TEST_F(VectorTests, RemoveHandlesEmptyVector) {
    EXPECT_THROW(vector.remove(), EmptyException);
}

TEST_F(VectorTests, IndexRemove) {
    vector.add(1);
    vector.add(2);

    dato = vector.remove(0);
    EXPECT_EQ(dato, 1);

    dato = vector.remove(0);
    EXPECT_EQ(dato, 2);
}

TEST_F(VectorTests, IndexRemoveHandlesEmptyVector) {
    EXPECT_THROW(vector.remove(0), EmptyException);
}

TEST_F(VectorTests, IndexRemoveHandlesIndexOutOfBounds) {
    vector.add(1);

    EXPECT_THROW(vector.remove(1), IndexException);
}

TEST_F(VectorTests, Empty) {
    EXPECT_TRUE(vector.empty());

    vector.add(1);
    EXPECT_FALSE(vector.empty());

    vector.remove();
    EXPECT_TRUE(vector.empty());
}

TEST_F(VectorTests, Size) {
    EXPECT_EQ(vector.size(), 0);

    vector.add(1);
    vector.add(2);
    vector.add(3);
    EXPECT_EQ(vector.size(), 3);

    vector.remove();
    EXPECT_EQ(vector.size(), 2);
}

TEST_F(VectorTests, AccessOperator) {
    vector.add(1);
    vector.add(2, 0);
    vector.add(3);
    dato = vector.remove(0);

    EXPECT_EQ(vector[1], 3);
    EXPECT_EQ(dato, 2);
}

TEST_F(VectorTests, AccessOperatorHandlesEmptyVector) {
    EXPECT_THROW(vector[0], EmptyException);
}

TEST_F(VectorTests, AccessOperatorHandlesIndexOutOfBounds) {
    vector.add(1);

    EXPECT_THROW(vector[1], IndexException);
}
