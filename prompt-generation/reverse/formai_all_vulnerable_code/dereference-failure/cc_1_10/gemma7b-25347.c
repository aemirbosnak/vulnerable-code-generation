//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word
{
    char *word;
    int frequency;
} Word;

Word **words;

void initializeWords(int size)
{
    words = malloc(sizeof(Word *) * size);
    for (int i = 0; i < size; i++)
    {
        words[i] = malloc(sizeof(Word));
        words[i]->word = NULL;
        words[i]->frequency = 0;
    }
}

void addWord(char *word)
{
    int i = 0;
    for (Word *w = words; w && w->word; i++)
    {
        if (strcmp(w->word, word) == 0)
        {
            w->frequency++;
            return;
        }
    }

    words[i]->word = strdup(word);
    words[i]->frequency = 1;
}

void printWordStatistics()
{
    printf("Word Statistics:\n");
    for (int i = 0; words[i] && words[i]->word; i++)
    {
        printf("%s: %d occurrences\n", words[i]->word, words[i]->frequency);
    }
}

int main()
{
    initializeWords(MAX_WORDS);

    addWord("apple");
    addWord("banana");
    addWord("orange");
    addWord("apple");
    addWord("apricot");
    addWord("mango");

    printWordStatistics();

    return 0;
}