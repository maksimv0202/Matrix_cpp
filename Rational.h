#include <iostream>

class Rational {
private:
    int numerator;
    int denumerator;
public:
    Rational(): numerator(1), denumerator(1) {}

    Rational(int num, int denum): numerator(num), denumerator(denum) {} 

    Rational(int num): numerator(num), denumerator(1) {}

    Rational operator=(const Rational& rhs) {
        this->numerator     = rhs.numerator;
        this->denumerator   = rhs.denumerator;
    }

    Rational operator+=(const Rational& rhs) {
        this->numerator     = this->numerator * rhs.denumerator + this->denumerator * rhs.numerator;
        this->denumerator  *= rhs.denumerator;
        return *this;
    }

    Rational operator-=(const Rational& rhs) {
        this->numerator     = this->numerator * rhs.denumerator - this->denumerator * rhs.numerator;
        this->denumerator  *= rhs.denumerator;
        return *this;
    }

    Rational operator*=(const Rational& rhs) {
        this->numerator     *= rhs.numerator;
        this->denumerator   *= rhs.denumerator;
        return *this;
    }

    Rational operator/=(const Rational& rhs) {
        this->numerator     *= rhs.denumerator;
        this->denumerator   *= rhs.numerator;
        return *this;
    }

    Rational operator+(const Rational& rhs) {
        return *this += rhs;
    }

    Rational operator-(const Rational& rhs) {
        return *this -= rhs;
    }

    Rational operator*(const Rational& rhs) {
        return *this *= rhs;
    }

    Rational operator/(const Rational& rhs) {
        return *this /= rhs;
    }

    inline bool operator==(const Rational& rhs) {
        return this->numerator * rhs.denumerator == this->numerator * rhs.denumerator;
    }

    inline bool operator!=(const Rational& rhs) {
        return !(*this == rhs);
    }

    inline bool operator<(const Rational& rhs) {
        return this->numerator * rhs.denumerator < this->denumerator * rhs.numerator;
    }

    inline bool operator>(const Rational& rhs) {
        return this->numerator * rhs.denumerator > this->denumerator * rhs.numerator;
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

