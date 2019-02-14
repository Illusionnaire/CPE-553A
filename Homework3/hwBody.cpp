/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the Stevens Honor System
*/
#include <string>
#include <iostream>
using namespace std;

class Body {
private:
    string name;
    double mass;
    double x,y,z;
    double radius;

public:
    Body(string name,double mass, double x, double y, double z, double radius) : name(name), mass(mass), x(x), y(y), z(z), radius(radius) {}

    friend ostream& operator <<(ostream& s, Body b);

    void print() const{
        cout << mass << "\n";
        cout << x << "\n";
        cout << radius << "\n";
    }
};

ostream& operator <<(ostream& s, Body b){
    s << b.name;
    return s;
}


int main() {
	//         name      mass(kg) x y z  radius (m)
	Body earth("earth", 5.972e24, 0,0,0, 6.371e6);
	Body moon("moon",   7.34767309e22, 384.400e6,0,0,  1.737e6);
	cout << earth << '\n';
	cout << moon << '\n';
}