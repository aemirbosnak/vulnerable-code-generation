//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char str[1000];
    int i, sentiment, pos_words[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50}, neg_words[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sentiment = 0;

    printf("Enter a sentence: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }

        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 32;
        }
    }

    for (i = 0; pos_words[i] != 0; i++)
    {
        if (strstr(str, pos_words[i]) != NULL)
        {
            sentiment++;
        }
    }

    for (i = 0; neg_words[i] != 0; i++)
    {
        if (strstr(str, neg_words[i]) != NULL)
        {
            sentiment--;
        }
    }

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