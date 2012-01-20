#include <stdio.h>
#include <stdlib.h>


int faktoriel(int);
int fibonaci(int);
int prost(int, int);
int najdi_sleden_prost_broj(int n);
int suma_neparni(int n, int kolku, int brojac, int zbir);


int main ( int argc, char *argv[] )
{
    int n;

    printf("n = ");
    scanf("%d", &n);

    printf("n! = %d\n", faktoriel(n));
    printf("fibonaci(%d) = %d\n", n, fibonaci(n));
    printf("najbliskiot pogolem prost broj od %d e %d\n", n, najdi_sleden_prost_broj(n));
    printf("Sumata na prostite broevi do %d e: %d\n", n, suma_neparni(1, (n+1)/2, 0, 0));

    return EXIT_SUCCESS;
}


int suma_neparni(int n, int kolku, int brojac, int zbir)
{
    if(brojac == kolku)
    {
        return zbir;
    }
    if(prost(n, 2))
    {
        zbir += n;
    }
    brojac ++;
    return suma_neparni(n + 2, kolku, brojac, zbir);
}



int najdi_sleden_prost_broj(int n)
{
    if (prost(n + 1, 2))
    {
        return n + 1;
    }
    else
    {
        return najdi_sleden_prost_broj(n + 1);
    }
}


int prost(int n, int i)
{
    if (n % i == 0)
    {
        return 0;
    }
    else if (i * i > n)
    {
        return 1;
    }
    else
    {
        return prost(n, i + 1);
    }
}


int faktoriel(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    else
    {
        return n * faktoriel(n - 1);
    }
}

int fibonaci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonaci(n - 1) + fibonaci(n - 2);
    }
}

