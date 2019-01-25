/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the Stevens Honor System
*/
// sum the numbers from 1 to 100.
// Display the answer using the Gauss formula n(n+1)/2
// Display the answer using a loop.  Verify that both answers are the same.
#include <iostream>
using namespace std;

int main(){
int sum1 = 0;
int sum2 = 0;
int n = 100;


//Loop approach
for(int i = 0; i <= n; i++){
    sum1 += i;
}

//Gauss Formula approach
sum2 = n*(n+1)/2;

cout << "Loop sum: " << sum1 << "\tGauss Sum: " << sum2 << endl;
return 0;
}