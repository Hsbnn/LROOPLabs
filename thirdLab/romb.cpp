#include "romb.hpp"

using namespace std;

Romb::Romb() : po{Point(), Point(), Point(), Point()} {}

Romb::Romb(Point& p1, Point& p2, Point& p3, Point& p4) : po{p1, p2, p3, p4}  {}

Point Romb::center() const {
    //cout << "Romb center() " << endl;
    double x = 0, y = 0;
    for(size_t i = 0; i < 4; ++i){
        x += po[i].x_;
        y += po[i].y_;
    }
    return Point(x / 4.0, y / 4.0);
}

double Romb::square() const {
    //cout << "Romb square() " << endl;
    double x1 = po[0].x_; double y1 = po[0].y_;
    double x2 = po[1].x_; double y2 = po[1].y_;
    double x3 = po[2].x_; double y3 = po[2].y_;
    double x4 = po[3].x_; double y4 = po[3].y_;
    /*
             /\
            /  \ .(x3, y3)
 (x1, y1) ' \  / 
             \/
    */
    //первая диагональ
    double d1 = sqrt(pow(abs(x1 - x3),2) + pow(abs(y1 - y3),2));
    //вторая диагональ
    double d2 = sqrt(pow(abs(x2 - x4),2) + pow(abs(y2 - y4),2));
    //площадь
    double S = (d1*d2)/2.0;
    return S;
}

Romb& Romb::operator = (const Romb &other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 4; ++i){
        po[i] = other.po[i];
    }

    return *this;
}

Romb& Romb::operator = (Romb &&other){
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



bool Romb::operator == (const Romb& other){
    for(size_t i = 0; i < 4; ++i){
        if(po[i] != other.po[i]){
            return false;
        }
    }
    return true;
}

ostream& operator << (ostream& os, const Romb& Romb){
    os << "Romb's coordinates x,y: "<< endl;
    for(size_t i = 0; i < 4; ++i){
        os << Romb.po[i] << endl;
    }
    return os;
}

istream& operator >> (istream& is, Romb& Romb) {
    cout << "Введите координаты ромба по часовой стрелке, начиная от левой вершины, ";
    cout << "если бы ромб был расположен так, чтобы его большая диагональ была параллельна оси Y (x1 y1 ... x4 y4): " << endl;
    for (size_t i = 0; i < 4; ++i) {
        is >> Romb.po[i];
    }
    return is;
}

Romb::operator double() const{
    return square();
}

/*Point Romb::get_point(const int i) const{
    if ( i < 0 || 3 < i){
        throw invalid_argument("Out of index range");
    }
    return po[i];
}*/