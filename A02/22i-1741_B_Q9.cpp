#include <iostream>
#include "Integer.h"

int main() {
    Integer a = 5;
    Integer b = 3;

std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "a + b = " << a + b << std::endl;
std::cout << "a - b = " << a - b << std::endl;
std::cout << "a * b = " << a * b << std::endl;
std::cout << "a / b = " << a / b << std::endl;
std::cout << "a % b = " << a % b << std::endl;

std::cout << "++a = " << ++a << std::endl;
std::cout << "a++ = " << a++ << std::endl;
std::cout << "a = " << a << std::endl;

std::cout << "--b = " << --b << std::endl;
std::cout << "b-- = " << b-- << std::endl;
std::cout << "b = " << b << std::endl;

std::cout << "a += b, a = " << (a += b) << std::endl;
std::cout << "a -= b, a = " << (a -= b) << std::endl;
std::cout << "a *= b, a = " << (a *= b) << std::endl;
std::cout << "a /= b, a = " << (a /= b) << std::endl;
std::cout << "a %= b, a = " << (a %= b) << std::endl;

std::cout << "a == b: " << (a == b) << std::endl;
std::cout << "a != b: " << (a != b) << std::endl;
std::cout << "a > b: " << (a > b) << std::endl;
std::cout << "a < b: " << (a < b) << std::endl;
std::cout << "a >= b: " << (a >= b) << std::endl;
std::cout << "a <= b: " << (a <= b) << std::endl;

return 0;
}