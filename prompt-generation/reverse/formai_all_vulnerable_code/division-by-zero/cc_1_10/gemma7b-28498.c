//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTENCE_LENGTH 256

int sentiment_analysis(char *sentence)
{
    int i, positive = 0, negative = 0, neutral = 0;
    char word[MAX_SENTENCE_LENGTH];

    // Tokenize the sentence into words
    char *words = strtok(sentence, " ");
    while (words)
    {
        // Check if the word is positive or negative
        if (strcmp(words, "good") == 0 || strcmp(words, "great") == 0 || strcmp(words, "excellent") == 0)
        {
            positive++;
        }
        else if (strcmp(words, "bad") == 0 || strcmp(words, "terrible") == 0 || strcmp(words, "awful") == 0)
        {
            negative++;
        }
        else
        {
            neutral++;
        }

        words = strtok(NULL, " ");
    }

    // Calculate the sentiment score
    int score = (positive - negative) * 100 / (positive + negative + neutral);

    return score;
}

int main()
{
    char sentence[MAX_SENTENCE_LENGTH];

    // Get the sentence from the user
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Analyze the sentiment of the sentence
    int sentiment_score = sentiment_analysis(sentence);

    // Print the sentiment score
    printf("The sentiment score for the sentence is: %d%\n", sentiment_score);

    return 0;
}