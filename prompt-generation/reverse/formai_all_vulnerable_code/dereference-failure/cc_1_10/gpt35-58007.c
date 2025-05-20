//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

int main()
{
    char input[1000];
    char *words[MAX_WORD_LENGTH];
    int freq[MAX_WORD_LENGTH] = {0};
    int i, j, count = 0;

    printf("Enter a string:\n");
    fgets(input, 1000, stdin);

    /* Convert input to lower case */
    for (i = 0; input[i]; i++)
    {
        input[i] = tolower(input[i]);
    }

    /* Parse input string and save each word */
    i = 0;
    words[i] = strtok(input, " \n\t");
    while (words[i] != NULL)
    {
        i++;
        words[i] = strtok(NULL, " \n\t");
    }

    /* Count frequency of each word */
    for (i = 0; i < MAX_WORD_LENGTH; i++)
    {
        count = 0;
        for (j = 0; j < MAX_WORD_LENGTH; j++)
        {
            if (words[j] != NULL && strlen(words[j]) == i+1)
            {
                count++;
            }
        }
        freq[i] = count;
    }

    /* Print frequency of each word length */
    printf("Word Length\tFrequency\n");
    printf("-----------\t---------\n");
    for (i = 0; i < MAX_WORD_LENGTH; i++)
    {
        if (freq[i] > 0)
        {
            printf("%d\t\t%d\n", i+1, freq[i]);
        }
    }

    return 0;
}