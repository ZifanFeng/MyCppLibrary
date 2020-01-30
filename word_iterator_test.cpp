#include "word_iterator.h"

#include <gtest/gtest.h>

#include <string>

using namespace Tools;

struct wordIteratorState {
	int numWords;
	char sep;
	const char* input;
	const char* firstWord;
	const char* secondWord;
	const char* lastWord;
};

class WordIteratorTestFixtureBase : public ::testing::Test {
public: 
	WordIterator* iterptr_;
	WordIterator iter_;
    virtual void TearDown() {
        if (iterptr_) {
            delete iterptr_;
        }
    }
};

class WordIteratorTest :public WordIteratorTestFixtureBase, 
			public ::testing::WithParamInterface<struct wordIteratorState> {
public:
	virtual void SetUp() {
		auto as = GetParam();
		iterptr_ = new WordIterator(as.input, as.sep);
		iter_ = *iterptr_;
	}
};

// test the operator '*', 'iter++' and '++iter'
TEST_P(WordIteratorTest, IncrementTest) { 
    auto as = GetParam();
    EXPECT_EQ(0, strcmp(as.firstWord, *iter_));
    if (as.numWords <= 1) { return; }
    ++iter_;
    EXPECT_EQ(0, strcmp(as.secondWord, *iter_));
    if (as.numWords == 2) { return; }
    for(int i = as.numWords-2; i > 0; i--) {iter_++;}
    EXPECT_EQ(0, strcmp(as.lastWord, *iter_));
}

// test the operator '=', '=='' and '!='
TEST_P(WordIteratorTest, CompareTest) { 
	auto as = GetParam();
	if (as.numWords <= 1) { return; }
	WordIterator cpyiter(as.input, as.sep);
    EXPECT_TRUE(iter_ == cpyiter);
    cpyiter++;
    EXPECT_TRUE(iter_ != cpyiter);
    WordIterator cpyiterDiffSep(as.input, as.sep+1);
    EXPECT_TRUE(iter_ != cpyiterDiffSep);
}

INSTANTIATE_TEST_SUITE_P(
        IteratorTest,
        WordIteratorTest,
        ::testing::Values(
                wordIteratorState{3, ' ', "apple banana clement", "apple", "banana", "clement"},
                wordIteratorState{4, ' ', "    ", "", "", ""},
                wordIteratorState{1, ' ', "apple", "apple", "", ""}, 
                wordIteratorState{0, ' ', "", "", "", ""}, 
                wordIteratorState{3, ',', "apple,banana,clement", "apple", "banana", "clement"}
                ));
