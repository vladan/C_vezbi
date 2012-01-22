#include <stdio.h>

#define MAX 100

int main()
{
    int i,j,m,a[MAX][MAX];
    printf("Od koj red e matricata\n");
    scanf("%d",&m);
    printf("Vnesi ja matricata\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int suma=0;
    for(i=0;i<=m-1;i++)
    {
        for(j=0;j<=m-1;j++)
        {
            if((i%2 && j%2) || (!(i%2)&&!(j%2)))
                suma+=a[i][j];
        }
    }
    printf("suma=%d\n",suma);


    for(i=0;i<=m-1;i++)
    {
        for(j=0; j <= m-1; j++)
        {
            if(i+j == m-1)
            {
                a[i][j]=suma;
            }
        }
    }
    for(i=0;i<=m-1;i++)
    {
        for(j=0;j<=m-1;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
