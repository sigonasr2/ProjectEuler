#include <stdio.h>
#include "utils.h"
#include <stdlib.h>

/*
    The Fibonacci sequence is defined by the recurrence relation:

    Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
    Hence the first 12 terms will be:

    F1 = 1
    F2 = 1
    F3 = 2
    F4 = 3
    F5 = 5
    F6 = 8
    F7 = 13
    F8 = 21
    F9 = 34
    F10 = 55
    F11 = 89
    F12 = 144
    The 12th term, F12, is the first term to contain three digits.

    What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

    https://projecteuler.net/problem=24
*/

int main(int argc,char**argv) {
    struct String numb1 = BigNumber(1);
    struct String numb2 = BigNumber(1);
    int term=3;
    while (numb2.length<1000) {
        struct String oldString = numb1;
        numb1 = numb2;
        numb2 = add(oldString,numb1); 
        //free(oldString.str);
        //printf("%d: %s\n",term,numb2.str);
        term++;
    }
    printf("\n\nTerm %d has %d digits!",term,numb2.length);
    return 0;
}