//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

int main()
{
    char text[MAX_WORDS];
    printf("Enter text: ");
    fgets(text, MAX_WORDS, stdin);

    char *words[MAX_WORDS];
    int num_words = tokenize(text, words);

    int sentiment_score = calculate_sentiment(words);

    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}

int tokenize(char *text, char **words)
{
    char *ptr = text;
    int i = 0;
    words = malloc(MAX_WORDS * sizeof(char *));

    while (ptr)
    {
        char *word = malloc(MAX_WORDS);
        word = strtok(ptr, " \t\n");
        if (word)
        {
            words[i++] = word;
        }
        ptr = strstr(ptr, word) + strlen(word);
    }

    return i;
}

int calculate_sentiment(char **words)
{
    int sentiment_score = 0;
    for (int i = 0; words[i]; i++)
    {
        if (is_positive(words[i]))
        {
            sentiment_score++;
        }
        else if (is_negative(words[i]))
        {
            sentiment_score--;
        }
    }

    return sentiment_score;
}

int is_positive(char *word)
{
    return strstr(word, "happy") || strstr(word, "good") || strstr(word, "excellent") || strstr(word, "great") || strstr(word, "wonderful");
}

int is_negative(char *word)
{
    return strstr(word, "sad") || strstr(word, "bad") || strstr(word, "terrible") || strstr(word, "awful") || strstr(word, "horrible");
}