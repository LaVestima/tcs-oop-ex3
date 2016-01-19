#include "complex.h"

Complex Complex::operator ++ (int) {
    ++x;
    return Complex(x,y);
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
    //return Complex(()/(cn.x*cn.x + cn.y*cn.y), ()/());
}

void Complex::operator += (Complex cn) {
    x += cn.x;
    y += cn.y;
}

void Complex::operator -= (Complex cn) {
    x -= cn.x;
    y -= cn.y;
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
