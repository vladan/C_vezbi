#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int vnesi(int A[MAX][MAX], int m, int n);
void pecati(int A[MAX][MAX], int m, int n);
void pecati_elementi(int niza[MAX], int n);

int main ( int argc, char *argv[] )
{
    int i, j, m, n, A[MAX][MAX];
    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);

    vnesi(A, m, n);
    pecati(A, m, n);

    int niza[MAX];

    for(j = 0; j < n; j++)
    {
        niza[j] = A[0][j];
    }

    int k, najden, izbrisani = 0;

    if(m > 1)
    {
        for (i = 1; i < m; i++)
        {
            for(k = 0; k < n - izbrisani; k++)
            {
                najden = 0;
                for(j = 0; j < n; j++)
                {
                    printf("niza[%d]=%d --- A[%d,%d]=%d\n", k, niza[k], i, j, A[i][j]);
                    if(niza[k] == A[i][j])
                    {
                        printf("---go najdov %d\n", niza[k]);
                        najden = 1;
                        break;
                    }
                }
                if (najden == 0)
                {
                    printf("Ne go najdov %d\n", niza[k]);
                    int l;
                    for(l = k; l < n - izbrisani - 1; l++)
                    {
                        niza[l] = niza[l+1];
                    }
                    izbrisani++;
                    k--;
                }
            }
        }
    }
    pecati_elementi(niza, n - izbrisani);

    return EXIT_SUCCESS;
}

void pecati_elementi(int niza[MAX], int n)
{
    int i, j, k, izbrisani = 0;
    for (i = 0; i < n - izbrisani - 1; i++)
    {
        for(j = i + 1; j < n - izbrisani; j++)
        {
            if (niza[i] == niza[j])
            {
                for(k = i; k < n - izbrisani - 1; k++)
                {
                    niza[k] = niza[k+1];
                }
                izbrisani++;
                i--;
            }
        }
    }

    printf("Elementite koi se povtoruvaat vo redicite se: ");
    for(i = 0; i < n-izbrisani; i++)
    {
        printf("%d ", niza[i]);
    }
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
    return 1;
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

