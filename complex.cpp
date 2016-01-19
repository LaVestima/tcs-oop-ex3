#include "complex.h"

Complex Complex::operator ++ (int) {
    return Complex(x++,y);
}

Complex Complex::operator ++ () {
    return Complex(++x,y);
}

Complex Complex::operator -- (int) {
    return Complex(x--,y);
}

Complex Complex::operator -- () {
    return Complex(--x,y);
}

Complex Complex::operator + (Complex cn) {
    return Complex(x+cn.x, y+cn.y);
}

Complex Complex::operator - (Complex cn) {
    return Complex(x-cn.x, y-cn.y);
}

Complex Complex::operator * (Complex cn) {
    return Complex(x*cn.x - y*cn.y, x*cn.y + y*cn.x);
}

Complex Complex::operator / (Complex cn) {
    return Complex((x*cn.x + y*cn.y)/(cn.x*cn.x + cn.y*cn.y), (y*cn.x - x*cn.y)/(cn.x*cn.x + cn.y*cn.y));
}

void Complex::operator += (Complex cn) {
    x += cn.x;
    y += cn.y;
}

void Complex::operator -= (Complex cn) {
    x -= cn.x;
    y -= cn.y;
}

void Complex::operator *= (Complex cn) {
    double tempX = x*cn.x - y*cn.y;
    double tempY = x*cn.y + y*cn.x;
    x = tempX;
    y = tempY;
}

void Complex::operator /= (Complex cn) {
    double tempX = (x*cn.x + y*cn.y)/(cn.x*cn.x + cn.y*cn.y);
    double tempY = (y*cn.x - x*cn.y)/(cn.x*cn.x + cn.y*cn.y);
    x = tempX;
    y = tempY;
}

bool Complex::operator < (Complex cn) {
    return (x*x + y*y < cn.x*cn.x + cn.y*cn.y) ? true : false;
}

bool Complex::operator > (Complex cn) {
    return (x*x + y*y > cn.x*cn.x + cn.y*cn.y) ? true : false;
}

bool Complex::operator <= (Complex cn) {
    return (x*x + y*y <= cn.x*cn.x + cn.y*cn.y) ? true : false;
}

bool Complex::operator >= (Complex cn) {
    return (x*x + y*y >= cn.x*cn.x + cn.y*cn.y) ? true : false;
}
