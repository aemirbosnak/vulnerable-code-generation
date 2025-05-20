//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 20

typedef struct Word
{
    char *word;
    int sentiment;
} Word;

Word **loadWords(char *filename)
{
    Word **words = malloc(MAX_WORDS * sizeof(Word));

    FILE *fp = fopen(filename, "r");
    char line[1024];

    int i = 0;
    while (fgets(line, 1024, fp) != NULL)
    {
        char *word = strdup(line);
        words[i] = malloc(sizeof(Word));
        words[i]->word = word;
        words[i]->sentiment = rand() % 2 - 1;
        i++;
    }

    fclose(fp);
    return words;
}

int main()
{
    Word **words = loadWords("words.txt");

    char *sentence = "The movie was fantastic!";

    int sentiment = 0;
    for (int i = 0; words[i] != NULL; i++)
    {
        if (strstr(sentence, words[i]->word))
        {
            sentiment += words[i]->sentiment;
        }
    }

    if (sentiment > 0)
    {
        printf("Positive sentiment\n");
    }
    else
    {
        printf("Negative sentiment\n");
    }

    return 0;
}