#include <stdio.h>
#include "utils.h"

/*
    Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

    How many such routes are there through a 20×20 grid?


    https://projecteuler.net/problem=15
*/

void move(int x,int y,long*pathCount) {
    if (x<21) {
        move(x+1,y,pathCount);
    }
    if (x!=0&&y<21) {
        move(x,y+1,pathCount);
    }
    if (x==20&&y==20) {
        (*pathCount)++;
    }
}

int main(int argc,char**argv) {
    int x=0;
    int y=0;
    int i=0;
    int id=0;
    while (argv[1][i]!='\0') {
        y*=10;
        y+=argv[1][i]-'0';
        i++;
    }
    id=y;
    long pathCount=0;
    move(x,y,&pathCount);
    printf("\n\n%d:%ld",id,pathCount);
    return 0;
}