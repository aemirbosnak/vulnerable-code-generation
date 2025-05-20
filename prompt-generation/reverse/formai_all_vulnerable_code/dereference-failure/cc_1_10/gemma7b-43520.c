//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TOKENS 100

char **tokenize(char *str)
{
    char **tokens = NULL;
    int num_tokens = 0;
    char *token = strtok(str, " ");

    while (token)
    {
        tokens = realloc(tokens, (num_tokens + 1) * sizeof(char *));
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    return tokens;
}

int sentiment_analysis(char *token)
{
    int sentiment = 0;
    char *words_positive = "happy, joyful, glad, excited, positive, optimistic";
    char *words_negative = "sad, depressed, angry, hateful, negative, pessimistic";

    if (strchr(words_positive, token) != NULL)
    {
        sentiment = 1;
    }
    else if (strchr(words_negative, token) != NULL)
    {
        sentiment = -1;
    }

    return sentiment;
}

int main()
{
    char *str = "I am happy today. I am excited about the future.";
    char **tokens = tokenize(str);

    for (int i = 0; tokens[i] != NULL; i++)
    {
        int sentiment = sentiment_analysis(tokens[i]);
        printf("Token: %s, Sentiment: %d\n", tokens[i], sentiment);
    }

    free(tokens);

    return 0;
}