//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

int main()
{
    char **words = NULL;
    char sentence[200];
    int sentiment_score = 0;
    int i, word_count = 0;

    printf("Enter a sentence: ");
    fgets(sentence, 200, stdin);

    // Tokenize the sentence into words
    words = tokenize(sentence);

    // Count the number of words in the sentence
    word_count = count_words(words);

    // Calculate the sentiment score for each word
    sentiment_score = calculate_sentiment(words, word_count);

    // Print the sentiment score for the sentence
    printf("Sentiment score for the sentence: %d\n", sentiment_score);

    // Free the memory allocated for words
    free(words);

    return 0;
}

int tokenize(char *sentence)
{
    char **words = NULL;
    int i = 0, word_count = 0;

    // Allocate memory for words
    words = (char **)malloc(MAX_WORDS * sizeof(char *));

    // Tokenize the sentence into words
    for (i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == ' ' || sentence[i] == ',' || sentence[i] == '.')
        {
            words[word_count++] = malloc(MAX_WORDS * sizeof(char));
            strcpy(words[word_count - 1], sentence + i);
        }
    }

    return words;
}

int count_words(char **words)
{
    int i = 0, word_count = 0;

    // Count the number of words in the sentence
    for (i = 0; words[i] != NULL; i++)
    {
        word_count++;
    }

    return word_count;
}

int calculate_sentiment(char **words, int word_count)
{
    int i, sentiment_score = 0;

    // Calculate the sentiment score for each word
    for (i = 0; i < word_count; i++)
    {
        sentiment_score += calculate_sentiment_score(words[i]);
    }

    // Return the sentiment score for the sentence
    return sentiment_score;
}

int calculate_sentiment_score(char *word)
{
    int sentiment_score = 0;

    // Assign sentiment score based on word
    if (strcmp(word, "happy") == 0)
    {
        sentiment_score = 5;
    }
    else if (strcmp(word, "sad") == 0)
    {
        sentiment_score = -5;
    }
    else if (strcmp(word, "good") == 0)
    {
        sentiment_score = 3;
    }
    else if (strcmp(word, "bad") == 0)
    {
        sentiment_score = -3;
    }

    return sentiment_score;
}