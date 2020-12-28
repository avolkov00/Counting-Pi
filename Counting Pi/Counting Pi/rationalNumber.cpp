#include "rationalNumber.h"
#include <iostream>
using namespace std;

int findNOD(long long int a,long long int b) {
    
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return findNOD(a % b, b);
    return findNOD(a, b % a);
}

void rationalNumber::cut() {
    int nod = findNOD(abs(numerator), abs(denominator));
    if (nod != 1 || nod != -1) {
        numerator = numerator / nod;
        denominator = denominator / nod;
    }
}

rationalNumber rationalNumber::operator+(rationalNumber num)
{
    rationalNumber sum(1, 1);
    sum.numerator = numerator * num.denominator + denominator * num.numerator;
    sum.denominator = denominator * num.denominator;
    sum.cut();
    return sum;
}

rationalNumber rationalNumber::operator-(rationalNumber num)
{
    rationalNumber sum(1, 1);
    sum.numerator = (numerator * num.denominator + (-1) * denominator * num.numerator);
    sum.denominator = denominator * num.denominator;
    sum.cut();
    return sum;
}

rationalNumber rationalNumber::operator*(rationalNumber num)
{
    rationalNumber comp(1, 1);
    comp.numerator = numerator * num.numerator;
    comp.denominator = denominator * num.denominator;
    comp.cut();
    return comp;
}

rationalNumber rationalNumber::operator/(rationalNumber num)
{
    rationalNumber  quo(1, 1);
    quo.numerator = numerator * num.denominator;
    quo.denominator = denominator * num.numerator;
    quo.cut();
    return  quo;
}

void rationalNumber::print()
{
    cout << numerator << "/" << denominator << " ~ " << float(numerator)/ denominator << endl;

}
