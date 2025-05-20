//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SENTENCE_LENGTH 256

int main()
{
    // Setlocale for language-independent string operations
    setlocale(LC_ALL, "");

    // Get the sentence to analyze
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Calculate the sentiment score
    int sentiment_score = calculate_sentiment(sentence);

    // Print the sentiment score
    if (sentiment_score > 0)
    {
        printf("The sentence is positive.\n");
    }
    else if (sentiment_score < 0)
    {
        printf("The sentence is negative.\n");
    }
    else
    {
        printf("The sentence is neutral.\n");
    }

    return 0;
}

int calculate_sentiment(char *sentence)
{
    // Count the number of positive and negative words in the sentence
    int positive_words = count_positive_words(sentence);
    int negative_words = count_negative_words(sentence);

    // Calculate the sentiment score
    int sentiment_score = positive_words - negative_words;

    return sentiment_score;
}

int count_positive_words(char *sentence)
{
    // Create an array of positive words
    char *positive_words[] = {"happy", "joy", "good", "excellent", "great", "wonderful"};

    // Iterate over the sentence and count the number of positive words
    int count = 0;
    for (int i = 0; i < MAX_SENTENCE_LENGTH; i++)
    {
        if (sentence[i] != '\0' && strstr(positive_words, sentence[i]) != NULL)
        {
            count++;
        }
    }

    return count;
}

int count_negative_words(char *sentence)
{
    // Create an array of negative words
    char *negative_words[] = {"sad", "angry", "bad", "terrible", "awful", "horrible"};

    // Iterate over the sentence and count the number of negative words
    int count = 0;
    for (int i = 0; i < MAX_SENTENCE_LENGTH; i++)
    {
        if (sentence[i] != '\0' && strstr(negative_words, sentence[i]) != NULL)
        {
            count++;
        }
    }

    return count;
}