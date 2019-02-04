/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the Stevens Honor System
*/

// Compute the nth fibonacci number using a function fibo(n).
// fibo(1) = 1
// fibo(2) = 1
// fibo(n) = fibo(n-1) + fibo(n-2)
#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

const double PHI = 1.618033988749895;

uint64_t fibo(uint64_t n){
    
    //First two digits of Fibonacci are 0,1. Fibo(0) and Fibo(1) should return 0,1 respectively, or in other case n.
    if (n <= 1){
        return n;
    }

    return fibo(n-1) + fibo(n-2);
}


//Fun stuff:
//Supposedly you can approximate fibo(n) by using the number Phi = 1.618033988749895
//Formula = Fibo(n) =  Phi^n / 5^(1/2)
//This is obviously faster than recursively calling the function a large quanitity of times.

int main(){
    int n = 0;
    cout << "Enter which n-th value of Fibonacci you would like: ";
    cin >> n;

    cout << fibo(0) << endl;
    cout << fibo(1) << endl;
    cout << fibo(2) << endl;
    cout << fibo(3) << endl;
    cout << "Approximating..." << pow(PHI,n) / pow(5,.5) << endl;
    cout << "Please wait..." << endl;
    cout << fibo(n) << endl;
    

}