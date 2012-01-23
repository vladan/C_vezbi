/*
 * Програмот ги сортира елементите од матрицата по опаѓачки редослед
 * и ги печати елементите заедно со нивните индекси.
 *
 */

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

    // постави ги индексите на првиот елемент (0,0) од матрицата
    // како максимален елемент во првиот ред од индекс матрицата,
    // потоа ако најдеш некој поголем од него помести ги сите редици надоле,
    // а индексите на новиот максимален елемент стави ги во првата редица
    Index[0][0] = 0;
    Index[0][1] = 0;

    for (i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            // broj_na_indeksi го чуваме за да провериме до каде да одиме во индекс матрицата
            // и да ја прескокнеме иницијализацијата на индекс матрицата (Index)
            if (broj_na_indeksi > 0)
            {
                int l = 0; // почнуваме од 0 да бараме во која
                           // редица од Index да ги сместиме индексите на новиот елемент
                while (l < broj_na_indeksi && A[i][j] <= A[Index[l][0]][Index[l][1]])
                {
                    // додека редицата е помала од бројот на внесени редици во Index матрицата
                    // и додека новиот елемент од матрицата е помал од елементот во тековната редица
                    l++; // спушти го елементот подоле во Index матрицата
                }
                for(k = broj_na_indeksi; k > l; k--)
                {
                    // помести ги сите редици надоле за да се направи простор за новиот член од матрицата
                    Index[k][0] = Index[k-1][0];
                    Index[k][1] = Index[k-1][1];
                }
                // внеси го новиот елемент во l-от ред од Index матрицата
                Index[l][0] = i;
                Index[l][1] = j;
            }
            broj_na_indeksi++; // зголени го бројот на внесени редици во Index матрицата
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
