//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTENCE_LENGTH 255

int sentiment_analysis(char *sentence)
{
    int sentiment = 0;
    char *words[MAX_SENTENCE_LENGTH];
    int i = 0;

    // Tokenize the sentence
    words[i] = strtok(sentence, " ");
    while (words[i] != NULL)
    {
        // Check if the word is positive or negative
        if (strcmp(words[i], "good") == 0 || strcmp(words[i], "excellent") == 0)
        {
            sentiment++;
        }
        else if (strcmp(words[i], "bad") == 0 || strcmp(words[i], "terrible") == 0)
        {
            sentiment--;
        }
        i++;
    }

    return sentiment;
}

int main()
{
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    int sentiment = sentiment_analysis(sentence);

    if (sentiment > 0)
    {
        printf("Sentiment: Positive\n");
    }
    else if (sentiment < 0)
    {
        printf("Sentiment: Negative\n");
    }
    else
    {
        printf("Sentiment: Neutral\n");
    }

    return 0;
}