//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: careful
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
    char *str;
    int size = 100;
    int i = 0;
    char c;

    str = (char *)malloc(size * sizeof(char));

    while ((c = getchar()) != '\n')
    {
        if (i == size - 1)
        {
            size *= 2;
            str = (char *)realloc(str, size * sizeof(char));
        }

        str[i] = c;
        i++;
    }

    str[i] = '\0';

    return str;
}

// Function to print the number of words in the string
void printWordCount(char *str)
{
    int count = wordCount(str);
    printf("The number of words in the string is: %d\n", count);
}

// Main function
int main()
{
    char *str;

    printf("Enter a string: ");
    str = readString();

    printWordCount(str);

    free(str);

    return 0;
}