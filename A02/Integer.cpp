#include "Integer.h"

Integer::Integer() : value(0) {}

Integer::Integer(int value) : value(value) {}

Integer::Integer(const Integer& obj) : value(obj.value) {}

Integer::~Integer() {}

int Integer::getValue() const {
    return value;
}

void Integer::setValue(int value) {
    this->value = value;
}

Integer Integer::operator+(const Integer& obj) const {
    return Integer(value + obj.value);
}

Integer Integer::operator-(const Integer& obj) const {
    return Integer(value - obj.value);
}

Integer Integer::operator*(const Integer& obj) const {
    return Integer(value * obj.value);
}

Integer Integer::operator/(const Integer& obj) const {
    return Integer(value / obj.value);
}

Integer Integer::operator%(const Integer& obj) const {
    return Integer(value % obj.value);
}

Integer& Integer::operator++() {
    ++value;
    return *this;
}

Integer Integer::operator++(int) {
    Integer temp(*this);
    ++value;
    return temp;
}

Integer& Integer::operator--() {
    --value;
    return *this;
}

Integer Integer::operator--(int) {
    Integer temp(*this);
    --value;
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Integer& obj) {
    out << obj.value;
    return out;
}

std::istream& operator>>(std::istream& in, Integer& obj) {
    in >> obj.value;
    return in;
}
