#include <iostream>

template <typename T>
class Complex {
private:
    T re;
    T im;
public:
    Complex(): re(0), im(0) {}

    Complex(T re): re(re), im(0) {}

    Complex& operator=(const Complex& z);

    Complex& operator+=(const Complex& rhs);

    Complex& operator-=(const Complex& rhs);

    Complex& operator*=(const Complex& rhs);

    Complex& operator/=(const Complex& rhs);

    Complex& operator+(const Complex& rhs);

    Complex& operator-(const Complex& rhs);

    Complex& operator*(const Complex& rhs);

    Complex& operator/(const Complex& rhs);

    Complex& operator++();

    Complex operator++(int);

    Complex& operator--();

    Complex operator--(int);

    inline bool operator==(const Complex& rhs);

    inline bool operator!=(const Complex& rhs);

    inline bool operator<(const Complex& rhs);

    inline bool operator>(const Complex& rhs);

    inline bool operator<=(const Complex& rhs);

    inline bool operator>=(const Complex& rhs);

    friend std::ostream& operator<<(std::ostream& out, const Complex& z);

    friend std::istream& operator>>(std::istream& in, Complex& z);

    ~Complex() = default;
};
