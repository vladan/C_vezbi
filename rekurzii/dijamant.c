#include <stdio.h>
#include <stdlib.h>


void pecati_dijamant(int, int);
void pecati(int n, int m);

int main ( int argc, char *argv[] )
{
    int n;

    printf("n = ");
    scanf("%d", &n);

    pecati_dijamant(n, 1);
    return EXIT_SUCCESS;
}

void pecati_dijamant(int n, int i)
{
    if(n > i)
    {
        pecati(n-i, 2*i-1);
        pecati_dijamant(n, i + 1);
        pecati(n-i, 2*i-1);
    }
    else
    {
        pecati(n-i, 2*i-1);
    }
}

// за дома да го решите ова рекурзивно
void pecati(int n, int m)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        printf(" ");
    }
    for(i = 1; i <= m; i++)
    {
        printf("*");
    }
    printf("\n");
}
