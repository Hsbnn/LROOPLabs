#include "trapezia.hpp"

using namespace std;

Trapezia::Trapezia() : po{Point(), Point(), Point(), Point()} {}

Trapezia::Trapezia(Point& p1, Point& p2, Point& p3, Point& p4) : po{p1, p2, p3, p4}  {}

Point Trapezia::center() const {
    //cout << "Trapezia center() " << endl;
    double x = 0, y = 0;
    for(size_t i = 0; i < 4; ++i){
        x += po[i].x_;
        y += po[i].y_;
    }
    return Point(x / 4.0, y / 4.0);
}

double Trapezia::square() const {
    //cout << "Для вычисления площади трапеции необходимо, чтобы координаты были перечислены в порядке следования часовой стрелке, начиная от левой нижней точки. " << endl;
    //cout << "Trapezia square() " << endl;
    double x1 = po[0].x_; double y1 = po[0].y_;
    double x2 = po[1].x_; double y2 = po[1].y_;
    double x3 = po[2].x_; double y3 = po[2].y_;
    double x4 = po[3].x_; double y4 = po[3].y_;

    double S = abs(x1*y2 + x2*y3 + x3*y4 + x4*y1 - x2*y1 - x3*y2 - x4*y3 - x1*y4) / 2.0;
    return S;
}

Trapezia& Trapezia::operator = (const Trapezia &other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 4; ++i){
        po[i] = other.po[i];
    }

    return *this;
}

Trapezia& Trapezia::operator = (Trapezia &&other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 4; ++i){
        po[i] = move(other.po[i]);
        //po[i] = other.po[i];
        //other.po[i] = nullptr;
        
    }

    return *this;
}



bool Trapezia::operator == (const Trapezia& other){
    for(size_t i = 0; i < 4; ++i){
        if(po[i] != other.po[i]){
            return false;
        }
    }
    return true;
}

ostream& operator << (ostream& os, const Trapezia& trapezia){
    //os << "Trapezia's coordinates x,y: "<< endl;
    for(size_t i = 0; i < 4; ++i){
        os << trapezia.po[i] << endl;
    }
    return os;
}

istream& operator >> (istream& is, Trapezia& trapezia) {
    cout << "Введите координаты трапеции по часовой стрелке, начиная от левой нижней вершины (x1 y1 ... x4 y4): " << endl;
    for (size_t i = 0; i < 4; ++i) {
         is >> trapezia.po[i];
    }
    return is;
}

Trapezia::operator double() const{
    return square();
}

/*Point Trapezia::get_point(const int i) const{
    if ( i < 0 || 3 < i){
        throw invalid_argument("Out of index range");
    }
    return po[i];
}*/