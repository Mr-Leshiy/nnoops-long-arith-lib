#include <gtest/gtest.h>

#include <limits>

#include "nnoops/long_arithmetic/big_float.hpp"
using namespace nnoops;

template <uint64_t SIZE, typename BASE_T>
struct BigFloatTestCase {
  const static uint64_t size = SIZE;
  using base_t = BASE_T;
};

template <typename T>
struct BigFloatTest : public ::testing::Test {};

TYPED_TEST_SUITE_P(BigFloatTest);

TYPED_TEST_P(BigFloatTest, comparison_test) {
  const static uint64_t size = TypeParam::size;
  using base_t = typename TypeParam::base_t;
  using BigFloatT = BigFloat<size, base_t>;

  BigFloatT val1("0.312");
  BigFloatT val2("0.32141");

  EXPECT_TRUE(val1 == val1);
  EXPECT_FALSE(val1 == val2);
  EXPECT_FALSE(val1 != val1);
  EXPECT_TRUE(val1 != val2);

  EXPECT_TRUE(val1 < val2);
  EXPECT_FALSE(val2 < val1);
  EXPECT_FALSE(val1 < val1);
  EXPECT_FALSE(val2 < val2);

  EXPECT_FALSE(val1 > val2);
  EXPECT_TRUE(val2 > val1);
  EXPECT_FALSE(val1 > val1);
  EXPECT_FALSE(val2 > val2);

  EXPECT_TRUE(val1 <= val2);
  EXPECT_FALSE(val2 <= val1);
  EXPECT_TRUE(val1 <= val1);
  EXPECT_TRUE(val2 <= val2);

  EXPECT_FALSE(val1 >= val2);
  EXPECT_TRUE(val2 >= val1);
  EXPECT_TRUE(val1 >= val1);
  EXPECT_TRUE(val2 >= val2);

  val1 = BigFloatT("-452.41");
  val2 = BigFloatT("0.415");

  EXPECT_TRUE(val1 == val1);
  EXPECT_FALSE(val1 == val2);
  EXPECT_FALSE(val1 != val1);
  EXPECT_TRUE(val1 != val2);

  EXPECT_TRUE(val1 < val2);
  EXPECT_FALSE(val2 < val1);
  EXPECT_FALSE(val1 < val1);
  EXPECT_FALSE(val2 < val2);

  EXPECT_FALSE(val1 > val2);
  EXPECT_TRUE(val2 > val1);
  EXPECT_FALSE(val1 > val1);
  EXPECT_FALSE(val2 > val2);

  EXPECT_TRUE(val1 <= val2);
  EXPECT_FALSE(val2 <= val1);
  EXPECT_TRUE(val1 <= val1);
  EXPECT_TRUE(val2 <= val2);

  EXPECT_FALSE(val1 >= val2);
  EXPECT_TRUE(val2 >= val1);
  EXPECT_TRUE(val1 >= val1);
  EXPECT_TRUE(val2 >= val2);

  val1 = BigFloatT("-452.41");
  val2 = BigFloatT("-0.415");

  EXPECT_TRUE(val1 == val1);
  EXPECT_FALSE(val1 == val2);
  EXPECT_FALSE(val1 != val1);
  EXPECT_TRUE(val1 != val2);

  EXPECT_TRUE(val1 < val2);
  EXPECT_FALSE(val2 < val1);
  EXPECT_FALSE(val1 < val1);
  EXPECT_FALSE(val2 < val2);

  EXPECT_FALSE(val1 > val2);
  EXPECT_TRUE(val2 > val1);
  EXPECT_FALSE(val1 > val1);
  EXPECT_FALSE(val2 > val2);

  EXPECT_TRUE(val1 <= val2);
  EXPECT_FALSE(val2 <= val1);
  EXPECT_TRUE(val1 <= val1);
  EXPECT_TRUE(val2 <= val2);

  EXPECT_FALSE(val1 >= val2);
  EXPECT_TRUE(val2 >= val1);
  EXPECT_TRUE(val1 >= val1);
  EXPECT_TRUE(val2 >= val2);
}

TYPED_TEST_P(BigFloatTest, addition_test) {
  const static uint64_t size = TypeParam::size;
  using base_t = typename TypeParam::base_t;
  using BigFloatT = BigFloat<size, base_t>;

  BigFloatT val1("3124.3312");
  BigFloatT val2("-12.41551");

  EXPECT_EQ(val1 + val2, BigFloatT("3111.91569"));
  EXPECT_EQ(val2 + val1, BigFloatT("3111.91569"));

  val1 = BigFloatT("0.312415");
  val2 = BigFloatT("0.00000312");

  EXPECT_EQ(val1 + val2, BigFloatT("0.31241812"));
  EXPECT_EQ(val2 + val1, BigFloatT("0.31241812"));

  val1 = BigFloatT("2041.0");
  val2 = BigFloatT("4145000.0");

  EXPECT_EQ(val1 + val2, BigFloatT("4147041"));
  EXPECT_EQ(val2 + val1, BigFloatT("4147041"));

  val1 = BigFloatT("5.0");
  val2 = BigFloatT("15.0");

  EXPECT_EQ(val1 + val2, BigFloatT("20"));
  EXPECT_EQ(val2 + val1, BigFloatT("20"));

  val1 = BigFloatT("4120000.0");
  val2 = BigFloatT("0.00100312");

  EXPECT_EQ(val1 + val2, BigFloatT("4120000.00100312"));
  EXPECT_EQ(val2 + val1, BigFloatT("4120000.00100312"));

  EXPECT_EQ(++val1, BigFloatT("4120001.0"));
  EXPECT_EQ(val1, BigFloatT("4120001.0"));

  EXPECT_EQ(val1++, BigFloatT("4120001.0"));
  EXPECT_EQ(val1, BigFloatT("4120002.0"));
}

TYPED_TEST_P(BigFloatTest, substraction_test) {
  const static uint64_t size = TypeParam::size;
  using base_t = typename TypeParam::base_t;
  using BigFloatT = BigFloat<size, base_t>;

  BigFloatT val1("3124.3312");
  BigFloatT val2("-12.41551");

  EXPECT_EQ(val1 - val2, BigFloatT("3136.74671"));
  EXPECT_EQ(val2 - val1, BigFloatT("-3136.74671"));

  val1 = BigFloatT("0.312415");
  val2 = BigFloatT("0.00000312");

  EXPECT_EQ(val1 - val2, BigFloatT("0.31241188"));
  EXPECT_EQ(val2 - val1, BigFloatT("-0.31241188"));

  val1 = BigFloatT("2041.0");
  val2 = BigFloatT("4145000.0");

  EXPECT_EQ(val1 - val2, BigFloatT("-4142959.0"));
  EXPECT_EQ(val2 - val1, BigFloatT("4142959.0"));

  val1 = BigFloatT("5.0");
  val2 = BigFloatT("15.0");

  EXPECT_EQ(val1 - val2, BigFloatT("-10"));
  EXPECT_EQ(val2 - val1, BigFloatT("10"));

  val1 = BigFloatT("4120000.0");
  val2 = BigFloatT("0.00100312");

  EXPECT_EQ(val1 - val2, BigFloatT("4119999.99899688"));
  EXPECT_EQ(val2 - val1, BigFloatT("-4119999.99899688"));

  EXPECT_EQ(--val1, BigFloatT("4119999.0"));
  EXPECT_EQ(val1, BigFloatT("4119999.0"));

  EXPECT_EQ(val1--, BigFloatT("4119999.0"));
  EXPECT_EQ(val1, BigFloatT("4119998.0"));
}

TYPED_TEST_P(BigFloatTest, multiplication_test) {
  const static uint64_t size = TypeParam::size;
  using base_t = typename TypeParam::base_t;
  using BigFloatT = BigFloat<size, base_t>;

  BigFloatT val1("3124.3312");
  BigFloatT val2("-12.41551");

  val1 *= val2;

  EXPECT_EQ(val1, BigFloatT("-38790.165256912"));

  val1 = BigFloatT("3124.3312");

  EXPECT_EQ(val1 * val2, BigFloatT("-38790.165256912"));
  EXPECT_EQ(val2 * val1, BigFloatT("-38790.165256912"));

  val2 *= BigFloatT("-1");

  EXPECT_EQ(val1 * val2, BigFloatT("38790.165256912"));
  EXPECT_EQ(val2 * val1, BigFloatT("38790.165256912"));

  val1 = BigFloatT("0.312415");
  val2 = BigFloatT("0.00000312");

  EXPECT_EQ(val1 * val2, BigFloatT("0.0000009747348"));
  EXPECT_EQ(val2 * val1, BigFloatT("0.0000009747348"));
}

TYPED_TEST_P(BigFloatTest, inverse_test) {
  const static uint64_t size = TypeParam::size;
  using base_t = typename TypeParam::base_t;
  using BigFloatT = BigFloat<size, base_t>;

  BigFloatT val("5.0");

  EXPECT_EQ(val.inverse(), BigFloatT("0.2"));

  // accuracy - 5
  val = BigFloatT("3.0", 5);

  EXPECT_EQ(val.inverse(), BigFloatT("0.33333"));

  // accuracy - 19
  val = BigFloatT("4134.6146161", 19);

  EXPECT_EQ(val.inverse(), BigFloatT("0.0002418605100717357"));

  // accuracy - 15
  val = BigFloatT("0.245555542", 15);

  EXPECT_EQ(val.inverse(), BigFloatT("4.072398414856383"));

  // accuracy - 15
  val = BigFloatT("-0.245555542", 15);

  EXPECT_EQ(val.inverse(), BigFloatT("-4.072398414856383"));
}

TYPED_TEST_P(BigFloatTest, division_test) {
  const static uint64_t size = TypeParam::size;
  using base_t = typename TypeParam::base_t;
  using BigFloatT = BigFloat<size, base_t>;

  // accuracy - 5
  BigFloatT val1("13.0", 5);
  BigFloatT val2("4.0", 5);

  EXPECT_EQ(val1 / val2, BigFloatT("3.25"));
  EXPECT_EQ(val2 / val1, BigFloatT("0.30768"));
  EXPECT_EQ(val1 / val1, BigFloatT("1.0"));
  EXPECT_EQ(val2 / val2, BigFloatT("1.0"));

  // accuracy - 5
  val1 = BigFloatT("121.0", 6);
  val2 = BigFloatT("5", 6);

  EXPECT_EQ(val1 / val2, BigFloatT("24.2"));
  EXPECT_EQ(val2 / val1, BigFloatT("0.04132"));
  EXPECT_EQ(val1 / val1, BigFloatT("1.0"));
  EXPECT_EQ(val2 / val2, BigFloatT("1.0"));
}

REGISTER_TYPED_TEST_SUITE_P(BigFloatTest,
                            comparison_test,
                            addition_test,
                            substraction_test,
                            multiplication_test,
                            inverse_test,
                            division_test);

typedef ::testing::Types<BigFloatTestCase<64, uint8_t>,
                         BigFloatTestCase<128, uint8_t>,
                         BigFloatTestCase<256, uint8_t>,
                         BigFloatTestCase<512, uint8_t>,
                         BigFloatTestCase<1024, uint8_t>,
                         BigFloatTestCase<2048, uint8_t>,
                         BigFloatTestCase<4096, uint8_t>,
                         BigFloatTestCase<64, uint16_t>,
                         BigFloatTestCase<128, uint16_t>,
                         BigFloatTestCase<256, uint16_t>,
                         BigFloatTestCase<512, uint16_t>,
                         BigFloatTestCase<1024, uint16_t>,
                         BigFloatTestCase<2048, uint16_t>,
                         BigFloatTestCase<4096, uint16_t>,
                         BigFloatTestCase<64, uint32_t>,
                         BigFloatTestCase<128, uint32_t>,
                         BigFloatTestCase<256, uint32_t>,
                         BigFloatTestCase<512, uint32_t>,
                         BigFloatTestCase<1024, uint32_t>,
                         BigFloatTestCase<2048, uint32_t>,
                         BigFloatTestCase<4096, uint32_t>>
    BigFloatTestCases;

INSTANTIATE_TYPED_TEST_SUITE_P(BigFloatTestSuite,
                               BigFloatTest,
                               BigFloatTestCases);

TEST(BigFloat, toPrettyString_test) {
  BigFloat<> val(1234);

  EXPECT_EQ(toPrettyString(val), "1234*e^(0)");

  val = 1234000000;

  EXPECT_EQ(toPrettyString(val), "1234*e^(6)");

  val = -1234;

  EXPECT_EQ(toPrettyString(val), "-1234*e^(0)");

  val = -1234000000;

  EXPECT_EQ(toPrettyString(val), "-1234*e^(6)");

  val = BigFloat<>("124.2134");

  EXPECT_EQ(toPrettyString(val), "1242134*e^(-4)");

  val = BigFloat<>("-124.2134");

  EXPECT_EQ(toPrettyString(val), "-1242134*e^(-4)");

  val = BigFloat<>("00000.00124");

  EXPECT_EQ(toPrettyString(val), "124*e^(-5)");

  val = BigFloat<>("-0.00124");

  EXPECT_EQ(toPrettyString(val), "-124*e^(-5)");

  val = BigFloat<>("-0.00124", 2);

  EXPECT_EQ(toPrettyString(val), "0*e^(0)");

  val = BigFloat<>("-0.1241124", 3);

  EXPECT_EQ(toPrettyString(val), "-124*e^(-3)");

  val = BigFloat<>("20000.0");

  EXPECT_EQ(toPrettyString(val), "2*e^(4)");

  val = BigFloat<>("20000");

  EXPECT_EQ(toPrettyString(val), "2*e^(4)");
}
