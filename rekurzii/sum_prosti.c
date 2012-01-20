#include <stdio.h>
#include <stdlib.h>


int prost(int n, int i);
int suma_neparni(int n, int kolku, int brojac, int zbir);
int suma_neparni2(int n, int kolku, int zbir);
int suma_prosti(int n, int kolku, int brojac, int zbir);

int main ( int argc, char *argv[] )
{
    int n;

    printf("n = ");
    scanf("%d", &n);

    printf("Sumata na neparnite broevi do %d e: %d\n", n, suma_neparni2(1, (n+1)/2, 0));
    printf("Sumata na prostite neparni broevi do %d e: %d\n", n, suma_prosti(1, (n+1)/2, 0, 0));

    return EXIT_SUCCESS;
}


int suma_neparni(int n, int kolku, int brojac, int zbir)
{
    if(brojac == kolku) // ако бројот на итерации го исполнува внесениот услов
    {
        return zbir;    // тогаш врати го самиот збир
    }
    zbir += n;          // додади го бројот во збирот
    brojac ++;          // инкрементирај го бројачот
    return suma_neparni(n + 2, kolku, brojac, zbir);    // премини на следниот непарен број
}

// малку подобро напишана
int suma_neparni2(int n, int kolku, int zbir)
{
    if(n >= kolku * 2)  // ако бројот на итерации го исполнува внесениот услов
    {
        return zbir;    // тогаш врати го самиот збир
    }
    zbir += n;          // додади го бројот во збирот
    return suma_neparni2(n + 2, kolku, zbir);   // премини на следниот непарен број
}

int suma_prosti(int n, int kolku, int brojac, int zbir)
{
    if(brojac == kolku) // ако бројот на итерации го исполнува внесениот услов
    {
        return zbir;    // тогаш врати го самиот збир
    }
    if(prost(n, 2))     // ако бројот е прост
    {
        zbir += n;      // тогаш додади го на збирот
    }
    brojac ++;      // зголеми го бројачот
    return suma_prosti(n + 2, kolku, brojac, zbir); // премини во следниот циклус
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
