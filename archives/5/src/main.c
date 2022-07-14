#include <stdio.h>
#include "utils.h"

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

https://projecteuler.net/problem=5
*/
int main(int argc,char**argv) {
    int numb=1;
    while (true) {
        boolean isDivisible=true;
        for (int i=1;i<=20;i++) {
            if (numb%i!=0) {
                isDivisible=false;
                break;
            }
        }
        if (isDivisible) {
            printf("%d is divisible!",numb);
            break;
        } else {
            numb++;
        }
    }
    return 0;
}