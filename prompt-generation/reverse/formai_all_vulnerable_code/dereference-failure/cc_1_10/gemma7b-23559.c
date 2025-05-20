//Gemma-7B DATASET v1.0 Category: Data mining ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void analyze_data(char **data)
{
    int i, j, count = 0, max_length = 0;
    char **words = NULL;

    for (i = 0; data[i] != NULL; i++)
    {
        for (j = 0; data[i][j] != '\0'; j++)
        {
            if (data[i][j] >= 'a' && data[i][j] <= 'z')
            {
                count++;
            }
        }
        if (max_length < strlen(data[i]))
        {
            max_length = strlen(data[i]);
        }
    }

    words = (char **)malloc(max_length * count * sizeof(char *));

    for (i = 0; data[i] != NULL; i++)
    {
        for (j = 0; data[i][j] != '\0'; j++)
        {
            if (data[i][j] >= 'a' && data[i][j] <= 'z')
            {
                words[count++] = data[i] + j;
            }
        }
    }

    printf("Number of words: %d\n", count);
    printf("Maximum length of a word: %d\n", max_length);
    printf("List of words:\n");
    for (i = 0; words[i] != NULL; i++)
    {
        printf("%s\n", words[i]);
    }

    free(words);
}

int main()
{
    char **data = NULL;
    data = (char **)malloc(MAX_SIZE * sizeof(char *));

    data[0] = "This is a sentence with many words.";
    data[1] = "It also has a few numbers.";
    data[2] = "But the most important thing is the data mining example.";

    analyze_data(data);

    free(data);

    return 0;
}