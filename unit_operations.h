#ifndef UNIT_OPERATIONS_H
#define UNIT_OPERATIONS_H

template<typename U, template<typename, typename> class Op>
struct AbstractOps {
	const U& value() const { return static_cast<const U&>(*this); }
	U& value() { return static_cast<U&>(*this); }
};

template<typename U, typename DT = typename U::value_type>
struct Addable : public AbstractOps<U, Addable> {
	//using DataType = typename U::value_type;
	U operator+(const U& other) {
		return U(this->value().get() + other.value().get()); 
	}

	U operator+(const DT& value) {
		return U(this->value().get() + value);
	}
};



#endif
