#include <stdio.h>
#include <stdlib.h>

int ispit_1_zadaca();

int main()
{
    ispit_1_zadaca();
    return 0;
}

// Функцијата проверува дали внесуваните броеви се делливи со претходно
// внесениот број од тастатура и ако е деллив печати соодветна порака.
// Внесувањето на нови броеви се прекинува со внесување на буква.
int ispit_1_zadaca()
{
    int a, tmp;
    scanf("%d", &a);
    tmp = a;
    while(scanf("%d", &a))
    {
        if (!(a % tmp))
        {
            printf("Brojot %d e delliv so %d\n", a, tmp);
        }
        tmp = a;
    }
    return 0;
}
