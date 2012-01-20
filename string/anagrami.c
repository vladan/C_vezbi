#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int anagram(char *str1, char *str2);
void isfrli_prazni_mesta(char *str);
void isfrli(char *str, int pos);
void isfrli_2_pati(char *str, char c);


int main ( int argc, char *argv[] )
{
    char str1[MAX], str2[MAX];

    printf("Vnesete go prviot string: ");
    gets(str1);
    printf("Vnesete go vtoriot string: ");
    gets(str2);

    if(anagram(str1, str2))
    {
        printf("Stringovite se anagrami\n");
    }
    else
    {
        printf("Stringovite ne se anagrami\n");
    }


    return EXIT_SUCCESS;
}


int anagram(char *str1, char *str2)
{
    isfrli_prazni_mesta(str1);
    isfrli_prazni_mesta(str2);

    int pos = 0, pos2 = 0;
    char c1, c2;

    if(strlen(str1) != strlen(str2))
    {
        return 0;
    }

    strcat(str1, str2);

    while((c1 = *(str1 + pos)) != '\0')
    {
        pos2 = pos + 1;
        while((c2 = *(str1 + pos2)) != '\0')
        {
            if(tolower(c1) == tolower(c2))
            {
                isfrli(str1, pos);
                isfrli(str1, pos2);
                break;
            }
            pos2++;
        }
        pos++;
    }
    return 1;
}

void isfrli(char *str, int pos)
{
    while(*(str + pos) != '\0')
    {
        *(str + pos) = *(str + pos + 1);
        pos ++;
    }
}

void isfrli_prazni_mesta(char *str)
{
    int i;
    char c1;
    for(i = 0; (c1 = *(str + i)) != '\0'; i++)
    {
        if(c1 == ' ')
        {
            isfrli(str, i);
        }
    }
}
