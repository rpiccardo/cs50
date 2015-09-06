#include <stdio.h>
#include <cs50.h>

/*
 ____      _                                             _
|  _ \ ___| |__   ___  ___ __ _  _  ___     ___ ___   __| | ___
| |_) / _ \  _ \ / _ \/ __/ _  |\/ / __|   / __/ _ \ / _  |/ _ \
|  _ <  __/ |_) |  __/ (_| (_| |   \__ \  | (_| (_) | (_| |  __/
|_| \_\___|_.__/ \___|\___\__,_(   )___/  \___\___/ \__,_|\___|

                          (╯°□°）╯︵ ┻━┻
  */


int main(void)
{
    int height;

    do
    {
        printf("The height is: ");
        height = GetInt();

scanf()

    }
    while (height < 0 || height > 23);

    int row;

    for(row = 1 ; row <= height; row++)
    {
        for(int space = height-row; space > 0; space--)
        {
            printf(" ");
        }

        for(int hash=0; hash <= row; hash++)
        {
             printf("#");
        }
            printf("\n");
      }
        return 0;
}
