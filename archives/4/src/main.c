#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define boolean char

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

https://projecteuler.net/problem=4
*/

struct String{
    int length;
    char*str;
};

struct String numberToString(int numb) {
    int placeValues=0;
    int tempNumb=numb;
    while (tempNumb>0) {
        tempNumb/=10;
        placeValues++;
    }
    char*finalStr=malloc(placeValues+1);
    tempNumb=numb;
    int marker=placeValues-1;
    while (tempNumb>0) {
        finalStr[marker--]='0'+(tempNumb%10);
        tempNumb/=10;
    }
    struct String str={placeValues,finalStr};
    return str;
}

boolean isPalindrome(struct String numb) {
    int offset=0;
    while (offset<numb.length/2) {
        //printf("Compare %c to %c\n",numb.str[offset],numb.str[numb.length-offset-1]);
        if (numb.str[offset]!=numb.str[numb.length-offset-1]) {
            return false;
        }
        offset++;
    }
    return true;
}

int main(int argc,char**argv) {
    int numb1=999;
    int numb2=999;
    int maxPal=0;

    //printf("%s : %d",numberToString(numb1*numb2).str,numberToString(numb1*numb2).length);

    for (numb1=999;numb1>0;numb1--) {
        for (numb2=999;numb2>0;numb2--) {
            struct String str = numberToString(numb1*numb2);
            if (isPalindrome(str)) {
                printf("%d is a Palindrome!\n",numb1*numb2);
                if (maxPal<numb1*numb2) {
                    maxPal=numb1*numb2;
                    printf("  New MAX set to %d\n",maxPal);
                }
            }
            free(str.str);
        }
    }

    printf("\n\nThe maximum palindrome is %d\n",maxPal);

    return 0;
}