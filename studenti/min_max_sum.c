#include <stdio.h>
#define MAX 10

int main() {
    int i,j,m,n,a[MAX][MAX],maxKol=0,minKol=0,tmp,max=0,min=0,suma;
    printf("Vnesete go brojot na redici: ");
    scanf("%d",&m);
    printf("Vnesete go brojot na koloni: ");
    scanf("%d",&n);
    printf("Vnesete gi elementite na matricata:\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("a[%d][%d]= ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    printf("\n\n Ja vnesovte matricata:\n\n\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<m; i++)
    {
        min+=a[i][0];
        max+=a[i][0];
    }
    for(j=0; j<n; j++)
    {
        suma=0;
        for(i=0; i<m; i++)
        {
            suma+=a[i][j];
        }
        if(suma<min)
        {
            min=suma;
            minKol=j;
        }
        if(suma>max)
        {
            max=suma;
            maxKol=j;
        }
    }

    for(i=0; i<m; i++)
    {
        tmp=a[i][maxKol];
        a[i][maxKol]=a[i][minKol];
        a[i][minKol]=tmp;
    }
    printf("\nNovodobienata matrica e: \n\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
