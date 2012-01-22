#include <stdio.h>

#define MAX 10

int main() {
    int a[MAX][MAX],b[MAX][MAX],i,j,k,m,n;
    int sumared=0,sumakol=0;
    printf("Vnesi dimenzii na matricata: ");
    scanf("%d%d",&m,&n);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("a[%d][%d]= ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<m;i++)
    {
        sumared=0;
        for(k=0;k<n;k++)
        {
            sumared+=a[i][k];
        }
        for(j=0;j<n;j++)
        {
            sumakol=0;
            for(k=0;k<m;k++)
            {
                sumakol+=a[k][j];
            }
            b[i][j]=sumared-sumakol;
        }
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%3d",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
