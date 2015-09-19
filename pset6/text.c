#include <stdio.h>
#include <cs50.h>
#include <string.h>

const char* lookup(const char* extension);

int main(void)
{
    const char* extension = "GET /cat.html";
    
   const char*  type = lookup(extension);
   
   printf("%s", type);
    
}

const char* lookup(const char* extension)
{

    if(extension != NULL)
    {

        if((strcmp(extension, "html") || strcmp(extension, "HTML")) == 0)
        {
        return "text/html";
        }
    }
    
    return NULL;
}

