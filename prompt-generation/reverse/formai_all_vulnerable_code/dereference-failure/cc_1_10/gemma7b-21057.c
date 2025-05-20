//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

int main()
{
    char **words = NULL;
    int num_words = 0;

    // Initialize the words array
    words = malloc(MAX_WORDS * sizeof(char *));
    for (int i = 0; i < MAX_WORDS; i++)
    {
        words[i] = NULL;
    }

    // Get the number of words from the user
    printf("Enter the number of words: ");
    scanf("%d", &num_words);

    // Get the words from the user
    for (int i = 0; i < num_words; i++)
    {
        words[i] = malloc(20 * sizeof(char));
        printf("Enter the word: ");
        scanf("%s", words[i]);
    }

    // Calculate the sentiment of each word
    for (int i = 0; i < num_words; i++)
    {
        int sentiment = calculate_sentiment(words[i]);
        printf("The sentiment of the word '%s' is %d.\n", words[i], sentiment);
    }

    // Free the memory allocated for the words array
    for (int i = 0; i < num_words; i++)
    {
        free(words[i]);
    }
    free(words);

    return 0;
}

int calculate_sentiment(char *word)
{
    int sentiment = 0;
    char *sentiment_words[] = {"good", "bad", "happy", "sad", "angry", "joyful"};

    for (int i = 0; i < 6; i++)
    {
        if (strcmp(word, sentiment_words[i]) == 0)
        {
            sentiment = i + 1;
        }
    }

    return sentiment;
}