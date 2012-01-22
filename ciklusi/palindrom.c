#include <stdio.h>
#include <stdlib.h>

int palindrom(int);

int main()
{
    int n;

    printf("Vnesete go brojot za proverka: ");
    scanf("%d", &n);
    if(palindrom(n))
    {
        printf("Brojot e palindrom");
    }
    else
    {
        printf("Brojot ne e palindrom");
    }
    return 0;
    return 0;
}

int palindrom(int n)
{
    int a = n, c = 0;
    while (a > 0)
    {
        c = c * 10 + a % 10;
        a = a / 10;
    }
    return n == c;
}
