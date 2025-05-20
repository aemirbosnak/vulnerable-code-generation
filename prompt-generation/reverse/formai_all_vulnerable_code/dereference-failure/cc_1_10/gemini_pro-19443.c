//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int wordCount(char *str)
{
    int count = 0;
    int i = 0;
    int inWord = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            inWord = 0;
        }
        else if (!inWord)
        {
            inWord = 1;
            count++;
        }

        i++;
    }

    return count;
}

// Function to read a string from the user
char *readString()
{
    char *str = NULL;
    int size = 0;

    printf("Enter a string: ");
    getline(&str, &size, stdin);

    return str;
}

// Main function
int main()
{
    char *str;

    // Read a string from the user
    str = readString();

    // Count the number of words in the string
    int count = wordCount(str);

    // Print the number of words in the string
    printf("The number of words in the string is: %d\n", count);

    // Free the memory allocated for the string
    free(str);

    return 0;
}