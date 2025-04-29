#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
    private:
        char* str;
        int len;

    public:
        // Constructors and Destructor
        String();
        String(const char*);
        String(const String&);
        ~String();

        // Accessors
        int length() const;
        const char* c_str() const;

        // Overloaded Operators
        String& operator=(const char*);
        String& operator=(const String&);
        char& operator[](int);
        const char& operator[](int) const;
        String operator+(const char*) const;
        String operator+(const String&) const;
        friend String operator+(const char*, const String&);
        bool operator==(const char*) const;
        bool operator==(const String&) const;

        // Other Member Functions
        void clear();
        void push_back(char);
        void resize(int);
        String substr(int, int) const;
        int find(char) const;
        int find(const String&) const;
        int find(const char*) const;
        int find_last_of(char) const;
        int find_last_of(const String&) const;
        int find_last_of(const char*) const;
        String& replace(int, int, const char*);
        String& replace(int, int, const String&);
        String& replace(int, int, char);
        String& replace(int, int, int, char);
};

// Non-Member Function
std::ostream& operator<<(std::ostream&, const String&);

#endif // STRING_H
