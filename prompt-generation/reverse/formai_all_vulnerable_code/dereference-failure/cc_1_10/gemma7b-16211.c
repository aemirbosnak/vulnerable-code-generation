//Gemma-7B DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main()
{
    // Allocate memory for a string
    char *str = malloc(MAX_SIZE);

    // Get the string from the user
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    // Remove the newline character from the end of the string
    str[strcspn(str, "\n")] = '\0';

    // Split the string into words
    char **words = NULL;
    int num_words = word_split(str, &words);

    // Print the words
    for (int i = 0; i < num_words; i++)
    {
        printf("%s ", words[i]);
    }

    // Free the memory allocated for the string and words
    free(str);
    free(words);

    return 0;
}

int word_split(char *str, char ***words)
{
    // Calculate the number of words in the string
    int num_words = count_words(str);

    // Allocate memory for the words
    *words = malloc(num_words * sizeof(char *));

    // Split the string into words
    char **word_ptr = *words;
    char *ptr = str;
    while (ptr)
    {
        word_ptr[0] = ptr;
        ptr = strchr(ptr, ' ') ? strchr(ptr, ' ') : NULL;
        word_ptr++;
    }

    return num_words;
}

int count_words(char *str)
{
    int num_words = 0;
    char *ptr = str;
    while (ptr)
    {
        if (isspace(ptr[0]) || ptr[0] == '\0')
        {
            num_words++;
        }
        ptr++;
    }
    return num_words;
}