#include "String.hh"
#include <memory.h>

String::String(const String& orig): length(orig.length),capacity(orig.capacity), s(new char[capacity]){
    memcpy(s, orig.s, length);
}

String& String::operator =(const String& orig){
    String copy(orig);
    this->length = copy.length;
    this->capacity = copy.length;
    swap(s, copy.s);
    return *this;
}

String::String(String&& orig) : length(orig.length), 
                                capacity(orig.capacity), 
                                s(orig.s) 
{
    orig.s = nullptr;
}