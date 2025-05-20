//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

int main()
{
    char text[MAX_WORDS];
    char words[MAX_WORDS][MAX_WORDS];
    int numWords = 0;
    int i, j, sentiment = 0;

    printf("Enter text: ");
    fgets(text, MAX_WORDS, stdin);

    // Tokenize the text
    char *token = strtok(text, " ");
    while (token)
    {
        strcpy(words[numWords], token);
        numWords++;
        token = strtok(NULL, " ");
    }

    // Analyze the sentiment of each word
    for (i = 0; i < numWords; i++)
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

    // Calculate the overall sentiment
    sentiment /= numWords;

    // Print the sentiment
    printf("Overall sentiment: ");
    if (sentiment > 0)
    {
        printf("Positive\n");
    }
    else if (sentiment < 0)
    {
        printf("Negative\n");
    }
    else
    {
        printf("Neutral\n");
    }

    return 0;
}