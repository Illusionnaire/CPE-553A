/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the Stevens Honor System
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    bool printing = true;
    bool palindrome = true;
    char vowels[5] = {'a','e','i','o','u'};

    cout << "Enter a string: ";
    getline(cin,input);
    
    cout << "Output backwards: ";
    //Output string backwards and check for palindrome at the same time.
    for(int i = 0; i <= input.length(); i++){
        cout << input[input.length()-i-1];
        
        if (input[i] != input[input.length()-i-1]){
            palindrome = false;
        }
    }

    cout << "\nWord without vowels: ";
    for(int i = 0; i <= input.length(); i++){
        for(int j = 0; j <= 5; j++){
            if(input[i] == vowels[j]){
                printing = false;
            }
        }
        if(printing){
        cout << input[i];
        }
        printing = true;
    }

    if (palindrome){
        cout << "\nPalindrome";
    }
    else {
        cout << "\nNot Palindrome";
    }

    return 0;
}

// Write a program to read in a complete line of input from cin as a string.
// 1. print out the string backward
// 2. Print true if the string is the same backward and forward (palindrome)
// For example, the following input lines should result in true:
// ewe
// racecar
// 3. Remove all vowels (a,e,i, o, u) and print out the string:
// Example: for the input
// hello there
// output is:
// hll thr