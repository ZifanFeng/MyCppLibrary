#ifndef WORD_ITERATOR_H
#define WORD_ITERATOR_H

/* 
WorldIterator takes a seperator and a string, and iterate through each word seperated by the sep
*/

#include <iterator>
#include <memory>
#include <string>

namespace Tools {
	class WordIterator : public std::iterator<std::input_iterator_tag, char*> {

	public:
		WordIterator() : word_start_(0), current_position_(0), sep_(0) {}
		WordIterator(const char* input, char sep);
		WordIterator(const WordIterator& other) : word_start_(other.word_start_), current_position_(other.current_position_), sep_(other.sep_) {}
		WordIterator& operator++();
		WordIterator operator++(int);
		WordIterator& operator=(const WordIterator& rhs);
		bool operator==(const WordIterator& rhs);
		bool operator!=(const WordIterator& rhs);
		const char* operator*();
	private:
		const char* word_start_;
		const char* current_position_;
		char sep_;
		void toNextWord(); 
	};
}

#endif 
