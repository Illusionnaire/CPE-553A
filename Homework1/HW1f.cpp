/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the Stevens Honor System
*/
#include <cmath>
#include <iostream>
using namespace std;

int main(){
    float sum1 = 0;
    float sum2 = 0;
    const int n = 10000;
    //At n = 750, the value only changes every 7 values
    
    cout <<"---For " << n << " values---" << endl; 
    for(int i = 1; i <= n; i++){
        sum1 += 1.0f/(i*i);

        switch(i){
            case(n): cout << "Working forwards: " << sqrt(6*sum1) << endl;
        }
    }

    //More accurate to work backwards
     for(int i = n; i >= 1; i--){
        sum2 += 1.0f/(i*i);

        switch(i){
            case(1): cout << "Working backwards: " << sqrt(6*sum2) << endl;
        }
    }

    

    return 0;
}
