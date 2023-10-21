#pragma once

#include "figure.hpp"
#include <iostream>

class Trapezia : public Figure{
    friend std::ostream& operator << (std::ostream& os, const Trapezia& f);
    friend std::istream& operator >> (std::istream& is, Trapezia& f);

    public:
        Trapezia();
        Trapezia(Point& p1, Point& p2, Point& p3, Point& p4);
        
        virtual double square() const override;
        virtual Point center() const override;
       // Point get_point(const int i) const;

        Trapezia& operator = (const Trapezia &other);
        Trapezia& operator = (Trapezia &&other);
        bool operator == (const Trapezia &other);
        virtual operator double() const override;

        ~Trapezia(){};

    private:
        Point po[4];

};