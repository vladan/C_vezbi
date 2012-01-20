#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
 * Програма која ги печати сите прости броеви кои имаат непарни цифри
 * во даден опсег.
 */


int prost(int);
int neparni_cifri(int);

int main ( int argc, char *argv[] )
{
    int m, n, i; // поставување на променливите за опсег и итерирање

    printf("Vnesete dva broja za opsegot: ");
    scanf("%d %d", &m, &n); // читање на вредностите

    for(i = m; i <= n; i++)
    {
        if(prost(i) && neparni_cifri(i)) // провери прво дали бројот е прост па потоа дали цифрите се непарни
        {
            printf("%d\n", i);
        }
    }

    return EXIT_SUCCESS;
}

// проверува дали некој број е прост
// ако бројот е прост враќа 1 во спротивно 0
int prost(int n)
{
    n = abs(n); // земи ја апсолутната вредност на бројот
    if(n < 4)   // позитивните броеви помали од 4 се прости
    {
        return 1;
    }
    int i;
    if (n % 2 == 0) // ако е парен >= 4 не е прост
    {
        return 0;
    }
    else
    {
        for (i = 3; i < sqrt(n); i += 2) // pomini gi site сите непарни броеви до коренот на n
        {
            if (n % i == 0) // ако најдеш делител врати False
            {
                return 0;
            }
        }
    }
    return 1;
}

// функција за проверка на непарните цифри
int neparni_cifri(int n)
{
    while(n) // додека n > 0
    {
        if((n % 10) % 2 == 0)   // ако последната цифра е парна, тогаш врати False
        {
            return 0;
        }
        else
        {
            n /= 10;            // во спротивно исфрли ја последната цифра
        }
    }
    return 1;   // ако стигнеш до 0, тогаш врати True
}
