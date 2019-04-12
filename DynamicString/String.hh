#include <iostream>
#pragma once

class String {
private:
    uint32_t length;
    uint32_t capacity;
    char* s;
public:
    String() : length(0), capacity(0), s(nullptr) {}
    String(const char str[]);
    ~String() { delete [] s;}
    String(const String& orig);
    String& operator =(const String& orig);
    String(String&& orig);
};