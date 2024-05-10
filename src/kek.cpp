#include <stdio.h>
#include <iostream>
#include <map>
#include <functional>
#include <string>

using namespace std;

// Arithmetic interface
class Arithmetic {
public:
    virtual Arithmetic& operator+(const Arithmetic& other) = 0;
    virtual Arithmetic& operator-(const Arithmetic& other) = 0;
    virtual Arithmetic& operator*(const Arithmetic& other) = 0;
    virtual Arithmetic& operator/(const Arithmetic& other) = 0;

    virtual void display() const = 0; // Just for demonstration
    virtual ~Arithmetic() {}
};

// Class implementing the arithmetic operations for integers
class Integer : public Arithmetic {
private:
    int value;

public:
    Integer(int val) : value(val) {}

    Integer& operator+(const Arithmetic& other) override {
        const Integer& otherInteger = dynamic_cast<const Integer&>(other);
        
        Integer new_int = *this;

        new_int.value -= otherInteger.value;
        return new_int;
    }

    Integer& operator-(const Arithmetic& other) override {
        const Integer& otherInteger = dynamic_cast<const Integer&>(other);
        Integer new_int = *this;
        
        new_int.value -= otherInteger.value;
        return new_int;
    }

    Integer& operator*(const Arithmetic& other) override {
        const Integer& otherInteger = dynamic_cast<const Integer&>(other);
        value *= otherInteger.value;
        return *this;
    }

    Integer& operator/(const Arithmetic& other) override {
        const Integer& otherInteger = dynamic_cast<const Integer&>(other);
        if (otherInteger.value != 0)
            value /= otherInteger.value;
        return *this;
    }

    void display() const override {
        std::cout << "Integer value: " << value << std::endl;
    }
};

class MegaKek {
private:
    int val;
public:
    MegaKek(int new_val) : val(move(new_val)) {
        cout << &new_val << endl;
        cout << &(this->val);
    }

    int getVal() {
        //int kek = 1;
        //cout << &kek << endl;
        return val;
    }
};

int main() {
    return 1;
}