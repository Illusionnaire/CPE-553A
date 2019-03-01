#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Body{
private:
    string Orbits;
    double mass;
    double diam;
    double perihelion;
    double aphelion;
    double orbPeriod;
    double rotPeriod;
    double axialtilt;
    double orbincline;
public:





};

int main() {
    ifstream f("solarsystem.dat");
    char buf[1024];
    string x;
    string y;
    string z;
    
    while(!f.eof()){
        f.getline(buf,sizeof(buf));
        istringstream linestr(buf);
        linestr >> x >> y >> z;
    }
    return 0;
}