#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] )
{
    int n, i, j, izbrisani = 0, a[100];

    printf("Vnesi ja dolzinata: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n - 1 - izbrisani; i++)
    {
        for(j = i + 1; j < n - izbrisani; j++)
        {
            if(a[i] == a[j])
            {
                int pos;
                for(pos = j; pos < n - 2 - izbrisani; pos++)
                {
                    a[pos] = a[pos + 1];
                }
                izbrisani++;
            }
        }
    }

    for(j = 0; j < n - izbrisani - 1; j++)
    {
        printf("%d,", a[j]);
    }
    printf("%d", a[j+1]);

    return EXIT_SUCCESS;
}
