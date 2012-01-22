#include <stdio.h>

#define MAX 100

int main() {
    int n,i,j,a[MAX][MAX];
    printf("Vnesete red na kvadratnata matrica: ");
    scanf("%d",&n);
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
            if(!(i%2)&&!(j%2))
            {
                a[i][j]+=2;
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
