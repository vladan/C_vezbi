#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int cmp();
int otsecka();
int prva_zadaca();
float niza_proizvod();

/*
 * Овде се извршува сѐ, a се повикуваат надворешни функции.
 * За вежба може да ги повикувате функциите во main() и да ги
 * прегледувате резултатите што ќе ги дадат.
 *
 */
int main()
{
    float p = niza_proizvod();
    printf("Proizvodot e %f", p);

    return 0;
}

int faktoriel(int num)
{
    int i, f = 1;
    for (i = num; i >= 1; i--)
    {
        f = f * i;
    }
    num = 5;
    return f;
}

float niza_proizvod() {
    int m, n;
    printf("Внесете ги броевите:");
    scanf("%d %d", &m, &n);

    float proizvod = 1;
    int i;
    for (i = 1; i <= n; i++)
    {
        proizvod = proizvod * ( (float)faktoriel(i) / m );
    }
    return proizvod;
}

int prva_zadaca()
{
    int a, b, c;
    printf("Внесете ги броевите:");     // ова принта и ништо не прави
    scanf("%d %d %d", &a, &b, &c);      // тука се внесуваат вредностите во променливите

    // ЗБИР
    printf("a + b + c = %d\n", a+b+c);  // тука се принта збирот на сите внесени променливи
                                        // кој се извршува директно во printf функцијата
    int zbir = a+b+c; // внесување на збирот во посебна променлива
    printf("a + b + c = zbir = %d\n", zbir); // принтање на променливата која го содржи збирот

    // РАЗЛИКА
    printf("a - b - c = %d\n", a-b-c);  // тука се принта разликата на сите внесени променливa
    int razlika = a - b - c; // внесување на разликата во посебна променлива
    printf("a - b - c = razlika = %d\n", razlika); // принтање на променливата која ја содржи разликата

    // ПРОИЗВОД
    printf("a * b * c = %d\n", a*b*c);

    return 0;
}

int otsecka()
{
    int x1, x2, y1, y2;
    printf("Внеси ги координатите на првата точка: ");
    scanf("%d %d", &x1, &y1);
    printf("Внеси ги координатите на втората точка: ");
    scanf("%d %d", &x2, &y2);

    if (x1 == x2 && y1 == y2)
        printf("Станува збор за точка, не за отсечка!");
    else if (x1 == x2)
        printf("Отсечката е паралелна со Y-оската и е оддалечена за %d!", x1);
    else if (y1 == y2)
        printf("Отсечката е паралелна со X-оската и е оддалечена за %d!", y1);
    else
        printf("Квадратот на должината на отсечката е %f!", pow(x1-x2, 2) + pow(y1-y2, 2));

    return 0;
}

int cmp()
{
    int a, b;
    char c;
    printf("Vnesi dva celi broja: "); scanf("%d %d", &a, &b);
    if(a/b)
        if(a-b) c='>';
        else c='=';
    else c='<';
    printf("%d %c %d\n", a, c, b);
    return 0;
}
