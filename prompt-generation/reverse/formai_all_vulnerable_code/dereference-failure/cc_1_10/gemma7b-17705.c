//Gemma-7B DATASET v1.0 Category: Text processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void process_text(char **text)
{
    int i = 0, j = 0, count = 0, word_size = 0;
    char word[MAX_SIZE];

    // Allocate memory for the text
    text = (char **)malloc(MAX_SIZE * sizeof(char *));

    // Read the text from the user
    printf("Enter text: ");
    getline(text, MAX_SIZE, stdin);

    // Split the text into words
    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            word[j] = '\0';
            count++;
            word_size = j;
            j = 0;
        }
        else
        {
            word[j] = text[i];
            j++;
        }
    }

    // Print the number of words in the text
    printf("Number of words: %d\n", count);

    // Print the average word size
    if (count)
    {
        word_size /= count;
        printf("Average word size: %d bytes\n", word_size);
    }

    // Free the memory allocated for the text
    free(text);
}

int main()
{
    char **text = NULL;
    process_text(text);

    return 0;
}