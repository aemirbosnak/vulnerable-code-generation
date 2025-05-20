//Gemma-7B DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void process_text(char **buffer)
{
    int i = 0;
    char word[MAX_BUFFER_SIZE];
    char *p = *buffer;

    while (*p)
    {
        // Ignore punctuation and whitespace
        if (!isalnum(*p) && *p != '\n' && *p != '\t')
        {
            continue;
        }

        // Create a word
        word[0] = *p;
        i = 1;

        // Iterate over the remaining characters in the word
        while (isalnum(*p) && *p)
        {
            word[i] = *p;
            i++;
            p++;
        }

        // Process the word
        printf("%s ", word);
    }

    printf("\n");
}

int main()
{
    char *buffer = malloc(MAX_BUFFER_SIZE);
    getline(buffer, MAX_BUFFER_SIZE, stdin);

    process_text(&buffer);

    free(buffer);

    return 0;
}