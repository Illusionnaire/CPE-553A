/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the Stevens Honor System
*/
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    long double radius = 1; //Initial circle radius
    long double newRadius;
    uint64_t n; //Sides

    cout << "Enter to which polygon it should iterate: ";
    cin >> n;

    //The longest distance away from the center of the circle is always at a vertex.
    //Since we know the circle radius, we can create 2n congruent (due to ASA posulate) triangles within the n-polygon.
    //With the law of sines, you can then find the new longest radius and re-iterate

    // old radius / sin(90-angle) = new radius / sin(90) = new radius

    //Starts at triangle (i=3) since that is the smallest polygon
    for(int i = 3; i <= n; i++){
    newRadius = radius / sin(M_PI / 2 - M_PI / i);



    switch(i){
        case 10: cout << i << "th Polygon Diagonal Length: " << radius << endl; break;
        case 100: cout << i << " Radius: " << radius << endl; break;
        case 1000: cout << i << " Radius: " << radius << endl; break;
        case 10000: cout << i << " Radius: " << radius << endl; break;
        case 100000: cout << i << " Radius: " << radius << endl; break;
        case 1000000: cout << i << " Radius: " << radius << endl;
    }

    radius = newRadius;
}
    cout << "Final Radius: " << radius;

    return 0;
}