#include <stdio.h>
#include "utils.h"

/*
    Euler discovered the remarkable quadratic formula:


    It turns out that the formula will produce 40 primes for the consecutive integer values . However, when  is divisible by 41, and certainly when  is clearly divisible by 41.

    The incredible formula  was discovered, which produces 80 primes for the consecutive values . The product of the coefficients, −79 and 1601, is −126479.

    Considering quadratics of the form:

    , where  and 

    where  is the modulus/absolute value of 
    e.g.  and 
    Find the product of the coefficients,  and , for the quadratic expression that produces the maximum number of primes for consecutive values of , starting with .

    https://projecteuler.net/problem=27
*/

int main(int argc,char**argv) {
    FILE*f = fopen("archives/primegenerator/primes","r");
    int startMarker=0;
    while (fgetc(f)!='{') {
        startMarker++;
    }
    fseek(f,startMarker,SEEK_SET);
    int n=0;
    while (true) {
        for (int a=1;a<1000;a++) {
            for (int b=1;b<=1000;b++) {

            }
        }
    }

    return 0;
}