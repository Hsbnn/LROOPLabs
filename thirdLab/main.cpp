#include <iostream>
#include <string>
#include "Vector.hpp"

#include "point.hpp"
#include "figure.hpp"
#include "trapezia.hpp"
#include "romb.hpp"
#include "pentagon.hpp"

using namespace std;


int main(){

    /*Vector arr;
    
    Trapezia tr;
    Romb romb;
    cin >> tr >> romb;

    arr.push_back(&tr);
    arr.push_back(&romb);

    double sqtr = tr; double S;
    cout << "площадь трапеции через double  " << sqtr << endl;


    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Geometric center of figure " << i + 1 << ": " << arr.get(i)->center() << std::endl;
        std::cout << "Square of figure " << i + 1 << ": " << arr.get(i)->square() << std::endl;
        S += arr.get(i)->square();
    }

    std::cout << "Square: " << S << std::endl;*/

    Trapezia tr;
    Point p(-1,-1), p2(-2,-3), p3(-4,-3), p6(-5,-1);
    Point p4;
    p4 = p6;
    Point p10(3.0,2.0);
    Trapezia tr2(p,p2,p3,p4);
    tr = tr2;

    cout << "tr.center() 1  " << tr.center() << endl;

    return 0;
}
