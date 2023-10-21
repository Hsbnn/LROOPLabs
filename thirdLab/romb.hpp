#pragma once

#include "figure.hpp"
#include <iostream>

class Romb : public Figure {

    friend std::ostream& operator<<(std::ostream& os, const Romb& f);
    friend std::istream& operator>>(std::istream& is, Romb& f);

public:
    Romb();
    Romb(Point& p1, Point& p2, Point& p3, Point& p4);

    virtual double square() const override;
    virtual Point center() const override;

    //Point get_point(const int i) const;

    Romb& operator = (const Romb &other);
    Romb& operator = (Romb &&other);
    bool operator == (const Romb &other);
    virtual operator double() const override;



    ~Romb(){};

private:
    Point po[4];

};