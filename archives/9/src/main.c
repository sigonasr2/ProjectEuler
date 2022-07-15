#include <stdio.h>
#include "utils.h"

/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

https://projecteuler.net/problem=9
*/
int main(int argc,char**argv) {
    int a=1;
    int b=2;
    int c=997;
    int sum=0;
    for (b=2;b<c;b++) {
        for (a=1;a<b;a++) {
            int tempC=1000-a-b;
            if (a*a+b*b==tempC*tempC) {
                printf("Pythagorean triplet of %d^2+%d^2=%d^2 works for %d+%d+%d=1000\n",a,b,tempC,a,b,tempC);
                printf("Product is %d",a*b*tempC);
                return 0;
            }
        }
    }
    return 0;
}