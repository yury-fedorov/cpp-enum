#include <iostream>
#include <string>
#include <set>

using namespace std;

enum Animal {
	Dog, Cat, Pig
};

template <typename E, typename T>
class EnumT {
	E _value;
public:
	EnumT( const E & value ) : _value(value) { }
	virtual std::set<E> GetValues() const = 0;
	virtual T toT( const E & value ) const = 0;
	void set( const E & value ) { _value = value; }
	void set( const T & value ) { _value = value; }
};

class AnimalT : public EnumT<Animal,string> {
public:
	AnimalT( const Animal & value ) : EnumT(value) { }
	std::set<Animal> GetValues() const { return std::set<Animal>(); }
	string toT( const Animal & value ) const { return ""; };
};

int main() {
    string v("");
    AnimalT a(Dog);
    cout << "Ciao!" << endl;
}
