#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int samoglaska(char c);


int main ( int argc, char *argv[] )
{
    if(argc != 2)
    {
        printf("Greska! Nacin na upotreba ./datoteki ime_na_datoteka");
        return -1;
    }
    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("Gresка! Datotekata ne postoi.");
        return -1;
    }

    char c, tmp;
    int dolzina = 1, count = 0;

    while((c = fgetc(f)) != EOF)
    {
        if(isalpha(c) && samoglaska(c))
        {
            while ((c = fgetc(f)) != EOF && isalpha(c))
            {
                dolzina++;
                tmp = c;
            }
            if(samoglaska(tmp) && dolzina > 10)
            {
                count++;
            }
        }
        else
        {
            while(isalpha(c))
            {
                c = fgetc(f);
            }
        }
    }

    fclose(f);

    printf("Vo datotekata ima %d zborovi.\n", count);

    return EXIT_SUCCESS;
}

int samoglaska(char c)
{
    switch(tolower(c))
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
            break;
        default:
            return 0;
    }
}

