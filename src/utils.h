#define true 1
#define false 0
#define boolean char
#define byte char
struct String{
    int length;
    char*str;
};
struct String add(struct String numb1, struct String numb2);
void printLongDoubleArr(int a,int b,long doubleArr[a][b]);
void printIntDoubleArr(int a,int b,int doubleArr[a][b]);