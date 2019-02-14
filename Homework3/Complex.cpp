/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the Stevens Honor System
*/

#include <iostream>
using namespace std;

class Complex {
private:
	double r,i;
public:
	Complex(double real, double imaginary) : r(real), i(imaginary){}

	void print() const{
		cout << r << " + " << i << "i\n";
	}

	Complex add(Complex y) const{
		return Complex(this->r + y.r, this->i + y.i);
	}

	friend Complex operator+(Complex x, Complex y);

	Complex operator-() const{
	return Complex(-(this->r),this->i);
	}

};

Complex operator +(Complex left, Complex right){
    return Complex(left.r + right.r, left.i + right.i);
}


int main() {
	const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
	const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
	const Complex c = a + b;   // overload operator + using the first syntax we discussed
	c.print(); // should print the following to cout: (1.5,2.0)
	// (member syntax).  Should look the same as method add where the name add
	// is replaced by operator +
	const Complex d = a.add(b); // this should be the same as the above except the name
	d.print();
	Complex e = -d;
	e.print();
}