/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the Stevens Honor System
*/
#include <iostream>
using namespace std;

int main(){
    int a;
    int count = 0;

    cout << "Enter an number: ";
    cin >> a;

    do{
        //Even
        if (a % 2 == 0){
            a = a / 2;
        }

        //Odd
        else {
            a = a * 3 + 1;
        }
    count++;
    // Uncomment below to see each iteration: 
    // cout << a << "\t"; 
    }while(a != 1);
    
    
    cout << "\nFinal number: " << a << endl << "after " << count << " iterations";
    return 0;
}