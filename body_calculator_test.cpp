#include "body_calculator.h"

#include <gtest/gtest.h>

using namespace Tools;

TEST(BodyCalculatorTest, LvalueTest) {
	Weight w(100.0_lb);
	Height h(5.0_inch);
	auto ibm = Calculator::calculateIBM(w, h);
	EXPECT_EQ(500.0, ibm);
}

TEST(BodyCalculatorTest, CRTPTest) {
	Length h1(5.0_inch);
	Length h2(10.0_inch);
	auto sum = (h1 + h2).get();
	EXPECT_EQ(15.0, sum);

	double value = 10.0;
	auto sum2 = (h1 + value).get();
	EXPECT_EQ(15.0, sum2);	
}
