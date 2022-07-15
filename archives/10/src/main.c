#include <stdio.h>
#include "utils.h"

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

https://projecteuler.net/problem=10
*/
int main(int argc,char**argv) {
    FILE*f=fopen("archives/primegenerator/primes","r");
    long sum=0;
    int ch=' ';
    while ((ch=fgetc(f))!='{');
    while (true) {
        int digit=0;
        while ((ch=fgetc(f))!=',') {
            digit*=10;
            digit+=ch-'0';
        }
        if (digit>=2000000) {
            break;
        } else {
            sum+=digit;
        }
    }
    fclose(f);
    printf("\n\nThe sum of all primes below 2000000 is %ld",sum);
    return 0;
}