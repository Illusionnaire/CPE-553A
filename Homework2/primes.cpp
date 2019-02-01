/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the Stevens Honor System
*/

#include <iostream>
#include <cmath> //For sqrt capabilities
using namespace std;

bool isPrime(unsigned long long p){
    bool check = true;

    for (int i = 2; i <= sqrt(p); i++){
        if(p % i == 0){
            check = false;
            break;
        }
    }

    return check;
}


int main(){
    long long n = 0;
    
    cout << "Check this number for prime characteristics: ";
    cin >> n;

    if (isPrime(n)) {
        cout << "This is a prime number.";
    }
    else {
        cout << "This is not a prime number.";
    }


    return 0;
}