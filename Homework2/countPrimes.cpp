/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the Stevens Honor System
*/

// int countPrimes(unsigned long long a, unsigned long long b) { ...}
// The main program should read in two numbers, and print out the result from this function.
// For example, if I type:
// 1 10
// there are 2,3,5,7 = 4 primes between 1 and 10 so the output should be:
// 4
// The range is inclusive, so if I type
// 11 17
// the output should be:
// 3

#include <iostream>
#include <cmath> //For sqrt capabilities
using namespace std;

int countPrime(unsigned long long p, unsigned long long b){
    int notPrimes = 0;
    int primes = 0;
    
    //Make sure at minimum range starts at 2
    if (p < 2){
        p = 2;
    }

    //Do for entire range
    for(int i = p; i <= b; i++){
        //For individual number
        for (int j = 2; j <= sqrt(i); j++){
            //Easier to keep track of non-Primes and then subtract from total tries
            if(i % j == 0){
                notPrimes++;
                break;
            }
        }
    }

    primes = (b-p) + 1 - notPrimes;

    return primes;
}


int main(){
    unsigned long long r_min = 0; 
    unsigned long long r_max = 0;
    int primes = 0;

    cout << "Check this range for prime numbers: ";
    cin >> r_min >> r_max;

    primes = countPrime(r_min,r_max);

    cout << "There are " << primes << " primes."; 
    


    return 0;
}