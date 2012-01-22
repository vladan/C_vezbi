#include <stdio.h>

#define MAX 100

int main() {
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
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(j<i && j+i>=m)
            {
                printf("a[%d][%d]=%d\t",i,j,a[i][j]);
            }
        }
    }
    return 0;
}
