#include <iostream>
#include <string>
#include <set>

using namespace std;

enum Animal {
	Dog, Cat, Pig
};

// only GetValues() as an addition
template <typename E>
class SimpleEnum {
	E _value;
public:
	SimpleEnum( const E & value ) : _value(value) { }
	virtual std::set<E> GetValues() const = 0;

    E Get() const { return _value; }
	void Set( const E & value ) { _value = value; }
};

// mapping to an alternative type
template <typename E, typename T>
class EnumT : public SimpleEnum<E> {
public:
	EnumT( const E & value ) : SimpleEnum<E>(value) { }
	virtual T To( const E & value ) const = 0;
	// TODO - void Set( const T & value ) { _value = value; }

    T To() const { return To( this->Get() ); }
};

class AnimalT : public EnumT<Animal,string> {
public:
	AnimalT( const Animal & value ) : EnumT(value) { }
	std::set<Animal> GetValues() const { return std::set<Animal>(); }
	string To( const Animal & value ) const { return ""; };
};

/*
template <typename E>
class EnumT1 : public EnumT<E,string> {
protected:
    typedef std::set<
};
*/

int main() {
    string v("");
    AnimalT a(Dog);
    cout << "Ciao!" << endl;
}
