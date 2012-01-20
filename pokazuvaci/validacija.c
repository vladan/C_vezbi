#include <stdio.h>
#include <ctype.h>

/*
 * Програма која проверува дали внесен стринг е валиден телефонски број.
 * формат на валиден број: 389-71-333444
 *
 */

int proveri(char *broj);

int main(int argc, char* argv[])
{
    char broj[20];
    printf("Vnesete go brojot: ");
    gets(broj);

    printf("Nizata e: %s\n", broj);

    if(proveri(broj))
        printf("Brojot e validen!\n");
    else
        printf("Brojot ne e validen!\n");
    return 0;
}

int proveri(char *broj)
{
    int count = 0;  // бројач
    char c;         // привремен знак
    printf("Nizata e: %s\n", broj); // проверка

    while((c = *(broj + count)) != '\0') // се додека не стигнеме до крајот на стрингот
    {
        if ((count == 3 || count == 6) && c != '-') // провери дали 3от и 6от знак се „-“
        {
            printf("Tuka - %d - treba da ima crtka!", count);   // проверка
            return 0;                                           // ако не се „-“ излези со False
        }
        else if ((count != 3 && count != 6) && !isdigit(c))     // ако позицијата е различна од 3 и 6 и знакот не е број
        {
            printf("Tuka - %d - treba da ima brojka!\n", count);// проверка
            printf("Tuka ima %c !\n", count);                   // проверка
            return 0;                                           // ако знакот не е број, тогаш излези со False
        }
        else
        {
            count++;    // во спротивно зголеми го бројачот
        }
    }
    if(count != 13)     // aко стрингот има помалку или повеќе од 13 знаци, врати False
    {
        printf("count = %d", count);
        return 0;
    }
    return 1;   // ако сѐ помине во ред, врати True
}
