//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char *text = NULL;
    int text_length = 0;
    int i, j, k, l, n, m;

    printf("Enter text: ");

    // Allocate memory for the text
    text = malloc(MAX_BUFFER_SIZE);

    // Get the text from the user
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Calculate the text length
    text_length = strlen(buffer);

    // Copy the text to the allocated memory
    memcpy(text, buffer, text_length);

    // Text summarizer logic
    n = 0;
    m = 0;
    for (i = 0; i < text_length; i++)
    {
        int word_count = 0;
        for (j = i; j < text_length && buffer[j] != ' '; j++)
        {
            word_count++;
        }

        if (word_count > n)
        {
            n = word_count;
            m = i;
        }
    }

    // Print the summary
    printf("Summary: ");
    for (k = m; k < text_length && buffer[k] != '\n'; k++)
    {
        printf("%c ", buffer[k]);
    }

    // Free the allocated memory
    free(text);

    return 0;
}