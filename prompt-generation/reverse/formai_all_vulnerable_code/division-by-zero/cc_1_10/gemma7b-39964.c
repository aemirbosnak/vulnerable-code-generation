//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTENCE_LENGTH 256

int main()
{
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    int sentiment_score = sentiment_analysis(sentence);

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

int sentiment_analysis(char *sentence)
{
    int sentiment_score = 0;
    int word_count = 0;

    // Tokenize the sentence into words
    char *word = strtok(sentence, " ");

    // Iterate over the words in the sentence
    while (word)
    {
        // Check if the word is a positive word
        if (is_positive_word(word))
        {
            sentiment_score++;
        }

        // Check if the word is a negative word
        else if (is_negative_word(word))
        {
            sentiment_score--;
        }

        word = strtok(NULL, " ");
        word_count++;
    }

    // Calculate the sentiment score
    sentiment_score = sentiment_score / word_count;

    return sentiment_score;
}

int is_positive_word(char *word)
{
    char *positive_words[] = {"happy", "joy", "love", "good", "excellent", "wonderful"};

    for (int i = 0; i < sizeof(positive_words) / sizeof(char *); i++)
    {
        if (strcmp(word, positive_words[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int is_negative_word(char *word)
{
    char *negative_words[] = {"sad", "hate", "anger", "bad", "terrible", "awful"};

    for (int i = 0; i < sizeof(negative_words) / sizeof(char *); i++)
    {
        if (strcmp(word, negative_words[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}