#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100
#define MAX 10

void pecati(int A[MAX][MAX], int n);
int vnesi(int A[MAX][MAX]);

int main()
{
    int A[MAX][MAX], n = vnesi(A);

    pecati(A, n);

    int tmp, i;
    for (i = 0; i < n; i++)
    {
        tmp = A[i][i];
        A[i][i] = A[i][n-1-i];
        A[i][n-1-i] = tmp;
    }

    pecati(A, n);

    return 0;
}

int vnesi(int A[MAX][MAX])
{
    int n;
    printf("Vnesi go n: ");
    scanf("%d", &n);

    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("A[%d,%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    return n;
}

void pecati(int A[MAX][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%5d", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}
