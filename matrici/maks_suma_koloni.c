/*
 * Da se napise programa vo koja od tastatura se vnesaat elementi (celobrojni vrednosti)
 * na matricata so dimenzijata mxn(ne pogolemi od 100). Potrebno e da se napravi promena
 * na matricata taka sto maksimalniot element ke ja dobie vrednosta na sumata na ostanatite
 * elementi vo taa kolona.
 *
 * Програмата ја пресметува сумата само на колоната во која се наоѓа максималниот елемент
 * во целата матрица, и не го зема максималниот елемент во сумата.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include<stdio.h>
int main()
{
    int a[100][100],i,j,m,n,max,k,r,suma=0;
    printf("Vnesi gi dimenziite na matricata: ");
    scanf("%d %d",&n,&m);
    printf("Vnesi ja matricata: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("a[%d][%d]= ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nMatricata e: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("  %d",a[i][j]);
        printf("\n");
    }

    max=a[0][0];
    k=0;
    r=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]>max)
            {
                max=a[i][j];
                r=i;
                k=j;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(i != r)
        {
            suma+=a[i][k];
        }
    }

    printf("Sumata e: %d", suma);

    return 0;
}
