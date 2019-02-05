/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the Stevens Honor System
*/

#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <array>
using namespace std;

const double PI = 3.14159265359;


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

    //-(Theta - 90) is taken in order to translate North to 0 degrees and inverse to go clockwise
    dx = r*cos((-(theta-90))*PI/180);
    dy = r*sin((-(theta-90))*PI/180);

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
    double r = 0, theta = 0;
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