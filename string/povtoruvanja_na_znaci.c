/*
 * Програмата проверува дали должините на два стринга
 * се еднакви и ако се, колку знаци од првиот се исти
 * со знаци од вториот на соодветната позиција.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

int sporedi_stringovi(char *, char *);

int main()
{
    char str[LEN], str2[LEN];
    printf("Vnesete eden string: ");
    gets(str);
    printf("Vnesete drug string: ");
    gets(str2);

    int count = sporedi_stringovi(str, str2);
    if(count >= 0)
        printf("\nDolzinite se ednakvi i im se razlikuvaat %d znaci.", count);
    else
        printf("\nDolzinite ne se ednakvi");

    return 0;
}

int sporedi_stringovi(char *s1, char *s2)
{
    int len1 = 0, len2 = 0;
    while(*(s1 + len1) != '\0')
        len1++;
    while(*(s2 + len2) != '\0')
        len2++;
    printf("len(s1) = %d \nlen(s2) = %d", len1, len2);

    if (len1 == len2)
    {
        int count = 0, i;
        for(i = 0; i < len1; i++)
        {
            if(*(s1 + i) != *(s2 + i))
                count += 1;
        }
        return count;
    }
    return -1;
}
