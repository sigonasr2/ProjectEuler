#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

struct String mult(struct String numb1, struct String numb2) {
    struct String n1 = numb1;
    struct String n2 = numb2;
    byte carryover = 0;
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
    for (int i=n2.length-1;i>=0;i--) {
        carryover=0;
        for (int j=n1.length-1;j>=0;j--) {
            int mult = (n1.str[j]-'0')*(n2.str[i]-'0')+((carryover!=0)?carryover:0);
            //printf("  %d/%d\n",mult,carryover);
            carryover=0;
            if (mult>=10) {
                carryover=mult/10;
                mult=mult%10;
            }
            addends[(n2.length-1)-i][j+1]=mult;
        }
        if (carryover>0) {
            addends[(n2.length-1)-i][0]=carryover;
        }
    }
    //printIntDoubleArr(n2.length,n1.length+1,addends);
    struct String sum = {1,"0"};
    for (int i=0;i<n2.length;i++) {
        char val[n1.length+1+i];
        for (int j=0;j<n1.length+1+i;j++) {
            val[j]='0';
        }
        for (int j=0;j<n1.length+1;j++) {
            val[j]=addends[i][j]+'0';
        }
        sum=add((struct String){n1.length+1+i,val},sum);
        //printf("%s\n",sum.str);
    }
    if (sum.str[0]=='0') {
        char*newStr=malloc(sum.length-1);
        for (int i=1;i<sum.length;i++) {
            newStr[i-1]=sum.str[i];
        }
        free(sum.str);
        sum=(struct String){sum.length-1,newStr};
    }
    //printf("%s",sum.str);
    return sum;
}

struct String add(struct String numb1, struct String numb2){
    //printf("%s %s\n",numb1.str,numb2.str);
    byte carryover=0;
    int digitCount=0;
    char*str = malloc(1);
    //str[0]='\0';
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
                str[offset]=numb1.str[numb1.length-offset-1]+((carryover>0)?carryover--:0);
            }
            //str[offset+1]='\0';
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
                str[offset]=numb2.str[numb2.length-offset-1]+((carryover>0)?carryover--:0);
            }
            //str[offset+1]='\0';
        }
    }
    if (carryover>0) {
        str = realloc(str,++digitCount);
        str[digitCount-1]='1';
        //str[digitCount]='\0';
    }
    for (int i=0;i<digitCount/2;i++) {
        char c = str[i];
        char c2 = str[digitCount-i-1];
        str[digitCount-i-1]=c;
        str[i]=c2;
    }
    str = realloc(str,digitCount+1);
    str[digitCount]='\0';
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

struct String createBigNumber(char*numb) {
    int marker=0;
    while (numb[marker++]!='\0');
    return (struct String){marker-1,numb};
}

int*getFactors(int numb) {
    int*factorList=malloc(sizeof(int)*1);
    int factorListSize=2;
    factorList[0]=1;
    factorList[1]=numb;
    int max=numb;
    for (int i=2;i<max;i++) {
        if (numb%i==0) {
            factorList=realloc(factorList,sizeof(int)*++factorListSize);
            factorList[factorListSize-1]=i;
            if (numb/i!=i) {
                factorList=realloc(factorList,sizeof(int)*++factorListSize);
                factorList[factorListSize-1]=numb/i;
                max=numb/i;
            }
        }
    }
    factorList=realloc(factorList,sizeof(int)*++factorListSize);
    factorList[factorListSize-1]=0;
    return factorList;
}

boolean isFactor(int*factorList,int numb) {
    int counter=0;
    while (factorList[counter]!=0) {
        if (numb==factorList[counter]) {
            return true;
        }
        counter++;
    }
    return false;
}