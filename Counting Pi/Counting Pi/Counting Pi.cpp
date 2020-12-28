
#include <iostream>
#include "rationalNumber.h"
rationalNumber countPi(int n) {
    //считает с точностью до 5 знаков в знаменателе
    if (((2 * n + 1) * pow(3, n)) < pow(10,5)) {
        // возвращает сумму текущего элемента ряда со всеми последующими 
        return( (rationalNumber(pow(-1,n), (2 * n + 1) * pow(3, n)) + countPi(n + 1)));
    }
    else return 0;

}
int main()
{
    //( int(sqrt(12) * 1000), 1000) это домножение на корень из 12 по формуле лейбница)
    (rationalNumber(long long int(sqrt(12) * 10000), 10000)*countPi(0)).print();
 }
