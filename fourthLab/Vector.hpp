#pragma once
#include<iostream>
#include <memory>
#include "figure.hpp"

template <typename T>
class Vector
{
    public:
        Vector();
        void resize(int new_size);
        int  size() const;
        void push_back(std::unique_ptr<Figure<T>> val);
        const std::unique_ptr<Figure<T>>& get(int ind) const;
        void remove(int ind);

        ~Vector();

    private:
        std::unique_ptr<std::unique_ptr<Figure<T>>[]> buf;
        int size_;
        int cap;
};

template <typename T>
Vector<T>::Vector() : buf(nullptr), size_(0), cap(0){ //изначально создаем с буфером 0
}


template <typename T>
void Vector<T>::resize(int new_size) {//изменяем размер буфера когда нужно
    std::unique_ptr<std::unique_ptr<Figure<T>>[]> tmp = std::make_unique<std::unique_ptr<Figure<T>>[]>(new_size);
    
    for (int i = 0; i < size_; ++i) {

        tmp[i] = std::move(buf[i]);
    }

    buf = std::move(tmp);
    cap = new_size;
}

template <typename T>
int Vector<T>::size() const{ 
    return size_;
}

template <typename T>
void Vector<T>::push_back(std::unique_ptr<Figure<T>> val){
    if (size_ == cap) {
        if (cap == 0){
            cap = 1;
        } else {
            cap *= 2;
        }
        resize(cap);
    }
    //int ind = (head + size_) % cap;
    buf[size_] = std::move(val);
    size_++;
}

template <typename T>
const std::unique_ptr<Figure<T>>& Vector<T>::get(int ind) const{

    if (ind >= 0 && ind < size_) {
        //int real_ind = (head + ind) % cap;
        return buf[ind];
    }
    throw std::out_of_range("Index is out of range");

}

template <typename T>
void Vector<T>::remove(int ind){
    if (ind < 0 || ind > size_) {
        throw std::invalid_argument("Index out of range");
    }

    for (int i = ind; i < size_ - 1; i++) {
        //int old_ind = (head + i + 1) % cap;
        buf[i] = std::move(buf[i + 1]);
    }

    size_--;

    /*if (size_ <= cap / 3) {
        resize(cap * 3/5);
    }*/
}

template <typename T>
Vector<T>::~Vector(){
    std::cout << "destructor" << std::endl;
}