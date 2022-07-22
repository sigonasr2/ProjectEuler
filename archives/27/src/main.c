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
    int primes[2500];
    char c;
    int counter=0;
    while (counter<2500) {
        int digit=0;
        while ((c=fgetc(f))!=',') {
            digit*=10;
            digit+=c-'0';
        }
        primes[counter++]=digit;
    }
    int n=0;

    int maxLength=0;
    int maxA=0;
    int maxB=0;
    
    for (int a=-999;a<1000;a++) {
        for (int b=-999;b<=1000;b++) {
            for (int p=0;p<2500;p++) {
                if (n*n+a*n+b==primes[p]) {
                    n++;
                    p=0;
                }
            }
            if (n>maxLength) {
                maxLength=n;
                maxA=a;
                maxB=b;
                printf("New max of %d found with n^2+%dn+%d\n",maxLength,maxA,maxB);
            }
            n=0;
        }
    }
    printf("\n\nProduct of maxes (%d*%d)=%ld\n",maxA,maxB,(long)maxA*maxB);

    return 0;
}