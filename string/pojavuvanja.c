/*
 * Програмата проверува колку пати два внесени
 * знака се појавуваат еден до друг во внесен стринг,
 * без разлика на редоследот на знаците во стрингот.
 *
 */

#include <stdio.h>
#include <stdlib.h>


int broj_na_povtoruvanja(char *str, char c1, char c2);

int main ( int argc, char *argv[] )
{
    char str[100], c1, c2;

    printf("Vnesete go satringot: ");
    gets(str);

    printf("Vnesete gi znacite: ");
    scanf("%c %c", &c1, &c2);

    int count = broj_na_povtoruvanja(str, c1, c2);
    printf("\n\n\nBrojot na povtoruvanja na znacite zalepeni eden do drug se: %d", count);

    return EXIT_SUCCESS;
}

int broj_na_povtoruvanja(char *str, char c1, char c2)
{
    int count = 0, pos = 0;
    char c;

    while((c = *(str + pos)) != '\0')
    {
        if(c == c1)
        {
            if (*(str + pos + 1) == c2)
            {
                count++;
            }
        }
        else if (c == c2)
        {
            if (*(str + pos + 1) == c1)
            {
                count++;
            }
        }
        pos++;
    }
    return count;
}
