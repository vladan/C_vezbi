#include <stdio.h>
#include <stdlib.h>


int faktoriel(int);
int faktoriel2(int n, int f);

int main ( int argc, char *argv[] )
{
    int n;

    printf("n = ");
    scanf("%d", &n);

    printf("n! = %d\n", faktoriel2(n, 1));

    return EXIT_SUCCESS;
}

// обичен рекурзивен повик
int faktoriel(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    else
    {
        return n * faktoriel(n - 1);
    }
}

// tail рекурзивен повик
int faktoriel2(int n, int f)
{
    if(n <= 1)
        return f;
    else
        return faktoriel2(n - 1, n * f);
}
