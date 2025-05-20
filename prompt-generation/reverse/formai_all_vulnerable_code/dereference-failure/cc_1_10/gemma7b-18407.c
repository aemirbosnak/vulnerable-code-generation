//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 200

int main()
{
    setlocale(LC_ALL, "");

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    char words[MAX_WORDS][MAX_WORDS];
    int num_words = tokenize(sentence, words);

    int sentiment_score = calculate_sentiment(words);

    printf("Sentiment score: %d", sentiment_score);

    return 0;
}

int tokenize(char *sentence, char **words)
{
    int i = 0;
    char *word = strtok(sentence, " ");

    while (word)
    {
        strcpy(words[i], word);
        i++;
        word = strtok(NULL, " ");
    }

    return i;
}

int calculate_sentiment(char **words)
{
    int i = 0;
    int sentiment_score = 0;

    for (i = 0; words[i] != NULL; i++)
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
    char *positive_words[] = {"happy", "joy", "love", "good", "excellent"};

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(word, positive_words[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int is_negative(char *word)
{
    char *negative_words[] = {"sad", "hate", "anger", "bad", "terrible"};

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(word, negative_words[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}