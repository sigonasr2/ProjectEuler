#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

struct String add(struct String numb1, struct String numb2){
    byte carryover=0;
    int digitCount=0;
    char*str = malloc(0);
    if (numb1.length>=numb2.length) {
        for (int offset=0;offset<numb1.length;offset++) {
            str = realloc(str,++digitCount);
            //printf("Digit count is now %d\n",digitCount);
            if (numb2.length>offset) {
                //printf("%c %c\n",numb1.str[numb1.length-offset-1],numb2.str[numb2.length-offset-1]);
                int sum=((numb1.str[numb1.length-offset-1]-'0')+(numb2.str[numb2.length-offset-1]-'0'))+((carryover>0)?carryover--:0);
                if (sum>=10) {
                    carryover=1;
                    sum-=10;
                }
                str[offset]=sum+'0';
            } else {
                str[offset]=numb1.str[numb1.length-offset-1];
            }
        }
    } else {

    }
    if (carryover>0) {
        str = realloc(str,++digitCount);
        str[digitCount-1]='1';
    }
    for (int i=0;i<digitCount/2;i++) {
        char c = str[i];
        char c2 = str[digitCount-i-1];
        str[digitCount-i-1]=c;
        str[i]=c2;
    }
    struct String newStr = {digitCount,str};
    return newStr;
}