#pragma once

#include <string>
#include <iostream>
#include <ostream>
#include <initializer_list>

class Three {
public:
    Three();
    Three (const std::initializer_list<unsigned char> & t);
    Three (const std::string & t);
    Three (const Three &other);
    Three (Three &&other) noexcept;
    Three(const size_t &n, unsigned char t);

    Three& operator = (const Three& other);
    Three& operator = (Three&& other) noexcept;

    bool operator == (const Three & t) const;
    bool operator > (const Three &other) const;
    bool operator < (const Three &other) const;
    Three operator + (const Three & t) const;
    Three operator - (const Three & t) const;

    virtual ~Three() noexcept;

    friend std::ostream& operator << (std::ostream& os, const Three& number);

private:
    size_t _size;
    unsigned char* _array;
    void copyDigits(const unsigned char* otherDigits, size_t otherSize);
};