#include "../sample_lib/PIDregulator.hpp"
#include "../sample_lib/Regulator.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::AtLeast;

class MockPIDregulator : public Regulator
{
public:
  MOCK_METHOD(int, compute, (double a, double b), (override));
};

PIDregulator pid1(1, 2, 3, 4);
PIDregulator pid2(1, 1, 1, 1);

TEST(getters, Kp_Test)
{
  EXPECT_EQ(pid1.getKp(), 1);
}
TEST(getters, Ki_Test)
{
  EXPECT_EQ(pid1.getKi(), 2);
}
TEST(getters, Kd_Test)
{
  EXPECT_EQ(pid1.getKd(), 3);
}
TEST(getters, dt_Test)
{
  EXPECT_EQ(pid1.getDt(), 4);
}

TEST(ComputeMethod, returnValue0)
{
  EXPECT_EQ(pid2.compute(0, 0), 0);
}

TEST(ComputeMethod, returnValue90)
{
  EXPECT_EQ(pid2.compute(10, 40), 90);
}

TEST(ComputeMethod, callWithArguments)
{
  MockPIDregulator mpid;
  EXPECT_CALL(mpid, compute).With(std::tuple<double, double>(10, 40));
  mpid.compute(10, 40);
}
TEST(ComputeMethod, callTimes)
{
  MockPIDregulator mpid;
  EXPECT_CALL(mpid, compute).Times(AtLeast(1));
  mpid.compute(10, 40);
}
