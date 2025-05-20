//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

char *getWord(char *sentence)
{
    char *word = NULL;
    char *p = sentence;
    int i = 0;

    while (*p)
    {
        if (*p >= 'a' && *p <= 'z')
        {
            word = (char *)malloc(MAX_WORDS);
            word[0] = *p;
            i = 1;
            while (*p >= 'a' && *p <= 'z' && i < MAX_WORDS)
            {
                p++;
                word[i] = *p;
                i++;
            }
            word[i] = '\0';
            return word;
        }
        p++;
    }

    return NULL;
}

int main()
{
    char *sentence = "Montague and Capulet, two feuding families, whose ancient grudge continues to poison the town of Verona.";
    char *word = getWord(sentence);

    if (word)
    {
        printf("Word: %s\n", word);
    }
    else
    {
        printf("No words found.\n");
    }

    return 0;
}