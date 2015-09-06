/*
 ____      _                                             _
|  _ \ ___| |__   ___  ___ __ _  _  ___     ___ ___   __| | ___
| |_) / _ \  _ \ / _ \/ __/ _  |\/ / __|   / __/ _ \ / _  |/ _ \
|  _ <  __/ |_) |  __/ (_| (_| |   \__ \  | (_| (_) | (_| |  __/
|_| \_\___|_.__/ \___|\___\__,_(   )___/  \___\___/ \__,_|\___|

                          (╯°□°）╯︵ ┻━┻

Greedy.c is a program that will output the smallest number of coins
needed to give back the change the user asked for.

*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        printf("How much change do I owe you? ");
        change = GetFloat();
    }
    while (change <= 0);

    int num = round(change * 100);
    int q = 25;
    int d = 10;
    int n = 5;
    int p = 1;
    int count = 0;

    while(num >= q)
        {
            num = num - q;
            count++;
        }

    while(num >= d)
        {
            num = num - d;
            count++;
         }

    while(num >= n)
        {
            num = num - n;
            count++;
         }

    while(num >= p)
        {
            num = num - p;
            count++;
         }

     printf("%i\n",count);

return 0;

}
