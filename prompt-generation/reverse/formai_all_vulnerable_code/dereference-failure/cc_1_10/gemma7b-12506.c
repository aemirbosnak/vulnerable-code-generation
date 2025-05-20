//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTIMENT_WORDS 100

char **sentiment_words(char **words)
{
    char **new_words = malloc(sizeof(char *) * MAX_SENTIMENT_WORDS);

    new_words[0] = "happy";
    new_words[1] = "sad";
    new_words[2] = "angry";
    new_words[3] = "fearful";
    new_words[4] = "surprised";
    new_words[5] = "excited";
    new_words[6] = "content";
    new_words[7] = "neutral";

    // Add more words...

    words = new_words;
    return words;
}

int sentiment_analysis(char *text)
{
    char **words = sentiment_words(NULL);

    int sentiment = 0;
    for (int i = 0; words[i] != NULL; i++)
    {
        if (strstr(text, words[i]) != NULL)
        {
            sentiment++;
        }
    }

    free(words);
    return sentiment;
}

int main()
{
    char text[] = "I am happy today.";

    int sentiment = sentiment_analysis(text);

    if (sentiment > 0)
    {
        printf("The text is positive.\n");
    }
    else
    {
        printf("The text is negative.\n");
    }

    return 0;
}