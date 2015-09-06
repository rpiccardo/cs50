/*
 ____      _                                             _
|  _ \ ___| |__   ___  ___ __ _  _  ___     ___ ___   __| | ___
| |_) / _ \  _ \ / _ \/ __/ _  |\/ / __|   / __/ _ \ / _  |/ _ \
|  _ <  __/ |_) |  __/ (_| (_| |   \__ \  | (_| (_) | (_| |  __/
|_| \_\___|_.__/ \___|\___\__,_(   )___/  \___\___/ \__,_|\___|

                          (╯°□°）╯︵ ┻━┻
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name;
    
    do
    {
        name = GetString();
    }
    while(name == NULL);


    int length = strlen(name);

    printf("%c",toupper(name[0]));
    for(int i = 0; i < length; i++)
    {
        if(isspace(name[i]))
            {
            printf("%c",toupper(name[i + 1]));
            }
    }
    printf("\n");
}
