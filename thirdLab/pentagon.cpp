#include "pentagon.hpp"
//#include <cmath>

using namespace std;

Pentagon::Pentagon() : po{Point(), Point(), Point(), Point(), Point()} {}

Pentagon::Pentagon(Point& p1, Point& p2, Point& p3, Point& p4, Point& p5) :
        po{p1, p2, p3, p4, p5} {}

Point Pentagon::center() const {
    //cout << "Pentagon center() " << endl;
    double x = 0, y = 0;
    for(size_t i = 0; i < 5; ++i){
        x += po[i].x_;
        y += po[i].y_;
    }
    return Point(x / 5.0, y / 5.0);
}

double Pentagon::square() const {
    //cout << "Pentagon square() " << endl;
    double x1 = po[0].x_; double y1 = po[0].y_;
    double x2 = po[1].x_; double y2 = po[1].y_;
    double x3 = po[2].x_; double y3 = po[2].y_;
    double x4 = po[3].x_; double y4 = po[3].y_;
    double x5 = po[4].x_; double y5 = po[4].y_;

    double S = abs(x1*y2 + x2*y3 + x3*y4 + x4*y5 + x5*y1 - y1*x2 - y2*x3 - y3*x4 - y4*x5 - y5 *x1)/2.0;
    return S;
}

Pentagon& Pentagon::operator = (const Pentagon &other){
    if (this == &other) {
    return *this;
    }

    for(size_t i = 0; i < 5; ++i){
        po[i] = other.po[i];
    }

    return *this;
}

Pentagon& Pentagon::operator = (Pentagon &&other){
    if (this == &other) {
        return *this;
    }


    for(size_t i = 0; i < 5; ++i){
        po[i] = move(other.po[i]);
        //po[i] = other.po[i];
        //other.po[i] = new Point(nullptr, nullptr);
        
    }

    return *this;
}

bool Pentagon::operator == (const Pentagon &other){
    for(size_t i = 0; i < 5; ++i){
        if(po[i] != other.po[i]){
            return false;
        }
    }
    return true;
}


ostream& operator << (std::ostream& os, const Pentagon &pentagon){
    //os << "pentagon x, y: "<< endl;
    for(size_t i = 0; i < 5; ++i){
        os << pentagon.po[i] << endl;
    }
    return os;

}

istream& operator >> (std::istream& is, Pentagon &pentagon){
    std::cout << "Введите координаты пятиугольника (x1 y1 ... x5 y5):" << std::endl;
    for(size_t i = 0; i < 5; ++i){
         is >> pentagon.po[i];
    }
    return is;
}

Pentagon::operator double() const{
    return square();
}

/*Point Pentagon::get_point(const int i) const{
    if ( i < 0 || 4 < i){
        throw invalid_argument("Out of index range");
    }
    return po[i];
}*/