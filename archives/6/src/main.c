#include <stdio.h>
#include "utils.h"

/*
The sum of the squares of the first ten natural numbers is,

The square of the sum of the first ten natural numbers is,

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is .

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

https://projecteuler.net/problem=6
*/
int main(int argc,char**argv) {
    int sumOfSquares=0,squareOfSum=0;
    for (int i=0;i<=100;i++) {
        sumOfSquares+=i*i;
    }
    for (int i=0;i<=100;i++) {
        squareOfSum+=i;
    }
    squareOfSum*=squareOfSum;
    printf("%d - %d = %d",squareOfSum,sumOfSquares,squareOfSum-sumOfSquares);
    return 0;
}