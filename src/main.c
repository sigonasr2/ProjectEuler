#include <stdio.h>
#include "utils.h"

/*
    

    https://projecteuler.net/problem=
*/

int main(int argc,char**argv) {
    printf("%s",add((struct String){7,"1845920"},(struct String){4,"1829"}).str);
    return 0;
}