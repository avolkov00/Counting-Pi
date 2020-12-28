#pragma once
#include <cassert>
using namespace std;
class rationalNumber
{
public:
	rationalNumber(long long int num, long long int denom = 1)
    {
        assert(denom != 0);
        numerator = num;
        denominator = denom;
    }
    long long int numerator;
    long long int denominator;
	void cut();
    rationalNumber operator+ (rationalNumber num);
    rationalNumber operator- (rationalNumber num);

    rationalNumber operator* (rationalNumber num);
    rationalNumber operator/ (rationalNumber num);

    void print();
};
