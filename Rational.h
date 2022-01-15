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
    
    int __gcd(int l_gcd, int r_gcd) {
        int tmp = 0;
        while (r_gcd) {
            tmp = l_gcd % r_gcd;
            l_gcd = r_gcd;
            r_gcd = tmp;
        }
        return abs(l_gcd);
    }

    Rational& canonical_form() {
        int gcd     = __gcd(numerator, denumerator);
        numerator   /= gcd;
        denumerator /= gcd;
        return *this;
    }

    Rational& operator=(const Rational& rhs) {
        numerator       = rhs.numerator;
        denumerator     = rhs.denumerator;
        return (*this).canonical_form();
    }
    
    Rational& operator=(Rational&& rhs) noexcept {
        numerator       = std::move(rhs.numerator);
        denumerator     = std::move(rhs.denumerator);
        return (*this).canonical_form();
    }

    Rational& operator+=(const Rational& rhs) {
        numerator       = numerator * rhs.denumerator + denumerator * rhs.numerator;
        denumerator     *= rhs.denumerator;
        return (*this).canonical_form();
    }

    Rational& operator-=(const Rational& rhs) {
        numerator       = numerator * rhs.denumerator - denumerator * rhs.numerator;
        denumerator     *= rhs.denumerator;
        return (*this).canonical_form();
    }

    Rational& operator*=(const Rational& rhs) {
        numerator       *= rhs.numerator;
        denumerator     *= rhs.denumerator;
        return (*this).canonical_form();
    }

    Rational& operator/=(const Rational& rhs) {
        numerator       *= rhs.denumerator;
        denumerator     *= rhs.numerator;
        return (*this).canonical_form();
    }

    Rational operator+(const Rational& rhs) {
        Rational copy   = *this;
        copy            += rhs;
        return copy.canonical_form();
    }

    Rational operator-(const Rational& rhs) {
        Rational copy   = *this;
        copy            -= rhs;
        return copy.canonical_form();
    }

    Rational operator*(const Rational& rhs) {
        Rational copy   = *this;
        copy            *= rhs;
        return copy.canonical_form();
    }

    Rational operator/(const Rational& rhs) {
        Rational copy   = *this;
        copy            /= rhs;
        return copy.canonical_form();
    }
    
    Rational& operator++() {
        return (*this += 1).canonical_form();
    }

    Rational operator++(int) {
        Rational copy = *this;
        ++(*this);
        return copy.canonical_form();
    }

    Rational& operator--() {
        return (*this -= 1).canonical_form();
    }

    Rational operator--(int) {
        Rational copy = *this;
        --(*this);
        return copy.canonical_form();
    }
    
    Rational& operator,(const Rational& rhs) = delete;

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

