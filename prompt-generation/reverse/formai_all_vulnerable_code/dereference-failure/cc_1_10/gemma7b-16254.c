//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTIMENT_WORDS 20

int sentiment_analyzer(char *text)
{
    char **sentiment_words = (char **)malloc(MAX_SENTIMENT_WORDS * sizeof(char *));
    sentiment_words[0] = "happy";
    sentiment_words[1] = "sad";
    sentiment_words[2] = "angry";
    sentiment_words[3] = "fearful";
    sentiment_words[4] = "excited";
    sentiment_words[5] = "surprised";
    sentiment_words[6] = "curious";
    sentiment_words[7] = "proud";
    sentiment_words[8] = "ashamed";
    sentiment_words[9] = "optimistic";
    sentiment_words[10] = "pessimistic";

    int i;
    for (i = 0; sentiment_words[i] != NULL; i++)
    {
        if (strstr(text, sentiment_words[i]) != NULL)
        {
            return i + 1;
        }
    }

    return 0;
}

int main()
{
    char text[] = "I am happy that I am learning C programming.";
    int sentiment_score = sentiment_analyzer(text);

    switch (sentiment_score)
    {
        case 1:
            printf("The text is happy.\n");
            break;
        case 2:
            printf("The text is sad.\n");
            break;
        case 3:
            printf("The text is angry.\n");
            break;
        default:
            printf("The text does not contain any sentiment words.\n");
            break;
    }

    return 0;
}