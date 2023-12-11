#include <iostream>
using namespace std;

class complex {
    float realp, imagp;

public:
    complex() {
        realp = 0;
        imagp = 0;
    }

    complex(float x, float y) {
        realp = x;
        imagp = y;
    }

    complex operator+(complex &);
    complex operator*(complex &);
    
    friend istream &operator>>(istream &, complex &);
    friend ostream &operator<<(ostream &, const complex &);
};

complex complex::operator+(complex &c) {
    complex temp;
    temp.realp = realp + c.realp;
    temp.imagp = imagp + c.imagp;
    return temp;
}

complex complex::operator*(complex &c) {
    complex mul;
    mul.realp = (realp * c.realp) - (imagp * c.imagp);
    mul.imagp = (imagp * c.realp) + (realp * c.imagp);
    return mul;
}

istream &operator>>(istream &din, complex &c) {
    cout << "Enter real part of complex number: ";
    din >> c.realp;
    cout << "Enter imaginary part of complex number: ";
    din >> c.imagp;
    return din;
}

ostream &operator<<(ostream &dout, const complex &c) {
    dout << c.realp << " + " << c.imagp << "i" << endl;
    return dout;
}

int main() {
    complex c2, c3;
    complex c1(1.2, 2.2);

    cout << "Complex no 1 is: " << c1;

    cout << "Enter complex no 2:\n";
    cin >> c2;

    cout << "Complex number 1 is: " << c1;
    cout << "Complex number 2 is: " << c2;

    cout << "\nAddition of two complex numbers is: ";
    c3 = c1 + c2;
    cout << c3;

    cout << "\nMultiplication of two complex numbers is: ";
    c3 = c1 * c2;
    cout << c3;

    return 0;
}
