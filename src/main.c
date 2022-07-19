#include <stdio.h>
#include "utils.h"

/*
    n! means n × (n − 1) × ... × 3 × 2 × 1

    For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
    and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

    Find the sum of the digits in the number 100!


    https://projecteuler.net/problem=20
*/
int main(int argc,char**argv) {
    struct String factorialSum = {1,"0"};
    int counter=1;
    mult((struct String){3,"575"},(struct String){4,"4200"});
    while (counter<=100) {
        counter++;
    }

    return 0;
}