#include "Three.hpp"
#include <algorithm>
#include <string>

using namespace std;

bool isThreeNumber(char t) {
    return (0 <= t - '0') && (t - '0' < 3);
}

Three::Three() : _size(0), _array(nullptr) {
    //std::cout << "Default constructor" << std::endl;
}

Three::Three(const std::initializer_list<unsigned char> & t): _array(nullptr), _size(t.size()) {
    //std::cout << "Initializer list constructor" << std::endl;
    _array = new unsigned char[t.size()];
    size_t i = t.size() - 1;
    for (auto c : t) {
        if (!isThreeNumber(c)) throw std::logic_error("Not Three number");
        _array[i] = c;
        i--;
    }
}

Three::Three(const size_t &n, unsigned char t) //
{
    //std::cout << "Full constructor CHAR " << std::endl;

    // добавляем исключение, если следующий символ - не цифра числа
    if (!isThreeNumber(t)) throw std::logic_error("Not Three number");

    _array = new unsigned char[n];
    for (size_t i = 0; i < n; ++i){
        _array[i] = t;
    }
    _size = n;
}

Three::Three(const std::string & t) {
    //std::cout << "Copy string constructor" << std::endl;
    _array = new unsigned char[t.size()];
    _size = t.size();
    size_t i = t.size() - 1;
    for (auto c : t) {
        if (!isThreeNumber(c)) throw std::logic_error("Not Three number");
        _array[i] = c;
        i--;
    }
}

void Three::copyDigits(const unsigned char* otherDigits, size_t otherSize) {
    _array = new unsigned char[otherSize];
    for (size_t i = 0; i < otherSize; i++) {
        _array[i] = otherDigits[i];
    }
}

Three::Three(const Three &other) : _array(nullptr), _size(other._size) {
    //std::cout << "Copy constructor" << std::endl;
    copyDigits(other._array, _size);
} 

Three::Three(Three &&other) noexcept : _array(other._array), _size(other._size) {
    //std::cout << "Move constructor" << std::endl;
    other._array = nullptr;
    other._size = 0;
}

// ------------------------------- operator := ------------------------------------//
//checked
Three &Three::operator = (const Three &other) {
    if (this == &other) {
        return *this;
    }

    if (_array) {
        delete[] _array;
    }

    _size = other._size;
    copyDigits(other._array, _size); //поэлементно

    return *this;
}

Three &Three::operator = (Three&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    if (_array) {
        delete[] _array;
    }

    _array = other._array;
    _size = other._size;
    other._array = nullptr;
    other._size = 0;

    return *this;
}

Three::~Three() noexcept {
    //cout << "desructor called" << endl;
    if (_size > 0) {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

std::ostream& operator << (std::ostream &os, const Three &number) {
    size_t i = number._size;
    while(i--) {
        os << static_cast<char>(number._array[i]); // ))
    }
    return os;
}

bool Three::operator == (const Three &other) const {
    //std::cout << "== элементов списка " << std::endl;
    if (_size != other._size) {
        return false;
    }
    for (size_t i = 0; i < _size; i++) {
        if (_array[i] != other._array[i]) {
            return false;
        }
    }
    return true;
}

bool Three::operator > (const Three &other) const {
    
    if (_size > other._size) 
         return true;
    if (_size < other._size) 
         return false;

    size_t i = _size;
    while(i--) {
        if (_array[i] > other._array[i]) {
            return true;
        }
    }
    return false;

}

bool Three::operator < (const Three &other) const {
    if (_size < other._size)
         return true;
    if (_size > other._size) 
         return false;

    size_t i = _size;
    while(i--) {
        if (_array[i] < other._array[i]) {
            return true;
        }
    }
    return false;
}


Three Three::operator + (const Three &other) const {
    size_t maxS = max(_size, other._size) + 1;
    string res(maxS, '0');
    int a = 0, b = 0, sum = 0, ost = 0;

    for (size_t i = 0; i <= maxS - 1; i++) {
        if (i < _size){
            a = _array[i] - '0';
        } else { a = 0; }
        if (i < other._size){
           b = other._array[i] - '0'; 
        } else { b = 0; }
        
        sum = a + b + ost;
        res[i] = res[i] + sum % 3;
        ost = sum / 3;
    }

    reverse(res.begin(), res.end());
    if (res[0] == '0'){
        res.erase(0,1);
    }

    return Three(res);
}

Three Three::operator - (const Three & other) const {

    if (*this < other) {
        throw std::logic_error("Разность < 0");
    }

    if (*this == other) {
        return Three("0");
    }
    string res(_size, '0');
    int a = 0, b = 0, ost = 0;

    for (size_t i = 0; i <= _size - 1; i++) {
        if (i < other._size){
            b = other._array[i] - '0';
        } else {
            b = 0;
        }
        a = _array[i] - '0';
        res[i] = res[i] + a - b - ost;

        if (i != _size - 1){
            if (res[i] - '0' < 0){
                res[i+1] = _array[i+1] - '0';
                res[i+1] = res[i+1] - 1;
                res[i] = res[i] + 3;
            }
        }

    }
    reverse(res.begin(), res.end());
    int i = 0, k = 0;
    while(res[i] == '0') {
        ++k;
        ++i;
    }
    res.erase(0, k);
    return Three(res);
}