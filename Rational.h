#include <iostream>

class Rational {
private:
    int numerator;
    int denumerator;
public:
    Rational(): numerator(1), denumerator(1) {}

    Rational(int num, int denum): numerator(num), denumerator(denum) {}
    
    Rational operator+=(const Rational& rhs);

    Rational operator-=(const Rational& rhs);

    Rational operator*=(const Rational& rhs);

    Rational operator/=(const Rational& rhs);

    Rational operator+(const Rational& rhs);

    Rational operator-(const Rational& rhs);

    Rational operator*(const Rational& rhs);

    Rational operator/(const Rational& rhs);

    inline bool operator==(const Rational& rhs);

    inline bool operator!=(const Rational& rhs);

    inline bool operator<(const Rational& rhs);

    inline bool operator>(const Rational& rhs);

    inline bool operator<=(const Rational& rhs);

    inline bool operator>=(const Rational& rhs);

    std::ostream& operator<<(std::ostream& out);

    std::istream& operator>>(std::istream& in);

    ~Rational() = default;
};
