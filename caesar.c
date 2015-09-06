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
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//prototype
void Encrypt(char message, int k);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("please type a positive integer\n");
        return 1;
    }
    else
    {
        string key = argv[1];

        //convert string into an integer
        int k = atoi(key);

        string text = GetString();

    for(int i = 0, n = strlen(text); i < n; i++)
    {
       if(isalpha(text[i]))
        {
            Encrypt(text[i], k);
        }
        else
        {
            printf("%c",text[i]);
        }
     }
        printf("\n");
    return 0;
    }
}

void Encrypt(char message, int k)
{
    if(islower(message))
    {
        if(message + k > 'z')
        {
            message = message - 'a';
            printf("%c",(message + k) % 26 +'a');
        }
        else
        {
            printf("%c",(message + k));
        }
    }
    else if (isupper(message))
    {
        if(message + k > 'Z')
        {
            message = message - 'A';
            printf("%c",(message + k) % 26 + 'A');
        }
        else
        {
            printf("%c",(message + k));
        }
    }
}
