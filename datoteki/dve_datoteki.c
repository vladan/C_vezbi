/*
 * Програмата зема две датотеки како влезни аргументи при повикот,
 * сите мали букви од првата ги запишува како големи во втората,
 * големите букви од првата ги запишува како мали во втората,
 * а другите знаци ги остава исти.
 *
 * Доколку втората датотека не постои, тогаш таа се креира.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void zapisi(FILE *f, FILE *f2);

int main ( int argc, char *argv[] )
{
    if(argc != 3)
    {
        printf("Greska! Nacin na koristenje: znaci_vo_red test.txt zapisan.txt\n\n");
        exit(-1);
    }

    FILE *f;
    if((f = fopen(argv[1], "r")) == NULL)
    {
        printf("Greska! Datotekata ne moze da se otvori.\n\n");
        exit(-1);
    }

    FILE *f2;
    if((f2 = fopen(argv[2], "w")) == NULL)
    {
        printf("Greska! Datotekata ne moze da se otvori.\n\n");
        exit(-1);
    }

    zapisi(f, f2);

    fclose(f);
    fclose(f2);

    return 0;
}

void zapisi(FILE *f, FILE *f2)
{
    char c;
    while((c = fgetc(f)) != EOF)
    {
        if(isalpha(c))
        {
            if (isupper(c))
            {
                c = tolower(c);
            }
            else
            {
                c = toupper(c);
            }
        }
        fputc(c, f2);
    }
}
