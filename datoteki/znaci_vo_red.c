#include <stdio.h>
#include <stdlib.h>

void proveri_linii(FILE *f);

int main ( int argc, char *argv[] )
{
    if(argc != 2)
    {
        printf("Greska! Nacin na koristenje: znaci_vo_red test.txt\n\n");
        exit(-1);
    }

    FILE *f;
    if((f = fopen(argv[1], "r")) == NULL)
    {
        printf("Greska! Datotekata ne moze da se otvori.\n\n");
        exit(-1);
    }

    proveri_linii(f);

    fclose(f);

    return 0;
}

void proveri_linii(FILE *f)
{
    int linija = 1, brojac = 1;
    char c;

    while((c = fgetc(f)) != EOF)
    {
        while((c = fgetc(f)) != '\n')
        {
            brojac++;
        }
        if (brojac > 20)
        {
            printf("Najdov poveke od 20 znaci na %d linija.\n", linija);
        }
        brojac = 1;
        linija ++;
    }
}
