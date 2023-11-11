#pragma once

#include "figure.hpp"
#include <iostream>
using namespace std;

template <typename T>
class Pentagon : public Figure<T>
{

    friend std::ostream& operator << (std::ostream& os, const Pentagon<T>&pentagon){
        //os << "pentagon x, y: "<< endl;
        for(size_t i = 0; i < 5; ++i){
            os << pentagon.po[i] << endl;
        }
        return os;
    }

    friend istream& operator >> (std::istream& is, Pentagon<T>&pentagon){
        std::cout << "Введите координаты пятиугольника (x1 y1 ... x5 y5):" << std::endl;
        for(size_t i = 0; i < 5; ++i){
            is >> pentagon.po[i];
        }
        return is;
    }

public:
    Pentagon();
    Pentagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5);

    virtual T square() const override;
    virtual Point<T> center() const override;

    Pentagon<T>& operator = (const Pentagon<T> &other);
    Pentagon<T>& operator = (Pentagon<T> &&other);
    bool operator == (const Pentagon<T> &other);
    virtual operator T () const override;


    ~Pentagon() = default;

private:
    Point<T> po[5];
};

template <typename T>
Pentagon<T>::Pentagon() : po{Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>()} {}

template <typename T>
Pentagon<T>::Pentagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5) : po{p1, p2, p3, p4, p5} {}

template <typename T>
Point<T> Pentagon<T>::center() const {
    //cout << "Pentagon center() " << endl;
    T x = 0, y = 0;
    for(size_t i = 0; i < 5; ++i){
        x += po[i].x_;
        y += po[i].y_;
    }
    return Point<T>(x / 5.0, y / 5.0);
}

template <typename T>
T Pentagon<T>::square() const {
    //cout << "Pentagon square() " << endl;
    T x1 = po[0].x_; T y1 = po[0].y_;
    T x2 = po[1].x_; T y2 = po[1].y_;
    T x3 = po[2].x_; T y3 = po[2].y_;
    T x4 = po[3].x_; T y4 = po[3].y_;
    T x5 = po[4].x_; T y5 = po[4].y_;

    T S = abs(x1*y2 + x2*y3 + x3*y4 + x4*y5 + x5*y1 - y1*x2 - y2*x3 - y3*x4 - y4*x5 - y5 *x1)/2.0;
    return S;
}

template <typename T>
Pentagon<T>& Pentagon<T>::operator = (const Pentagon<T> &other){
    if (this == &other) {
    return *this;
    }

    for(size_t i = 0; i < 5; ++i){
        po[i] = other.po[i];
    }

    return *this;
}

template <typename T>
Pentagon<T>& Pentagon<T>::operator = (Pentagon<T> &&other){
    if (this == &other) {
        return *this;
    }


    for(size_t i = 0; i < 5; ++i){
        po[i] = move(other.po[i]);
    }

    return *this;
}

template <typename T>
bool Pentagon<T>::operator == (const Pentagon<T> &other){
    for(size_t i = 0; i < 5; ++i){
        if(!(po[i] == other.po[i])){
            return false;
        }
    }
    return true;
}


template <typename T>
Pentagon<T>::operator T() const{
    return square();
}