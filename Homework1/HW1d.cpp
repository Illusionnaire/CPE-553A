/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the Stevens Honor System
*/
#include <iostream>
using namespace std;

int main(){
    float floatSum1 = 0;
    float floatSum2 = 0;
    double doubleSum1 = 0;
    double doubleSum2 = 0;
    int n = 100; //Max value of fractional denominator

    for (int i = 1; i <= n; i++){
        floatSum1 += 1.0f/i;
        doubleSum1 += 1.0/i;
    }

    for (int i = n; i >= 1; i--){
        floatSum2 += 1.0f/i;
        doubleSum2 += 1.0/i;
    }

    cout << "::Float::\nSum1 = " << floatSum1 << "\nSum2 = " << floatSum2 << "\nSum1 - Sum2 = " << floatSum1-floatSum2 << endl; 
    cout << "::Double::\nSum1 = " << doubleSum1 << "\nSum2 = " << doubleSum2 << "\nSum1 - Sum2 = " << doubleSum1-doubleSum2 << endl;


    return 0;
}



//  do this as float and as double

// 	sum1= 1/1 + 1.0/2 + ... + 1/100  approx 5.18


// 	sum2= 1/100 + 1/99 + .... + 1/1

// print out sum1
// print out sum2
// print out sum1 - sum2

// You should see that the two sums are not quite equal, which leads to the question, which is more correct?
// We will review that in class.