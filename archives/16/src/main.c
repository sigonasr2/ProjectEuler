#include <stdio.h>
#include "utils.h"

/*
    215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

    What is the sum of the digits of the number 21000?


    https://projecteuler.net/problem=16
*/

int main(int argc,char**argv) {
    
    int i=1;
    struct String numb = {1,"2"};
    while (i++<1000) {
        numb = add(numb,numb);
    }
    //printf("%s",numb.str);
    int sum=0;
    for (int j=0;j<numb.length;j++) {
        sum+=numb.str[j]-'0';
    }
    printf("The sum of the digits of %s is %d",numb.str,sum);
    return 0;
}