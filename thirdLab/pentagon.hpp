#pragma once

#include "figure.hpp"
#include <iostream>

class Pentagon : public Figure
{

    friend std::ostream& operator << (std::ostream& os, const Pentagon& f);
    friend std::istream& operator >> (std::istream& is, Pentagon& f);

public:
    Pentagon();
    Pentagon(Point& p1, Point& p2, Point& p3, Point& p4, Point& p5);

    virtual double square() const override;
    virtual Point center() const override;

    //Point get_point(const int i) const;

    Pentagon& operator = (const Pentagon &other);
    Pentagon& operator = (Pentagon &&other);
    bool operator == (const Pentagon &other);
    virtual operator double() const override;



    ~Pentagon(){};

private:
    Point po[5];
};