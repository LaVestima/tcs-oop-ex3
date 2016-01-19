#ifndef COMPLEX_H
#define COMPLEX_H


class Complex {
private:
    double x, y;
public:
    Complex() : x(0), y(0) {}
    Complex(double xx, double yy) : x(xx), y(yy) {}
    Complex operator ++ ();
    Complex operator ++ (int);
    Complex operator -- ();
    Complex operator -- (int);
    Complex operator + (Complex);
    Complex operator - (Complex);
    Complex operator * (Complex);
    Complex operator / (Complex);
    void operator += (Complex);
    void operator -= (Complex);
    void operator *= (Complex);
    void operator /= (Complex);
    bool operator < (Complex);
    bool operator > (Complex);
    bool operator <= (Complex);
    bool operator >= (Complex);
    double getRe() { return x; }
    double getIm() { return y; }
};

#endif // COMPLEX_H
