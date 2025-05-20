//Gemma-7B DATASET v1.0 Category: Data mining ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void analyze_data(char **data, int size)
{
    int i, j, count = 0, max_count = 0, word_count = 0;
    char **words = NULL;

    for (i = 0; i < size; i++)
    {
        for (j = 0; data[i][j] != '\0'; j++)
        {
            if (data[i][j] >= 'a' && data[i][j] <= 'z')
            {
                word_count++;
            }
        }
    }

    words = malloc(word_count * sizeof(char *));

    for (i = 0; i < word_count; i++)
    {
        words[i] = malloc(20 * sizeof(char));
    }

    word_count = 0;

    for (i = 0; i < size; i++)
    {
        for (j = 0; data[i][j] != '\0'; j++)
        {
            if (data[i][j] >= 'a' && data[i][j] <= 'z')
            {
                words[word_count++] = data[i][j];
            }
        }
    }

    for (i = 0; i < word_count; i++)
    {
        printf("%s ", words[i]);
    }

    printf("\n");

    free(words);
}

int main()
{
    char **data = NULL;
    int size = 0;

    // Allocate memory for data
    data = malloc(5 * sizeof(char *));

    // Create data
    data[0] = "Hello, world!";
    data[1] = "This is a sentence.";
    data[2] = "I have a lot of words.";
    data[3] = "And I'm here to tell you about them.";
    data[4] = "So, let's see what we can find.";

    size = 5;

    analyze_data(data, size);

    free(data);

    return 0;
}