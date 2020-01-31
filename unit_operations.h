#ifndef UNIT_OPERATIONS_H
#define UNIT_OPERATIONS_H

template<typename U, typename T, template<typename, typename> class Op>
struct AbstractOps {
	const U& value() const { return static_cast<const U&>(*this); }
	U& value() { return static_cast<U&>(*this); }
private:
	// declared as private in case of wrong inheritance
	AbstractOps() = default;
	friend Op<U, T>;
};

template<typename U, typename DT = typename U::value_type>
struct Addable : public AbstractOps<U, DT, Addable> {
	using T = DT;
	U operator+(const U& other) {
		return U(this->value().get() + other.value().get()); 
	}

	U operator+(const DT& value) {
		return U(this->value().get() + value);
	}
};



#endif
