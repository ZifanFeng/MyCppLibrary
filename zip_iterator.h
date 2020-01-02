#ifndef ZIP_ITERATOR_H
#define ZIP_ITERATOR_H

/* 
ZipIterator can iterate multiple iterators at the same time
For example, given {1,2,3} and {'a','b','c'}, it can be seen as {1,'a'} {2,'b'} {3,'c'}
currently it only supports zipping 2 iterators	
*/
#include <iterator>
#include <tuple>

namespace Tools {

	template<typename... Iterators>
	class ZipIterator : public std::iterator<typename std::iterator_traits<typename std::tuple_element<0, std::tuple<Iterators...>>::type>::iterator_category, 
											std::tuple<typename std::iterator_traits<Iterators>::value_type...>, 
											typename std::iterator_traits<typename std::tuple_element<0, std::tuple<Iterators...>>::type>::difference_type,
											std::tuple<typename std::iterator_traits<Iterators>::pointer...>,
											std::tuple<typename std::iterator_traits<Iterators>::reference...>
											>
	{
	public:
		ZipIterator() {}
		ZipIterator(Iterators... iterators);
		ZipIterator(const ZipIterator& other) : iters_(other.iters_) {}
		ZipIterator& operator++();
		ZipIterator operator++(int);
		ZipIterator& operator=(const ZipIterator& rhs);
		bool operator==(const ZipIterator& rhs);
		bool operator!=(const ZipIterator& rhs);
		std::tuple<typename std::iterator_traits<Iterators>::value_type...> operator*();

	private:
		std::tuple<Iterators...> iters_;
	};
}

#endif // ZIP_ITERATOR_H
