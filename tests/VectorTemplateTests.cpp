#include "gtest/gtest.h"
#include "Vector.hpp"

class VectorTemplateTests : public ::testing::Test {
protected:
    Vector<int> vector{};
    int dato{};
};

TEST_F(VectorTemplateTests, Add) {
    vector.add(1);
    EXPECT_EQ(vector[0], 1);

    vector.add(2);
    EXPECT_EQ(vector[1], 2);
}

TEST_F(VectorTemplateTests, IndexAdd) {
    vector.add(1, 0);
    EXPECT_EQ(vector[0], 1);

    vector.add(2, 0);
    EXPECT_EQ(vector[0], 2);
}

TEST_F(VectorTemplateTests, IndexAddHandlesIndexGreaterThanSize) {
    EXPECT_THROW(vector.add(1, 1), IndexException);
}


TEST_F(VectorTemplateTests, Remove) {
    vector.add(1);

    dato = vector.remove();
    EXPECT_EQ(dato, 1);
}

TEST_F(VectorTemplateTests, RemoveHandlesEmptyVector) {
    EXPECT_THROW(vector.remove(), EmptyException);
}

TEST_F(VectorTemplateTests, IndexRemove) {
    vector.add(1);
    vector.add(2);

    dato = vector.remove(0);
    EXPECT_EQ(dato, 1);

    dato = vector.remove(0);
    EXPECT_EQ(dato, 2);
}

TEST_F(VectorTemplateTests, IndexRemoveHandlesEmptyVector) {
    EXPECT_THROW(vector.remove(0), EmptyException);
}

TEST_F(VectorTemplateTests, IndexRemoveHandlesIndexGreaterThanSize) {
    vector.add(1);

    EXPECT_THROW(vector.remove(1), IndexException);
}

TEST_F(VectorTemplateTests, Empty) {
    EXPECT_TRUE(vector.empty());

    vector.add(1);
    EXPECT_FALSE(vector.empty());

    vector.remove();
    EXPECT_TRUE(vector.empty());
}

TEST_F(VectorTemplateTests, Size) {
    EXPECT_EQ(vector.size(), 0);

    vector.add(1);
    vector.add(2);
    vector.add(3);
    EXPECT_EQ(vector.size(), 3);

    vector.remove();
    EXPECT_EQ(vector.size(), 2);
}

TEST_F(VectorTemplateTests, AccessOperator) {
    vector.add(1);
    vector.add(2, 0);
    vector.add(3);
    dato = vector.remove(0);

    EXPECT_EQ(vector[1], 3);
    EXPECT_EQ(dato, 2);
}

TEST_F(VectorTemplateTests, AccessOperatorHandlesEmptyVector) {
    EXPECT_THROW(vector[0], EmptyException);
}

TEST_F(VectorTemplateTests, AccessOperatorHandlesIndexGreaterThanSize) {
    vector.add(1);

    EXPECT_THROW(vector[1], IndexException);
}