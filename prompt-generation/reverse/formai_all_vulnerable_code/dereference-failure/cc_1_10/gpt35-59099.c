//FormAI DATASET v1.0 Category: Compression algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000  // Maximum length of the input string

// Function to compress the input string using a unique algorithm
char *compress(char *input) 
{
    char *compressed = (char *) malloc(strlen(input) * sizeof(char));
    int i = 0, j = 0;
    
    while (*(input + i) != '\0') 
    {
        int count = 1;
        *(compressed + j) = *(input + i);
        while (*(input + i) == *(input + i + 1)) 
        {
            count++;
            i++;
        }
        if (count > 1) 
        {
            *(compressed + j + 1) = '0' + count;
            j++;
        }
        i++;
        j++;
    }
    *(compressed + j) = '\0';
    return compressed;
}

int main() 
{
    printf("Welcome to the happy world of C Compression Algorithm Program!\n");
    printf("Let's compress a string of characters and see the magic happen!\n\n");
    
    char input[MAX_LENGTH], *compressed;
    printf("Enter a string of characters to compress (maximum length is %d): ", MAX_LENGTH);
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';  // Removing the newline character from input
    
    if (strlen(input) > 0) 
    {
        printf("\nLet's compress the string...\n");
        compressed = compress(input);
        printf("Original string: %s\n", input);
        printf("Compressed string: %s\n", compressed);
        free(compressed);
    } 
    else 
    {
        printf("Oops! The input string is empty. Please try again!\n");
    }
    
    printf("\nThank you for using our C Compression Algorithm Program. Have a happy day ahead!\n");
    return 0;
}