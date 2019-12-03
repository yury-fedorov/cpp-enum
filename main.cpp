#include <iostream>
#include <string>
#include <set>
#include <utility> // for pair, as soon as <tuple> introduced only in C11

using namespace std;

enum Animal {
	Dog, Cat, Pig
};

// only GetValues() as an addition
template <typename E>
class AbstractEnum {
	E _value;
public:
	AbstractEnum( const E & value ) : _value(value) { }

    typedef std::set<E> (*GetValuesFunc)();
	virtual std::set<E> GetValues() const = 0;

    E Get() const { return _value; }
	void Set( const E & value ) { _value = value; }
};

// mapping to an alternative type
template <typename E, typename T>
class AbstractEnumT : public AbstractEnum<E> {
public:
	AbstractEnumT( const E & value ) : AbstractEnum<E>(value) { }
	virtual T ToT( const E & value ) const = 0;
	// TODO - void Set( const T & value ) { _value = value; }

    T To() const { return ToT( this->Get() ); }
};

template<typename E>
class EnumStr : public AbstractEnumT<E,string> {
public:
    typedef pair<E,string> ES;
    typedef std::set<ES> (*GetValuesFunc)();
private:
    GetValuesFunc _map;
protected:
    EnumStr( const E & value, GetValuesFunc map ) : AbstractEnumT<E,string>(value), _map(map) { }
public:
    std::set<E> GetValues() const { return set<E>(); }
    string ToT( const E & value ) const { return ""; }
};

typedef pair<Animal,string> AS;

#define PAIR(type,name) type(name,#name)

AS pairsAnimal [] = { PAIR(AS,Dog), PAIR(AS,Cat) };
std::set<AS> setAnimal = set<AS>(begin(pairsAnimal), end(pairsAnimal));

set<AS> SetAnimal() { return setAnimal; }

class AnimalEnum : public EnumStr<Animal> {
public:
	AnimalEnum( const Animal & value ) : EnumStr<Animal>(value, SetAnimal) { }
};

int main() {
    AnimalEnum a(Dog);
    cout << "Ciao " << a.To() <<  endl;
}
