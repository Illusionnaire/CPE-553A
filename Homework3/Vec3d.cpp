/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the stevens honor system
*/
#include <iostream>
#include <cmath>
using namespace std;

class Vec3d{
private:
    double x,y,z;
public:
    Vec3d(double x, double y, double z) : x(x), y(y), z(z){}

    friend ostream& operator <<(ostream& s, Vec3d v);

    friend Vec3d operator +(Vec3d left, Vec3d right);

    friend Vec3d operator *(double scalar, Vec3d v);
    
    
    Vec3d operator *(double scalar) const{
        return Vec3d(this->x * scalar,this->y * scalar, this->z * scalar);
    }

    Vec3d operator -() const{
        return Vec3d(-(this->x),-(this->y),-(this->z));
    }

    double mag() const{
        return (sqrt(this->x*this->x + this->y * this->y + this->z * this->z));
    }

    double magsq() const{
        return (this->x*this->x + this->y * this->y + this->z * this->z);
    }
};

    ostream& operator <<(ostream& s, Vec3d v){
        s << "<" << v.x << ", " << v.y << ", " << v.z << ">";
        return s;
    }

    Vec3d operator +(Vec3d left, Vec3d right){
        return Vec3d(left.x + right.x,left.y + right.y, left.z + right.z);
    }

    Vec3d operator *(double scalar, Vec3d v){
        return Vec3d(scalar * v.x, scalar * v.y, scalar* v.z);
    }


int main() {
	const Vec3d a(1.0,0.5,0.0);
	const Vec3d b(1.0,0.5,0.0);
	cout << a << '\n';
	const Vec3d c = a + b;
	const Vec3d d = c * 1.5;
	const Vec3d d2 = 1.5 * c;
	const Vec3d e = -a;
	cout << c << '\n';
	cout << d << '\n';
	cout << d2 << '\n';
	cout << e << '\n';
	double m = a.mag(); // abs value, magnitude..
	cout << m << '\n';
	double msq = a.magsq();
}