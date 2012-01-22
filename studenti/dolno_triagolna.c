#include <stdio.h>

#define MAX 10

int main() {
    int n,i,j,a[MAX][MAX],suma=0;
    printf("Vnesete red na kvadratnata matrica: ");
    scanf("%d",&n);
    printf("Vnesete gi elementite na matricata: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            suma+=a[i][j];
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>j)
            {
                a[i][j]=suma;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
