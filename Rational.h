#pragma once

#include <iostream>

class Rational {
private:
    int numerator;
    int denumerator;
public:
    Rational(): numerator(1), denumerator(1) {}

    Rational(int num, int denum): numerator(num), denumerator(denum) {} 

    Rational(int num): numerator(num), denumerator(1) {}

    Rational(const Rational& rhs): numerator(rhs.numerator), denumerator(rhs.denumerator) {}

    Rational(Rational&& rhs) noexcept: numerator(std::move(numerator)), denumerator(std::move(denumerator)) {}

    Rational& operator=(const Rational& rhs) {
        numerator       = rhs.numerator;
        denumerator     = rhs.denumerator;
        return *this;
    }
    
    Rational& operator=(Rational&& rhs) noexcept {
        numerator       = std::move(rhs.numerator);
        denumerator     = std::move(rhs.denumerator);
        return *this;
    }

    Rational& operator+=(const Rational& rhs) {
        numerator       = numerator * rhs.denumerator + denumerator * rhs.numerator;
        denumerator    *= rhs.denumerator;
        return *this;
    }

    Rational& operator-=(const Rational& rhs) {
        numerator       = numerator * rhs.denumerator - denumerator * rhs.numerator;
        denumerator    *= rhs.denumerator;
        return *this;
    }

    Rational& operator*=(const Rational& rhs) {
        numerator     *= rhs.numerator;
        denumerator   *= rhs.denumerator;
        return *this;
    }

    Rational& operator/=(const Rational& rhs) {
        numerator     *= rhs.denumerator;
        denumerator   *= rhs.numerator;
        return *this;
    }

    Rational operator+(const Rational& rhs) {
        Rational copy   = *this;
        copy           += rhs;
        return copy;
    }

    Rational operator-(const Rational& rhs) {
        Rational copy   = *this;
        copy           -= rhs;
        return copy;
    }

    Rational operator*(const Rational& rhs) {
        Rational copy   = *this;
        copy           *= rhs;
        return copy;
    }

    Rational operator/(const Rational& rhs) {
        Rational copy   = *this;
        copy           /= rhs;
        return copy;
    }
    
    Rational& operator++() {
        return *this += 1;
    }

    Rational operator++(int) {
        Rational copy = *this;
        ++(*this);
        return copy;
    }

    Rational& operator--() {
        return *this -= 1;
    }

    Rational operator--(int) {
        Rational copy = *this;
        --(*this);
        return copy;
    }

    inline bool operator==(const Rational& rhs) {
        return numerator * rhs.denumerator == numerator * rhs.denumerator;
    }

    inline bool operator!=(const Rational& rhs) {
        return !(*this == rhs);
    }

    inline bool operator<(const Rational& rhs) {
        return numerator * rhs.denumerator < denumerator * rhs.numerator;
    }

    inline bool operator>(const Rational& rhs) {
        return numerator * rhs.denumerator > denumerator * rhs.numerator;
    }

    inline bool operator<=(const Rational& rhs) {
        return !(*this > rhs);
    }

    inline bool operator>=(const Rational& rhs) {
        return !(*this < rhs);
    }

    friend std::ostream& operator<<(std::ostream& out, const Rational& num);

    friend std::istream& operator>>(std::istream& in, Rational& num);

    ~Rational() = default;
};

std::ostream& operator<<(std::ostream& out, const Rational& num) {
    if (num.denumerator == 1)
        out << num.numerator;
    else
        out << num.numerator << '/' << num.denumerator;
    return out;
}

std::istream& operator>>(std::istream& in, Rational& num) {
    if (num.denumerator == 1)
        in >> num.numerator;
    else
        in >> num.numerator >> num.denumerator;
    return in;
}

