#include <iostream>
#include <string>
#include <set>

using namespace std;

enum Animal {
	Dog, Cat, Pig
};

class Enum {
    string _value;
public:
    Enum() { }
    Enum(const Enum & other) { }
    Enum(const string & value) : _value(value) { }
    virtual ~Enum() { }

    virtual set<string> GetValues() const = 0;
    virtual string GetDefault() const = 0;
    bool IsValid() const {
    	const set<string> s = GetValues();
        return s.find(_value) != s.end();
    }
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
