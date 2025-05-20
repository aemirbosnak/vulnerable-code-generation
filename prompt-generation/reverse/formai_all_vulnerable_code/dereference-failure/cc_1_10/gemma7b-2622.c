//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1024

typedef struct Word
{
    char *word;
    int sentiment;
} Word;

Word **load_words(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return NULL;
    }

    Word **words = malloc(MAX_WORDS * sizeof(Word));
    int i = 0;
    char line[1024];

    while (fgets(line, 1024, fp) != NULL)
    {
        char *word = strdup(line);
        Word *new_word = malloc(sizeof(Word));
        new_word->word = word;
        new_word->sentiment = rand() % 2 - 1;
        words[i++] = new_word;
    }

    fclose(fp);
    return words;
}

int main()
{
    Word **words = load_words("words.txt");

    for (int i = 0; words[i] != NULL; i++)
    {
        printf("%s has a sentiment of %d\n", words[i]->word, words[i]->sentiment);
    }

    free(words);

    return 0;
}