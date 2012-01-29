/*
 * Задачата гласи: Да се најдат сите елементи кои се
 * повторуват во редиците на една матрица и да се
 * испечатат на екранот.
 *
 * Најпрво се зема првата редица и се става во низа.
 * Потоа низата се проверува со секоја следна редица
 * и ако некој елемент од низата не е најден во
 * следната редица, тогаш тој се отстранува од низата.
 * Овој чекор се повторува сѐ додека не се стигне до
 * последната редица во матрицата и додека има елементи
 * во помошната низа. Доколку нема елементи се прекинува
 * и се печати соодветната порака.
 *
 */

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
    // внеси го секој елемент од првата редица во помошна низа
    for(j = 0; j < n; j++)
    {
        niza[j] = A[0][j];
    }

    int k, najden, izbrisani = 0;

    if(m > 1)
    {
        for (i = 1; i < m; i++)
        {
            // за секоја редица провери дали секој елемент од низата
            // се наоѓа во тековната редица
            for(k = 0; k < n - izbrisani; k++)
            {
                najden = 0;
                for(j = 0; j < n; j++)
                {
                    printf("niza[%d]=%d --- A[%d,%d]=%d\n", k, niza[k], i, j, A[i][j]);
                    if(niza[k] == A[i][j])
                    {
                        // ако елементот постои во редицата означи дека е најден
                        // и прекини го циклусот
                        printf("---go najdov %d\n", niza[k]);
                        najden = 1;
                        break;
                    }
                }
                if (najden == 0)
                {
                    // ако елементот не е најден, тогаш отстрани го од помошната низа
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
            // провери дали воопшто има елементи во помошната низа
            // ако нема, тогаш може да се престане со проверките
            if (n == izbrisani)
            {
                break;
            }
        }
    }
    pecati_elementi(niza, n - izbrisani);

    return EXIT_SUCCESS;
}

void pecati_elementi(int niza[MAX], int n)
{
    if (n > 0)
    {
        // отстрани ги дупликатите
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

        // испечати ги елементите кои се повторуваат
        printf("Elementite koi se povtoruvaat vo redicite se: ");
        for(i = 0; i < n-izbrisani; i++)
        {
            printf("%d ", niza[i]);
        }
    }
    else
    {
        printf("Nema elementi koi se povtoruvaat vo redicite.");
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

