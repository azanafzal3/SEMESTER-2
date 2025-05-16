#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>

class Integer {
private:
    int value;
public:
    Integer();
    Integer(int value);
    Integer(const Integer& obj);
    ~Integer();

    int getValue() const;
    void setValue(int value);

    Integer operator+(const Integer& obj) const;
    Integer operator-(const Integer& obj) const;
    Integer operator*(const Integer& obj) const;
    Integer operator/(const Integer& obj) const;
    Integer operator%(const Integer& obj) const;

    Integer& operator++();
    Integer operator++(int);
    Integer& operator--();
    Integer operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Integer& obj);
    friend std::istream& operator>>(std::istream& in, Integer& obj);
};

#endif /* INTEGER_H */
