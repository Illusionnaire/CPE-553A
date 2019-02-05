/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the Stevens Honor System
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    bool charPrint = true;
    bool palindrome = true;
    char vowels[5] = {'a','e','i','o','u'};

    cout << "Enter a string: ";
    getline(cin,input);
    
    cout << "Output backwards: ";
    //Output string backwards and check for palindrome with same for loop.
    for(int i = 0; i <= input.length(); i++){
        cout << input[input.length()-i-1];
        
        if (input[i] != input[input.length()-i-1]){
            palindrome = false;
        }
    }

    //Check value equality with array of vowels and remove if the same.
    cout << "\nWord without vowels: ";
    for(int i = 0; i <= input.length(); i++){
        for(int j = 0; j <= 5; j++){
            if(input[i] == vowels[j]){
                charPrint = false;
            }
        }
        if(charPrint){
        cout << input[i];
        }
        charPrint = true;
    }

    if (palindrome){
        cout << "\nPalindrome";
    }
    else {
        cout << "\nNot Palindrome";
    }

    return 0;
}