/*
    Author: Marcin Wisniowski

    I pledge my honor I have abided by the Stevens Honor System
*/

//Windchill Table Generator
#include <cmath>
#include <iostream>

using namespace std;

//Windchill Equation (degrees F) = 35.74 + 0.6215*T - 35.75*V^0.16 + 0.4275*T*V^0.16 
// T = Air Temperature (F) , V = Wind Speed (mph)
int calcWindChill(int temperature, int windspeed){
    double windChill = 0;

    windChill = (35.74) + (0.6215 * temperature) - (35.75 * pow(windspeed, 0.16)) + (0.4275 * temperature * pow(windspeed,0.16));
    windChill = round(windChill);

    return windChill;
}

int main(){
    int temp_F = 40; //Range from 40 --> -45
    int windSpeed = 5; //Range from 5 --> 60
    
    for(int i = windSpeed; i <= 60; i+=5) {
        for(int j = temp_F = 40; j >= -45; j-=5) {
            cout << calcWindChill(j,i) << "\t";
        }
        cout << "\n";
    }
    
    

    return 0;
}