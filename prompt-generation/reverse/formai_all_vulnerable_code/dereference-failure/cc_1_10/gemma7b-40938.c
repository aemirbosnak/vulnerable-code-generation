//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_WORDS 100

int main()
{
    char text[MAX_WORDS] = "The quick brown fox jumps over the lazy dog. The swift brown fox jumps over the slumbering lion.";
    char **words = NULL;
    int num_words = 0;
    int i = 0;
    int sentiment = 0;

    // Tokenize the text
    words = tokenizer(text, &num_words);

    // Calculate the sentiment of each word
    for (i = 0; i < num_words; i++)
    {
        sentiment += sentiment_score(words[i]);
    }

    // Print the overall sentiment
    printf("The overall sentiment of the text is: %d\n", sentiment);

    // Free the memory allocated for words
    free(words);

    return 0;
}

int tokenizer(char *text, int *num_words)
{
    char **words = NULL;
    int i = 0;
    int num_words_temp = 0;

    // Allocate memory for words
    words = malloc(sizeof(char *) * MAX_WORDS);

    // Tokenize the text
    char *token = strtok(text, " ");
    while (token)
    {
        words[num_words_temp] = strdup(token);
        num_words_temp++;
        token = strtok(NULL, " ");
    }

    // Update the number of words
    *num_words = num_words_temp;

    return words;
}

int sentiment_score(char *word)
{
    int sentiment = 0;

    // Positive words
    if (strcmp(word, "good") == 0)
    {
        sentiment++;
    }
    else if (strcmp(word, "happy") == 0)
    {
        sentiment++;
    }
    else if (strcmp(word, "joy") == 0)
    {
        sentiment++;
    }

    // Negative words
    else if (strcmp(word, "bad") == 0)
    {
        sentiment--;
    }
    else if (strcmp(word, "sad") == 0)
    {
        sentiment--;
    }
    else if (strcmp(word, "angry") == 0)
    {
        sentiment--;
    }

    // Neutral words
    else
    {
        sentiment = 0;
    }

    return sentiment;
}