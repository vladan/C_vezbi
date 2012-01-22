#include <stdio.h>
#include <stdlib.h>

#define MAX 100


void pecati(int A[MAX][MAX], int, int);
int vnesi(int A[MAX][MAX], int, int);
int sortiraj(int A[MAX][MAX], int, int, int Index[MAX*MAX][2]);

int main ( int argc, char *argv[] )
{
    int A[MAX][MAX], m, n, Index[MAX*MAX][2];
    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);

    vnesi(A, m, n);
    pecati(A, m, n);

    Index[MAX*MAX][2] = sortiraj(A, m, n, Index);

    int i;
    for(i = 0; i < m*n; i++)
    {
        printf("A[%d][%d] = %d\n", Index[i][0], Index[i][1], A[Index[i][0]][Index[i][1]]);
    }

    return EXIT_SUCCESS;
}


int sortiraj(int A[MAX][MAX], int m, int n, int Index[MAX*MAX][2])
{
    int i, j, broj_na_indeksi = 0, k;

    Index[0][0] = 0;
    Index[0][1] = 0;

    for (i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if (broj_na_indeksi > 0)
            {
                int l = 0;
                while (l < broj_na_indeksi && A[i][j] <= A[Index[l][0]][Index[l][1]])
                {
                    l++;
                }
                for(k = broj_na_indeksi; k > l; k--)
                {
                    Index[k][0] = Index[k-1][0];
                    Index[k][1] = Index[k-1][1];
                }
                Index[l][0] = i;
                Index[l][1] = j;
            }
            broj_na_indeksi++;
        }
    }

    return Index[MAX*MAX][2];
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
