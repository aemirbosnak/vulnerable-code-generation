//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

char **allocate_memory(int size)
{
    char **ptr = (char**)malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++)
    {
        ptr[i] = (char*)malloc(MAX * sizeof(char));
    }
    return ptr;
}

int sentiment_analysis(char *text)
{
    char **words = allocate_memory(100);
    int num_words = 0;

    // Tokenization
    char *word = strtok(text, " ");
    while (word)
    {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Sentiment Analysis
    int sentiment = 0;
    for (int i = 0; i < num_words; i++)
    {
        if (words[i][0] == 'n' || words[i][0] == 'p')
        {
            sentiment--;
        }
        else if (words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'h')
        {
            sentiment++;
        }
    }

    free(words);
    return sentiment;
}

int main()
{
    char text[] = "I am very happy today. The sun is shining and the flowers are blooming. I am also feeling grateful for all the good things in my life.";

    int sentiment = sentiment_analysis(text);

    if (sentiment > 0)
    {
        printf("The text has a positive sentiment.\n");
    }
    else if (sentiment < 0)
    {
        printf("The text has a negative sentiment.\n");
    }
    else
    {
        printf("The text has a neutral sentiment.\n");
    }

    return 0;
}