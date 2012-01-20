#include <stdio.h>
#include <stdlib.h>

/*
 * Рекурзивен повик кон фибоначиевата низа
 * (0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...)
 *
 * Не е препорачливо да се пушта за броеви поголеми од 40
 * (на мојот компјутер бар)
 *
 */

int fibonaci(int);

int main ( int argc, char *argv[] )
{
    int n;

    printf("n = ");
    scanf("%d", &n);

    // овој дел го печати само n-от флен
    printf("fibonaci(%d) = %d\n", n, fibonaci(n));


    // овој дел ги печати сите членови до n-от
    int i;
    for (i = 1; i < n; i++)
    {
        printf("%d, ", fibonaci(i));
    }
    printf("%d\n", fibonaci(n));

    return EXIT_SUCCESS;
}

// го враќа членот на соодветната позиција во фибоначиевата низа
int fibonaci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonaci(n - 1) + fibonaci(n - 2);
    }
}

