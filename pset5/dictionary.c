/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//hashfunction returns index between 
int hashfunction(char* buffer)
{
    int index = tolower(buffer[0]) - 'a';
    
    return index % SIZE;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{   
    //make the word all lowercase and write the word into a buffer
    char buffer[strlen(word) + 1];
    
    for(int i=0, n=strlen(word);i<n;i++)
    {
        buffer[i]= tolower(word[i]);
    }
    
    buffer[strlen(word)] = '\0';
    
    //put the word into hashfunction to get the corresponding index.
    int slot = hashfunction(buffer);
    
    //make a pointer to traverse the linked list at the corresponding index
    node* ptr = hashtable[slot];
    
    //while the pointer hasn't reached the end of the list
    while( ptr != NULL)
    {    
        //search that linked list, comparing each word while set to lowercase
        if(strcmp(ptr -> word, buffer) == 0)
        {
            return true; 
        }
        //else traverse to the next node on the list
        else
        {
            ptr = ptr -> next;
        }
    }
 
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{   
    //open dictionary file to read
    FILE* inptr = fopen(dictionary, "r");
    if(inptr == NULL)
    {   
        printf("Could not open %s.\n", dictionary);
    }
    
    //create buffer
    char buffer[LENGTH + 1];
    
    //initialize counter;
    words = 0;
    
    //make sure the array doesn't have a trash value by setting it to NULL.
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = NULL;
    }
        
    //add a new node for each word in the dictionary
    while (!feof(inptr))
    {
    
        //allocate memory for each node
		node* new_node = malloc(sizeof(node)); 
		
		// store string into a buffer then pass it to the hashfunction
		fscanf(inptr,"%s", buffer);
		
		if(feof(inptr))
		{
		    break;
		}
		
		//Get the index for each word
        int index = hashfunction(buffer);
              
        if(new_node != NULL)
        {
            strcpy (new_node -> word, buffer);
            new_node -> next = NULL;
            words++;
            
            if (hashtable[index] == NULL)
            {
                hashtable[index] = new_node; 
            }
            else
            {   
                new_node -> next = hashtable[index];
                hashtable[index] = new_node;
            } 
         }   
        }
   
   fclose(inptr);
    return true;
}
/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return words;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    //create a pointer and make it point to beginning of hashtable;
    node* ptr = hashtable[0];
   
   //iterate through each index in the array
   
   for(int i = 0; i < SIZE; i++)
   { 
        ptr = hashtable[i];
        
        while(ptr != NULL)
        {
            node* temp = ptr;
            ptr = ptr -> next;
            free(temp);
        }
   }
    
    
    return true;
}
