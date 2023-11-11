#pragma once

#include <iostream>
#include <string>

template <typename T>
class Point
{
    
    friend std::istream& operator >> (std::istream &is, Point<T> &p){
        T x, y;
        is >> x >> y;
        p.x_ = x;
        p.y_ = y;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point<T>& p){
        os << "x  " << p.x_ << ", y  " << p.y_;
        return os;
    }

public:
    Point();
    Point(const Point<T>& other);
    Point(T x, T y);

    Point<T>& operator = (const Point<T>& other);
    Point<T>& operator = (Point<T> &&other) noexcept;
    bool operator == (const Point<T>& other);

    T x_{};
    T y_{};
};

template <typename T>
Point<T>::Point() : x_{0}, y_{0} {}

template <typename T>
Point<T>::Point(T x, T y): x_{x}, y_{y} {}

template <typename T>
Point<T>::Point(const Point<T>&other) : x_(other.x_), y_(other.y_) {}


template <typename T>
bool Point<T>::operator == (const Point<T>& other) {
    return (x_ == other.x_) && (y_ == other.y_);
}

template <typename T>
Point<T>& Point<T>::operator = (const Point<T>&other){
    if (!(this == &other)) {
        x_ = other.x_;
        y_ = other.y_;
    }
    return *this;
}

template <typename T>
Point<T>& Point<T>::operator = (Point<T> &&other) noexcept {
    if (!(this == &other)) {
        // Перемещение данных из other в текущий объект
        x_ = std::move(other.x_);
        y_ = std::move(other.y_);

    }
    return *this;
}