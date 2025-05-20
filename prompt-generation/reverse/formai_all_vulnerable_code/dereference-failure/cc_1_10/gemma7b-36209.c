//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

int main()
{
    char text[MAX_WORDS];
    char words[MAX_WORDS][MAX_WORDS];
    int num_words = 0;
    int i, j;
    int sentiment = 0;

    printf("Please enter text: ");
    fgets(text, MAX_WORDS, stdin);

    // Tokenize the text
    char *ptr = text;
    while (ptr)
    {
        char *word = strsep(ptr, " ");
        if (word)
        {
            strcpy(words[num_words], word);
            num_words++;
        }
        ptr = word;
    }

    // Calculate sentiment
    for (i = 0; i < num_words; i++)
    {
        for (j = 0; j < MAX_WORDS; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                if (words[j][0] >= 'a' && words[j][0] <= 'z')
                {
                    sentiment++;
                }
            }
        }
    }

    // Print sentiment
    if (sentiment > 0)
    {
        printf("The text is positive.\n");
    }
    else
    {
        printf("The text is negative.\n");
    }

    return 0;
}