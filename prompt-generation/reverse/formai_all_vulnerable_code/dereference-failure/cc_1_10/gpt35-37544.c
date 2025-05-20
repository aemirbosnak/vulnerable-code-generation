//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

typedef struct Word
{
    char* text;
    int count;
} Word;

int compareWords(const void *a, const void *b)
{
    Word *wordA = (Word *)a;
    Word *wordB = (Word *)b;
    return (wordA->count < wordB->count) ? 1 : -1;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    char wordBuffer[MAX_WORD_LENGTH + 1];
    Word words[MAX_WORDS];
    int numWords = 0;
    int i;

    while (fscanf(fp, "%s", wordBuffer) == 1)
    {
        int length = strlen(wordBuffer);
        if (ispunct(wordBuffer[length - 1]))
        {
            wordBuffer[length - 1] = '\0';
        }

        for (i = 0; i < numWords; i++)
        {
            if (strcasecmp(wordBuffer, words[i].text) == 0)
            {
                words[i].count++;
                break;
            }
        }

        if (i == numWords)
        {
            words[numWords].text = (char*)malloc(strlen(wordBuffer) + 1);
            strcpy(words[numWords].text, wordBuffer);
            words[numWords].count = 1;
            numWords++;
        }
    }

    qsort(words, numWords, sizeof(Word), compareWords);

    for (i = 0; i < numWords; i++)
    {
        printf("%s: %d\n", words[i].text, words[i].count);
        free(words[i].text);
    }

    fclose(fp);

    return 0;
}