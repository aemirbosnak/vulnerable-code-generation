//FormAI DATASET v1.0 Category: Compression algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//compression function to compress a string
char *compress(char *string)
{
    //create new string to store compressed version of original string
    char *compressed_string = (char*)malloc(2 * strlen(string) + 1);
    
    //initialize variables for compression process
    int count = 1;
    char current_char = string[0];
    int index = 0;
    
    //iterate through all characters in original string
    for(int i = 1; i <= strlen(string); i++)
    {
        //if next character is the same as current character, increment count
        if(string[i] == current_char)
        {
            count++;
        }
        else
        {
            //if next character is different than current character, compress current character
            compressed_string[index++] = current_char;
            char count_char[10];
            sprintf(count_char, "%d", count);
            strcat(compressed_string, count_char);
            index += strlen(count_char);
            count = 1;
            current_char = string[i];
        }
    }
    
    //if original string was not compressible, return original string
    if(strlen(compressed_string) >= strlen(string))
    {
        return string;
    }
    
    //return compressed string
    return compressed_string;
}

int main()
{
    //test compression function
    char string[] = "aabcccccaaa";
    char *compressed_string = compress(string);
    printf("Original string: %s\n", string);
    printf("Compressed string: %s\n", compressed_string);
    free(compressed_string);
    return 0;
}