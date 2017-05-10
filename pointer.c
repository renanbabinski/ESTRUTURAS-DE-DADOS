#include <stdio.h>

int main()
{

    int c = 1;
    int d = 2;
    int e = 3;
    int * a = &c;
    int * b = &d;
    int * f = &e;
    int ** pp = &a; 

    printf("\n A value: %p \n", a);
    printf("\n B value: %p \n", b);
    printf("\n F value: %p \n", f);
    
    a = b;
    printf("\n A = B : %p, \n", a);
    cant_change(a, f);
    printf("\n cant_change(a, f): %p \n", a);
    change(pp, f);
    printf("\n change(pp, f): %p\n", a);
    return 0;
}

void cant_change(int * x, int * z){
    x = z;
    printf("\n Swap cant_change: %p \n", x);
}

void change(int ** x, int * z){
    *x = z;
    printf("\n Change: %p \n", *x);
}