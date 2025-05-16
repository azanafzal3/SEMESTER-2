#include "string.h"
#include <cstring>

// Constructors and Destructor

String::String() {
    len = 0;
    str = new char[1];
    str[0] = '\0';
}

String::String(const char* s) {
    len = strlen(s);
    str = new char[len+1];
    strcpy(str, s);
}

String::String(const String& s) {
    len = s.len;
    str = new char[len+1];
    strcpy(str, s.str);
}

String::~String() {
    delete[] str;
}

// Accessors

int String::length() const {
    return len;
}

const char* String::c_str() const {
    return str;
}

// Overloaded Operators

String& String::operator=(const char* s) {
    if (str != s) {
        delete[] str;
        len = strlen(s);
        str = new char[len+1];
        strcpy(str, s);
    }
    return *this;
}

String& String::operator=(const String& s) {
    if (this != &s) {
        delete[] str;
        len = s.len;
        str = new char[len+1];
        strcpy(str, s.str);
    }
    return *this;
}

char& String::operator[](int i) {
    return str[i];
}

const char& String::operator[](int i) const {
    return str[i];
}

String String::operator+(const char* s) const {
    String temp;
    temp.len = len + strlen(s);
    temp.str = new char[temp.len+1];
    strcpy(temp.str, str);
    strcat(temp.str, s);
    return temp;
}

String String::operator+(const String& s) const {
    String temp;
    temp.len = len + s.len;
    temp.str = new char[temp.len+1];
    strcpy(temp.str, str);
    strcat(temp.str, s.str);
    return temp;
}

String operator+(const char* s, const String& obj) {
    String temp.len = strlen(s) + obj.len;
temp.str = new char[temp.len+1];
strcpy(temp.str, s);
strcat(temp.str, obj.str);
return temp;
}

bool String::operator==(const char* s) const {
return strcmp(str, s) == 0;
}

bool String::operator==(const String& s) const {
return strcmp(str, s.str) == 0;
}

bool String::operator!=(const char* s) const {
return strcmp(str, s) != 0;
}

bool String::operator!=(const String& s) const {
return strcmp(str, s.str) != 0;
}

bool String::operator<(const char* s) const {
return strcmp(str, s) < 0;
}

bool String::operator<(const String& s) const {
return strcmp(str, s.str) < 0;
}

bool String::operator<=(const char* s) const {
return strcmp(str, s) <= 0;
}

bool String::operator<=(const String& s) const {
return strcmp(str, s.str) <= 0;
}

bool String::operator>(const char* s) const {
return strcmp(str, s) > 0;
}

bool String::operator>(const String& s) const {
return strcmp(str, s.str) > 0;
}

bool String::operator>=(const char* s) const {
return strcmp(str, s) >= 0;
}

bool String::operator>=(const String& s) const {
return strcmp(str, s.str) >= 0;
}

// Friend functions

ostream& operator<<(ostream& os, const String& obj) {
os << obj.str;
return os;
}

istream& operator>>(istream& is, String& obj) {
char temp[String::CINLIM];
is.get(temp, String::CINLIM);
if (is)
obj = temp;
while (is && is.get() != '\n')
continue;
return is;
}
