#include "word_iterator.h"

using namespace Tools;

WordIterator::WordIterator(const char* input, char sep) : word_start_(input), current_position_(input), sep_(sep) {
	toNextWord();
}

WordIterator& WordIterator::operator++() {
	toNextWord();
	return *this;
}

WordIterator WordIterator::operator++(int) {
	WordIterator tmp(*this);
	this->operator++();
	return tmp;
}

const char* WordIterator::operator*() {
	int size = current_position_ - word_start_;
	// handle special case that the last word is reached (current_position will point to '\0')
	if (*current_position_ == '\0') {
		size += 1;
	}
	char* str(new char[size]);
	std::strncpy(str, word_start_, size-1);
	str[size-1] = '\0';
	return str;
}

WordIterator& WordIterator::operator=(const WordIterator& rhs) {
	this->word_start_ = rhs.word_start_;
	this->current_position_ = rhs.current_position_;
	this->sep_ = rhs.sep_;
	return *this;
}

bool WordIterator::operator==(const WordIterator& rhs) {
	return word_start_ == rhs.word_start_ && current_position_ == rhs.current_position_ && sep_ == rhs.sep_;
}

bool WordIterator::operator!=(const WordIterator& rhs) {
	return !(*this == rhs);
}

void WordIterator::toNextWord() {
	word_start_ = current_position_;
	while (*current_position_ != sep_ && *current_position_ != '\0') {current_position_++;}
	// current_position_ always points to the start of the next word or the end of the string
	if (*current_position_ != '\0') {
		current_position_ += 1;
	}
}
