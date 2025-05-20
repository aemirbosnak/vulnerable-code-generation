//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1024

int sentiment_analysis(char *sentence)
{
    int words_count = 0;
    char **words = (char **)malloc(MAX_WORDS * sizeof(char *));

    // Tokenize the sentence
    char *word = strtok(sentence, " ");
    while (word)
    {
        words[words_count++] = word;
        word = strtok(NULL, " ");
    }

    // Calculate sentiment score
    int score = 0;
    for (int i = 0; i < words_count; i++)
    {
        // Positive words
        if (strcmp(words[i], "happy") == 0 || strcmp(words[i], "joy") == 0 || strcmp(words[i], "good") == 0)
        {
            score++;
        }
        // Negative words
        else if (strcmp(words[i], "sad") == 0 || strcmp(words[i], "angry") == 0 || strcmp(words[i], "bad") == 0)
        {
            score--;
        }
    }

    // Free memory
    free(words);

    return score;
}

int main()
{
    char sentence[] = "I am happy that I am a student.";

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