/*

  ____          _          _   _             ____      _
 / ___|___   __| | ___  __| | | |__  _   _  |  _ \ ___| |__   ___  ___ __ _
| |   / _ \ / _` |/ _ \/ _` | | '_ \| | | | | |_) / _ \ '_ \ / _ \/ __/ _` |
| |__| (_) | (_| |  __/ (_| | | |_) | |_| | |  _ <  __/ |_) |  __/ (_| (_| |
 \____\___/ \__,_|\___|\__,_| |_.__/ \__, | |_| \_\___|_.__/ \___|\___\__,_|
                                      |___/


                (╯°□°）╯︵ ┻━┻   ┻━┻︵ \(°□°)/ ︵ ┻━┻           ¯\_(ツ)_/¯

*/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int convert(char key);
int main(int argc, string argv[])
{
    //if user fails to type in keyword
    if(argc == 1 || argc > 2)
    {
        printf("enter keyword: \n");
        return 1;
    }

    //variables to iterate through keyword
    int i = 0;
    int m = strlen(argv[1]);

    for(i = 0; i < m; i++)
    {
        //if there are numbers in the keyword
        if(isdigit(argv[1][i]))
        {
            printf("enter keyword: \n");
            return 1;
        }
    }

    //prompt user for message to encrypt
    string message = GetString();

    int n = strlen(message);
    string keyword = argv[1];
    m = strlen(keyword);

    int j=0;
    int k=0;

    //iterate every character inside keyword
    for(j = 0; j < m; j++)
    {
       //pass through to convert function
       keyword[j] = convert(keyword[j]);
    }

    for(i = 0, k = 0; i < n; i++)
    {

       if(isalpha(message[i]))
        {
              //if uppercase
              if(isupper(message[i]))
              {
                if(message[i] + keyword[k % m] > 'Z')
                {
                    message[i] = message[i]-'A';
                    printf("%c",(message[i] + keyword[k % m]) % 26 +'A');
                    k++;
                }
                else
                {
                    printf("%c",( message[i] + keyword[k % m]));
                    k++;
                }
              }
              //if lowercase
              if(islower(message[i]))
              {
                 if(message[i] + keyword[k % m] > 'z')
                {
                    message[i] = message[i] -'a';
                    printf("%c",(message[i] + keyword[k % m]) % 26 +'a');
                    k++;
                }
                else
                {
                    printf("%c",(message[i] + keyword[k % m]));
                    k++;
                }
              }
        }
        else
        {
            printf("%c", message[i]);
        }
   }
   printf("\n");
return 0;
}
/*
* set all to lowercase and subtract
* by 'a' to make index 0
*/
int convert(char key)
{
   return tolower(key) -'a';
}
