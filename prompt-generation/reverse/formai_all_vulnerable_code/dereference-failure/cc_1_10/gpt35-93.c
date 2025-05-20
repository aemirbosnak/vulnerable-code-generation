//FormAI DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function declaration
char *compress(char *);

//Main function
int main()
{
    char input_string[1000], *compressed_string;

    printf("Enter a string to compress: ");
    fgets(input_string, 1000, stdin);

    compressed_string = compress(input_string);

    printf("Compressed string: %s\n", compressed_string);

    free(compressed_string);

    return 0;
}

//Function to compress a given string
char *compress(char *input)
{
    //Initializing variables
    int count = 1, index = 0, i;
    char temp[1000];

    //Loop through each character in the input string
    for(i = 0; i < strlen(input); i++)
    {
        if(input[i] == input[i+1])
        {
            //If the character repeats, increment the count
            count++;
        }
        else
        {
            //If the character does not repeat, add it to the output string
            temp[index] = input[i];
            index++;

            //If the count of the previous character is greater than 1, add it to the output string
            if(count > 1)
            {
                char countChar[100];
                sprintf(countChar, "%d", count);
                strcat(temp, countChar);
                index += strlen(countChar);
                count = 1;
            }
        }
    }

    //Terminate the compressed string with a null character
    temp[index] = '\0';

    //Allocate space in memory for the compressed string
    char *compressed = malloc(sizeof(char) * (strlen(temp) + 1));

    //Copy the compressed string into the allocated memory
    strcpy(compressed, temp);

    //Return the compressed string
    return compressed;
}