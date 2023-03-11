#include "man.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class StubSum
    : public ISum
{
public:
     int Add(int) override
     {
         return 0;
     }
};

class MockSum
    : public ISum
{
public:
    MOCK_METHOD(int, Add, (int), (override));
};

TEST(ManTests, CreationTets)
{
    EXPECT_ANY_THROW(Man man(nullptr));
}

TEST(ManTests, StubTets)
{
    auto sumStub = std::make_shared<StubSum>();
    Man man(sumStub);
    EXPECT_EQ(0, man.Sum({1, 2, 3}));
}

TEST(ManTests, MockTets_1)
{
    auto mockStub = std::make_shared<MockSum>();
    Man man(mockStub);

    EXPECT_CALL(*mockStub, Add(42)).WillOnce(testing::Return(42));

    EXPECT_EQ(42, man.Sum({42}));
}

TEST(ManTests, MockTets_2)
{
    auto mockStub = std::make_shared<MockSum>();
    Man man(mockStub);

    EXPECT_CALL(*mockStub, Add(testing::_)).WillRepeatedly(testing::Return(100));

    EXPECT_EQ(100, man.Sum({10, 80, 10}));
}

TEST(ManTests, MockTets_3)
{
    auto mockStub = std::make_shared<MockSum>();
    Man man(mockStub);

    EXPECT_CALL(*mockStub, Add(1)).WillOnce(testing::Return(1));
    EXPECT_CALL(*mockStub, Add(2)).WillOnce(testing::Return(3));
    EXPECT_CALL(*mockStub, Add(3)).WillOnce(testing::Return(6));

    EXPECT_EQ(6, man.Sum({1, 2, 3}));
}



