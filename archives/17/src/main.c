#include <stdio.h>
#include "utils.h"

/*
    If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

    If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


    NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

    https://projecteuler.net/problem=17
*/

int main(int argc,char**argv) {
    int totalCount=0;
    int counter=1;
    int i=1;
    int hundredsDigit=-1;
    int tensDigit=-1;
    while (i<=1000) {
        hundredsDigit=-1;
        tensDigit=-1;
        counter=i;
        int currentCount=totalCount;
        if (counter==1000) {
            //onethousand (11)
            totalCount+=11;
            counter-=1000;
            printf("onethousand");
        }
        if (counter>=100) {
            hundredsDigit=counter/100;
            switch (hundredsDigit) {
                case 1:
                case 2:
                case 6:{
                    //onehundred (10)
                    totalCount+=10;
                    printf("%s",hundredsDigit==1?"one":hundredsDigit==2?"two":"six");
                }break;
                case 3:
                case 7:
                case 8:{
                    //threehundred (12)
                    totalCount+=12;
                    printf("%s",hundredsDigit==3?"three":hundredsDigit==7?"seven":"eight");
                }break;
                case 4:
                case 5:
                case 9:{
                    //fourhundred (11)
                    totalCount+=11;
                    printf("%s",hundredsDigit==4?"four":hundredsDigit==5?"five":"nine");
                }break;
            }
            printf("hundred");
            counter-=hundredsDigit*100;
        }
        if (counter>=10) {
            tensDigit=counter/10;
            if (tensDigit!=0) {
                if (hundredsDigit!=-1) {
                    //and (3)
                    totalCount+=3;
                    printf("and");
                }
                if (counter<20) {
                    switch (counter) {
                        case 10:{
                            //ten (3)
                            totalCount+=3;
                            printf("ten");
                        }break;
                        case 11:{
                            //eleven (6)
                            totalCount+=6;
                            printf("eleven");
                        }break;
                        case 12:{
                            //twelve (5)
                            totalCount+=5;
                            printf("twelve");
                        }break;
                        case 13:
                        case 14:
                        case 19:{
                            //thirteen (8)
                            totalCount+=8;
                            printf("%s",counter==13?"thirteen":counter==14?"fourteen":"nineteen");
                        }break;
                        case 15:
                        case 16:{
                            //fifteen (7)
                            totalCount+=7;
                            printf("%s",counter==15?"fifteen":"sixteen");
                        }break;
                        case 17:
                        case 18:{
                            //seventeen (9)
                            totalCount+=9;
                            printf("%s",counter==17?"seventeen":"eighteen");
                        }break;
                    }
                    counter=0;
                } else {
                    switch (tensDigit) {
                        case 2:
                        case 3:
                        case 8:
                        case 9:{
                            //twenty (6)
                            totalCount+=6;
                            printf("%s",tensDigit==2?"twenty":tensDigit==3?"thirty":tensDigit==8?"eighty":"ninety");
                        }break;
                        case 4:
                        case 5:
                        case 6:{
                            //forty (5)
                            totalCount+=5;
                            printf("%s",tensDigit==4?"forty":tensDigit==5?"fifty":"sixty");
                        }break;
                        case 7:{
                            //seventy (7)
                            totalCount+=7;
                            printf("seventy");
                        }break;
                    }
                    counter-=tensDigit*10;
                }
            }
        }
        if (counter>0) {
            if (tensDigit==-1&&hundredsDigit!=-1) {
                //and (3)
                totalCount+=3;
                printf("and");
            }
            switch (counter) {
                case 1:
                case 2:
                case 6:{
                    //one (3)
                    totalCount+=3;
                    printf("%s",counter==1?"one":counter==2?"two":"six");
                }break;
                case 3:
                case 7:
                case 8:{
                    //three (5)
                    totalCount+=5;
                    printf("%s",counter==3?"three":counter==7?"seven":"eight");
                }break;
                case 4:
                case 5:
                case 9:{
                    //four (4)
                    totalCount+=4;
                    printf("%s",counter==4?"four":counter==5?"five":"nine");
                }break;
            }
        }
        printf("  %d:%d\n",i,totalCount-currentCount);
        i++;
    }
    printf("%d",totalCount);
    return 0;
}