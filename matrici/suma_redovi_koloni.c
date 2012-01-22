/*
 * Програмата зема матрица на влез и го заменува секој елемент
 * со разликата од сумата на елементите од колоната и
 * сумата на елементите од редицата во кои се наоѓа тој елемент 
 *
 * Функцијата прво ги пресметува сумите и ги зачувува во посебни низи,
 * а потоа ја пресметува нивната разлика и ја зачувува во елементите соодветно.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100


void pecati(int A[MAX][MAX], int, int);
int vnesi(int A[MAX][MAX], int, int);
int presmetaj(int A[MAX][MAX], int m, int n);

int main ( int argc, char *argv[] )
{
    int A[MAX][MAX], m, n;

    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);

    vnesi(A, m, n);
    pecati(A, m, n);

    A[MAX][MAX] = presmetaj(A, m, n);

    pecati(A, m, n);

    return EXIT_SUCCESS;
}


int vnesi(int A[MAX][MAX], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("A[%d,%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    return n;
}

void pecati(int A[MAX][MAX], int m, int n)
{
    int i, j;

    printf("\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%5d", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int presmetaj(int A[MAX][MAX], int m, int n)
{
    int suma_redici[MAX], suma_koloni[MAX], i, j;

    // пресметaj ги сумите на секоја редица посебно
    for(i = 0; i < m; i++)
    {
        suma_redici[i] = 0;
        for(j = 0; j < n; j++)
        {
            suma_redici[i] += A[i][j];
        }
    }

    // пресметaj ги сумите на секоја колона посебно
    for(j = 0; j < n; j++)
    {
        suma_koloni[j] = 0;
        for(i = 0; i < m; i++)
        {
            suma_koloni[j] += A[i][j];
        }
    }

    // внеси ја нивната разлика во матрицата
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            A[i][j] = suma_redici[i] - suma_koloni[j];
        }
    }

    return A[MAX][MAX];
}

