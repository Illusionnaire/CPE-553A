/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the Stevens Honor System
*/

//Open a text file hw3c.dat.
// Each line will have two numbers.  The first is an angle theta (in degrees, with North = 0 going clockwise so East = 90 and West = 270.  The second number is the distance.
// Starting at location x=0, y = 0 compute the location of a robot if it follows the instructions.  Stop when either theta or distance is negative.  For example:
// 90.0 5.0           output should be:    Location: x = 5.0, y = 0.0
// 180.0 3.0         output should be:    Location: x = 5.0, y = -3.0
// 45.0 2.0           output should be:    Location: x = 6.4142, y = -1.5858
// -1 -1                 program terminates.
// As part of your program, write a function:
// polar2Rect(r, theta, dx,dy);
// that takes in two double precision parameters r and theta, and returns (by reference) the two answers dx and dy.
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <array>
using namespace std;

const double PI = 3.14159265359;
//Pseudo code:
// 1. Open the file and import the values into the program
// 2. Do math calculations on these values based on function polar2Rect()
// 3. Output the new location


//A table of 2 columns is made in file input with dynamic length.
// vec[0]a[0]     vec[0]a[1]
// vec[1]a[0]     vec[1]a[1]
// .... due to vector this grows dynamically as needed
// Where vec[] = element, a[0] = theta and a[1] = radius
vector<std::array<double, 2>> valueImport(vector<std::array<double, 2>> fileinput,string filename){
    ifstream myfile(filename);
    double x,y;
    
    if(myfile.is_open()){
        while(!myfile.eof()){
            myfile >> x >> y;
            
            //Input negative numbers into the file to exit, but do not add to vector size.
            if (x < 0 || y < 0){
                break;
            }

            array<double, 2> a = {x, y};
            fileinput.push_back(a);
        }
    }

    return fileinput;
}

void Polar2Rect(double r, double theta, double& dx, double& dy){
    double x,y;

    dx = r*cos(theta*PI/180);
    dy = r*sin(theta*PI/180);

    //To help fix the issues with rounded PI value.
    if ((dx < 1e-5 && dx > 0) || (dx > -1e-5 && dx < 0)){
        dx = 0;
    }
    if ((dy < 1e-5 && dy > 0) || (dy > -1e-5 && dy < 0)){
        dy = 0;
    }
}

int main(){
    double x = 0, y = 0;
    double dx = 0, dy = 0;
    double r = 5, theta = 30;
    vector<std::array<double, 2>> vect;
    
    vect = valueImport(vect,"hw3c.dat");
    
    //Loops through the vector table and receives the r and theta values previously inserted. The values are then computed into x and y.
    for(vector<std::array<double,2>>::iterator iter = vect.begin(); iter !=vect.end();iter++){
        theta = iter[0][0];
        r = iter[0][1];

        Polar2Rect(r,theta,dx,dy);
        x += dx;
        y += dy;
        cout << "Location: x = " << x << " | y = " << y << endl;
    }



    return 0;
}