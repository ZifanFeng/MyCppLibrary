#include "zip_iterator.h"
#include "zip_iterator.cpp"

#include <gtest/gtest.h>
#include <set>
#include <string>
#include <vector>

using namespace Tools;

typedef typename std::vector<int>::iterator IntIterator;
typedef typename std::vector<char>::iterator CharIterator;
typedef ZipIterator<IntIterator, CharIterator> TestIterator;

struct zipIteratorState {
    int minLength;
	std::vector<int> intVec;
    std::vector<char> charVec;
};

class ZipIteratorTestFixtureBase : public ::testing::Test {
public: 
	TestIterator* iterptr_;
	TestIterator iter_;

    virtual void TearDown() {
        if (iterptr_) {
            delete iterptr_;
        }
    }
};

class ZipIteratorTest :public ZipIteratorTestFixtureBase, 
						public ::testing::WithParamInterface<struct zipIteratorState> {
public:
	virtual void SetUp() {
		auto as = GetParam();
		iterptr_ = new TestIterator(as.intVec.begin(), as.charVec.begin());
		iter_ = *iterptr_;
	}	
};

// test the operator '*', 'iter++' and '++iter'
TEST_P(ZipIteratorTest, IncrementTest) { 
    auto as = GetParam();
    auto curvalues = *iter_;
    EXPECT_EQ(as.intVec[0], std::get<0>(curvalues));
    EXPECT_EQ(as.charVec[0], std::get<1>(curvalues));
    if (as.minLength <= 1) {return;}
    iter_++;
    curvalues = *iter_;
    EXPECT_EQ(as.intVec[1], std::get<0>(curvalues));
    EXPECT_EQ(as.charVec[1], std::get<1>(curvalues));
    if (as.minLength <= 2) {return;}
    ++iter_;
    curvalues = *iter_;
    EXPECT_EQ(as.intVec[2], std::get<0>(curvalues));
    EXPECT_EQ(as.charVec[2], std::get<1>(curvalues));
}

// test the operator '=', '==' and '!='
TEST_P(ZipIteratorTest, CompareTest) { 
    auto as = GetParam();
    TestIterator cpy(iter_);
    EXPECT_TRUE(iter_ == cpy);
    EXPECT_FALSE(iter_ != cpy);
    iter_++;
    EXPECT_TRUE(iter_ != cpy);
    EXPECT_FALSE(iter_ == cpy);
}

INSTANTIATE_TEST_SUITE_P(
        IteratorTest,
        ZipIteratorTest,
        ::testing::Values(
                zipIteratorState{4, std::vector<int>{1,2,3,4}, std::vector<char>{'a','b','c','d'}}
                ));