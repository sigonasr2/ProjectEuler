#include <stdio.h>
#include "utils.h"

/*
    The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

    We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

    There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

    If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

    https://projecteuler.net/problem=33
*/

void getDigits(int numb,int*digits) {
    int counter=0;
    while (numb>0) {
        int digit=numb%10;
        numb/=10;
        digits[counter++]=digit;
    }
}

int main(int argc,char**argv) {

    
    for (int numerator=10;numerator<=99;numerator++) {
        for (int denominator=10;denominator<=99;denominator++) {
            if (numerator%10==0&&denominator%10==0||numerator>=denominator) {
                continue; //Skip trivials.
            }
            //There are 4 cases.
            int numeratorDigits[2];
            int denominatorDigits[2];
            getDigits(numerator,numeratorDigits);
            getDigits(denominator,denominatorDigits);
            boolean works=false;
            for (int i=0;i<=1;i++) {
                for (int j=0;j<=1;j++) {
                    if (numeratorDigits[i]==denominatorDigits[j]) {
                        //Try new numbers with those digits removed.
                        int newNumb1 = numeratorDigits[!i];
                        int newNumb2 = denominatorDigits[!j];
                        if ((double)newNumb1/newNumb2==(double)numerator/denominator) {
                            printf("Curious Fraction: %d/%d -> %d/%d\n",numerator,denominator,newNumb1,newNumb2);
                        }
                    }
                }
            }
        }
    }
    return 0;
}