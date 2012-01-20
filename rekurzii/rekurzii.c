#include <stdio.h>
#include <stdlib.h>


int prost(int, int);
int najdi_sleden_prost_broj(int n);

int main ( int argc, char *argv[] )
{
    int n;

    printf("n = ");
    scanf("%d", &n);

    printf("najbliskiot pogolem prost broj od %d e %d\n", n, najdi_sleden_prost_broj(n));

    return EXIT_SUCCESS;
}

// функција која го наоѓа следниот поголем прост број од внесениот
int najdi_sleden_prost_broj(int n)
{
    if (prost(n + 1, 2)) // ако следниот број е прост, врати го
    {
        return n + 1;
    }
    else
    {
        // ако не, зголеми го за еден и пробај повторно
        // сѐ додека не наидеш на прост број
        return najdi_sleden_prost_broj(n + 1);
    }
}

// функција која рекурзивно проверува дали некој броје прост
int prost(int n, int i)
{
    if (n % i == 0) // ако е деллив со i тогаш е прост (има делители различни од 1)
    {
        return 0;
    }
    else if (i * i > n) // ако сме стигнале до коренот на бројот
    {
        return 1;       // тогаш бројот е прост и врати True
    }
    else
    {
        return prost(n, i + 1); // во спротивно зголемувај го i зa 1
    }
}
