/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

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
#include <stdint.h>

int main(void)
{
    //create buffer
    unsigned char buffer[512];

    //count of jpgs found
    int count = 0;

    //make title of files
    char filename[8];

    //declare img pointer
    FILE* outptr = NULL;

    //open card file
    FILE* inptr = fopen("card.raw", "r");

    if (inptr == NULL)
    {
        printf("could not open card.raw\n");
        return 1;
    }

    //as long as there are blocks of 512 bytes to read
    while((fread(buffer, 512, 1, inptr)) != 0)
    {

            if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
            {

                if(count != 0)
                {
                    //close previous jpg
                    fclose(outptr);
                    }


                    //name file
                    sprintf(filename, "%.3d.jpg", (count));cd

                    //open new file
                    outptr = fopen(filename, "w");

                    if(outptr == NULL)
                    {
                        return 1;
                    }

                       count++;

           }

           if(outptr != NULL)
           {
            fwrite(buffer, 512, 1, outptr);
           }

    }
        fclose(inptr);
        fclose(outptr);

 return 0;
}
