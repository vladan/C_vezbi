#include <stdio.h>
#define MAX 10

int main() {
    int n,i,j,tmp,a[MAX][MAX];

    printf("Vnesete red na kvadratnata matrica: ");
    scanf("%d",&n);

    //vnesi matrica
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    //pecati matrica
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    //smena na dijagonalite
    for(i=0;i<n;i++)
    {
        tmp=a[i][i];
        a[i][i]=a[i][n-1-i];
        a[i][n-1-i]=tmp;
    }
    printf("\n\n");

    //pecati ja smenetata matrica
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
