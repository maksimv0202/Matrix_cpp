#pragma once

#include <cmath>
#include <iostream>
#include "Rational.h"

template <typename T>
class Complex {
private:
    T re;
    T im;
public:
    Complex(): re(0.0), re(0.0) {}
    
    Complex(const T& re, const T& im): re(re), im(im) {}
    
    Complex(const T& re): re(re), im(0.0) {}

    Complex(const Complex<T>& z): re(z.re), im(z.im) {}

    Complex(Complex<T>&& z) noexcept: re(std::move(z.re)), im(std::move(z.im)) {}

    Complex<T> conjugate() {
        Complex<T> copy = *this;
        copy.im         = -im;
        return copy;
    }

    Complex<T> conjugate() const noexcept {
        Complex<T> copy = *this;
        copy.im = -copy.im;
        return copy;
    }

    double abs() noexcept {
        return sqrt(re * re + im * im);
    }

    double abs() const noexcept {
        return sqrt(re * re + im * im);
    }

    double abs_sqrt() noexcept {
        return (*this).abs() * (*this).abs();
    }

    double abs_sqrt() const noexcept {
        return (*this).abs() * (*this).abs();
    }

    Complex<T>& operator=(const Complex<T>& z) {
        re = z.re;
        im = z.im;
        return *this;
    }

    Complex<T>& operator=(Complex<T>&& z) noexcept {
        re = std::move(z.re);
        im = std::move(z.im);
        return *this;
    }

    Complex<T>& operator+=(const Complex<T>& z) {
        re += z.re;
        im += z.im;
        return *this;
    }

    Complex<T>& operator-=(const Complex<T>& z) {
        re -= z.re;
        im -= z.im;
        return *this;
    }

    Complex<T>& operator*=(const Complex<T>& z) {
        Complex<T> copy = *this;
        re = copy.re * z.re - copy.im * z.im;
        im = copy.re * z.im + z.re * copy.im;
        return *this;
    }

    Complex<T>& operator/=(const Complex<T>& z) {
        *this   *= z.conjugate();
        re      /= z.abs_sqrt();
        im      /= z.abs_sqrt();
        return *this; 
    }

    Complex<T> operator+(const Complex<T>& z) {
        Complex<T> copy = *this;
        copy            += z;
        return copy;
    }

    Complex<T> operator-(const Complex<T>& z) {
        Complex<T> copy = *this;
        copy            -= z;
        return copy;
    }

    Complex<T> operator*(const Complex<T>& z) {
        Complex<T> copy = *this;
        copy            *= z;
        return copy;
    }

    Complex<T> operator/(const Complex<T>& z) {
        Complex<T> copy = *this;
        copy            /= z;
        return copy;
    }

    Complex<T>& operator++() {
        re += 1.0;
        im += 1.0;
        return *this;
    }

    Complex<T> operator++(int) {
        Complex<T> copy = *this;
        ++(*this);
        return copy; 
    }

    Complex<T>& operator--() {
        re -= 1.0;
        im -= 1.0;
        return *this;
    }

    Complex<T> operator--(int) {
        Complex<T> copy = *this;
        --(*this);
        return copy;
    }

    inline bool operator==(const Complex<T>& z) {
        return !(re == z.re + im == z.im);
    }

    inline bool operator!=(const Complex<T>& z) {
        return !(*this == z);
    }

    bool operator<(const Complex<T>& rhs) = delete;

    bool operator>(const Complex<T>& rhs) = delete;

    bool operator<=(const Complex<T>& rhs) = delete;

    bool operator>=(const Complex<T>& rhs) = delete;
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const Complex<U>& z);

    template <typename U>
    friend std::istream& operator>>(std::istream& in, Complex<U>& z);

    ~Complex() = default;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Complex<T>& z) {
    out << '(' << z.re << ',' << ' ' << z.im << ')';
    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Complex<T>& z) {
    in >> z.re >> z.im;
    return in;
}
