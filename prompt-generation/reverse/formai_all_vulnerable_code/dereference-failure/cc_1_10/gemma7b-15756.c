//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1024

char **tokenize(char *str)
{
    char **words = NULL;
    int num_words = 0;
    char *word = NULL;

    word = strtok(str, " ");
    while (word)
    {
        words = realloc(words, (num_words + 1) * sizeof(char *));
        words[num_words++] = strdup(word);
        word = strtok(NULL, " ");
    }

    return words;
}

int sentiment_analysis(char **words)
{
    int sentiment = 0;
    int i = 0;

    for (i = 0; words[i] != NULL; i++)
    {
        if (words[i][0] == 'p' || words[i][0] == 'a' || words[i][0] == 'e')
        {
            sentiment++;
        }
        else if (words[i][0] == 'n' || words[i][0] == 'o' || words[i][0] == 's')
        {
            sentiment--;
        }
    }

    return sentiment;
}

int main()
{
    char str[] = "I am happy today. The weather is perfect.";
    char **words = tokenize(str);
    int sentiment = sentiment_analysis(words);

    printf("The sentiment of the text is: %d\n", sentiment);

    return 0;
}