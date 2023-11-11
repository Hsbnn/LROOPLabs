#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "point.hpp"

using namespace std;


template <typename T>
class Figure{
    public:
        Figure() = default; 
        virtual T square() const = 0;
        virtual Point<T> center() const = 0;

        virtual operator T() const = 0;
        ~Figure() = default; 
};