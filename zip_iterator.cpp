#include "zip_iterator.h"

#include <algorithm>
#include <string>
#include <tuple>

using namespace Tools;

template<typename... Iterators>
inline ZipIterator<Iterators...>::ZipIterator(Iterators... iterators) : iters_(std::make_tuple(iterators...)) {}

template<typename... Iterators>	
inline ZipIterator<Iterators...>& ZipIterator<Iterators...>::operator++() {
	// TODO: create for_each_tuple to loop over the iterators 
	std::get<0>(iters_)++;
	std::get<1>(iters_)++;
	return *this;
}

template<typename... Iterators>
inline ZipIterator<Iterators...> ZipIterator<Iterators...>::operator++(int) {
	ZipIterator tmp(*this);
	operator++();
	return tmp;
}

template<typename... Iterators>
inline ZipIterator<Iterators...>& ZipIterator<Iterators...>::operator=(const ZipIterator& rhs) {
	iters_ = rhs.iters_;
	return *this;
}

template<typename... Iterators>
inline bool ZipIterator<Iterators...>::operator==(const ZipIterator& rhs) {
	return iters_ == rhs.iters_;
}

template<typename... Iterators>
inline bool ZipIterator<Iterators...>::operator!=(const ZipIterator& rhs) {
	return !(*(this) == rhs);
}

template<typename... Iterators>
inline std::tuple<typename std::iterator_traits<Iterators>::value_type...> ZipIterator<Iterators...>::operator*() {
	std::tuple<typename std::iterator_traits<Iterators>::value_type...> res;
	// TODO: create for_each_tuple to loop over the iterators 
	std::get<0>(res) = *std::get<0>(iters_);
	std::get<1>(res) = *std::get<1>(iters_);
	return res;
}

