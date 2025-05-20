//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_WORDS 1000

int main()
{
    setlocale(LC_ALL, "");

    char text[] = "This text is positive, full of joy, and makes me happy.";
    char *words[MAX_WORDS];
    int num_words = tokenize(text, words);
    int sentiment = sentiment_analysis(words, num_words);

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

int tokenize(char *text, char **words)
{
    char *p = text;
    int i = 0;
    words[0] = NULL;

    while (p)
    {
        char *word = strsep(p, " \t\n\r");
        if (word)
        {
            words[i++] = word;
        }
        p = word ? NULL : p;
    }

    return i;
}

int sentiment_analysis(char **words, int num_words)
{
    int sentiment = 0;
    for (int i = 0; i < num_words; i++)
    {
        if (words[i] && words[i][0] >= 'a' && words[i][0] <= 'z')
        {
            sentiment++;
        }
        else if (words[i] && words[i][0] >= 'A' && words[i][0] <= 'Z')
        {
            sentiment++;
        }
    }

    return sentiment;
}