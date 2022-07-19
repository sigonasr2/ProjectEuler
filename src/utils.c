#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

struct String mult(struct String numb1, struct String numb2) {
    struct String n1 = numb1;
    struct String n2 = numb2;
    byte carryover = -1;
    if (numb2.length>numb1.length) {
        n1=numb2;
        n2=numb1;
    }
    int addends[n2.length][n1.length+1];
    for (int i=0;i<n2.length;i++) {
        for (int j=0;j<n1.length+1;j++) {
            addends[i][j]=0;
        }
    }
    printIntDoubleArr(n2.length,n1.length+1,addends);
    for (int i=n2.length-1;i>=0;i--) {
        
    }
}

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
        for (int offset=0;offset<numb2.length;offset++) {
            str = realloc(str,++digitCount);
            //printf("Digit count is now %d\n",digitCount);
            if (numb1.length>offset) {
                //printf("%c %c\n",numb1.str[numb1.length-offset-1],numb2.str[numb2.length-offset-1]);
                int sum=((numb1.str[numb1.length-offset-1]-'0')+(numb2.str[numb2.length-offset-1]-'0'))+((carryover>0)?carryover--:0);
                if (sum>=10) {
                    carryover=1;
                    sum-=10;
                }
                str[offset]=sum+'0';
            } else {
                str[offset]=numb2.str[numb2.length-offset-1];
            }
        }
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

void printLongDoubleArr(int a,int b,long doubleArr[a][b]) {
    for (int i=0;i<a;i++) {
        for (int j=0;j<b;j++) {
            printf("%ld\t",doubleArr[i][j]);
        }
        printf("\n");
    }
}

void printIntDoubleArr(int a,int b,int doubleArr[a][b]) {
    for (int i=0;i<a;i++) {
        for (int j=0;j<b;j++) {
            printf("%d\t",doubleArr[i][j]);
        }
        printf("\n");
    }
}