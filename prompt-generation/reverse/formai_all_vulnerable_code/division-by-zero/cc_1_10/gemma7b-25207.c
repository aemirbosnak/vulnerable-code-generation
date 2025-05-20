//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: optimized
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1024

int main()
{
    char sentence[MAX_SENTENCE_LENGTH];
    int sentiment_score = 0;
    int word_count = 0;

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Calculate the sentiment score
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        char word[MAX_SENTENCE_LENGTH];
        int word_length = 0;

        // Extract words from the sentence
        while (sentence[i] != ' ' && sentence[i] != '\0')
        {
            word[word_length] = sentence[i];
            word_length++;
            i++;
        }

        // Calculate the sentiment score for each word
        sentiment_score += calculate_sentiment_score(word);

        // Increment the word count
        word_count++;
    }

    // Calculate the overall sentiment score
    sentiment_score /= word_count;

    // Print the sentiment score
    printf("The sentiment score is: %d", sentiment_score);

    return 0;
}

int calculate_sentiment_score(char *word)
{
    int score = 0;

    // Positive words
    if (strcmp(word, "happy") == 0 || strcmp(word, "joy") == 0 || strcmp(word, "good") == 0)
    {
        score = 2;
    }

    // Neutral words
    else if (strcmp(word, "neutral") == 0)
    {
        score = 0;
    }

    // Negative words
    else if (strcmp(word, "sad") == 0 || strcmp(word, "angry") == 0 || strcmp(word, "bad") == 0)
    {
        score = -2;
    }

    return score;
}