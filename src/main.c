#include <stdio.h>
#include "utils.h"

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

https://projecteuler.net/problem=7
*/
int main(int argc,char**argv) {
    FILE*f=fopen("archives/primegenerator/primes","r");
    int count=0;
    while (count!=10000) {
        int c = fgetc(f);
        if (c==',') {
            count++;
            printf("Found comma #%d\n",count);
        }
    }
    int c;
    long numb=0;
    while ((c=fgetc(f))!=',') {
        printf("Read %c\n",c);
        numb*=10;
        numb+=c-'0';
    }
    fclose(f);
    printf("%ld",numb);
    return 0;
}