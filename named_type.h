#ifndef NAMED_TYPE_H
#define NAMED_TYPE_H

namespace Tools {

template<typename T, typename TypeParam, template<typename, typename> class... Skills>
class NamedType : public Skills<NamedType<T, TypeParam, Skills...>, T>... {
public:
	typedef T value_type;
	explicit NamedType(T&& val) : value_(std::move(val)){}
	explicit NamedType(const T& val) : value_(val){}
	T& get() {return value_;}
	const T& get() const {return value_;}

private:
	T value_;

};
}

#endif
