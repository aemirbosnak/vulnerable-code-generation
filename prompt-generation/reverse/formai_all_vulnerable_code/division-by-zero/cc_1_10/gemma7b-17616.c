//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 256

int main()
{
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Sentiment analysis
    int sentiment = sentiment_analysis(sentence);

    // Display sentiment
    switch (sentiment)
    {
        case 0:
            printf("Neutral\n");
            break;
        case 1:
            printf("Positive\n");
            break;
        case -1:
            printf("Negative\n");
            break;
    }

    return 0;
}

int sentiment_analysis(char *sentence)
{
    // Count the number of positive and negative words in the sentence
    int num_positive = count_positive_words(sentence);
    int num_negative = count_negative_words(sentence);

    // Calculate the sentiment score
    int sentiment = (num_positive - num_negative) / (num_positive + num_negative);

    return sentiment;
}

int count_positive_words(char *sentence)
{
    // Create an array of positive words
    char *positive_words[] = {"happy", "joy", "good", "great", "excellent"};

    // Iterate over the sentence and count the number of positive words
    int num_positive_words = 0;
    char *word = strtok(sentence, " ");
    while (word)
    {
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(word, positive_words[i]) == 0)
            {
                num_positive_words++;
            }
        }
        word = strtok(NULL, " ");
    }

    return num_positive_words;
}

int count_negative_words(char *sentence)
{
    // Create an array of negative words
    char *negative_words[] = {"sad", "sad", "bad", "terrible", "awful"};

    // Iterate over the sentence and count the number of negative words
    int num_negative_words = 0;
    char *word = strtok(sentence, " ");
    while (word)
    {
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(word, negative_words[i]) == 0)
            {
                num_negative_words++;
            }
        }
        word = strtok(NULL, " ");
    }

    return num_negative_words;
}