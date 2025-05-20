//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word
{
    char *word;
    int frequency;
} Word;

Word *words = NULL;

void addWord(char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->frequency = 0;

    if (words == NULL)
    {
        words = newWord;
    }
    else
    {
        words = realloc(words, (words->frequency + 1) * sizeof(Word));
        words->frequency++;
        words = words + 1;
        words->word = strdup(word);
        words->frequency = 0;
    }
}

void printWordFrequencies()
{
    for (Word *word = words; word != NULL; word++)
    {
        printf("%s: %d\n", word->word, word->frequency);
    }
}

int main()
{
    addWord("apple");
    addWord("banana");
    addWord("orange");
    addWord("apple");
    addWord("banana");

    printWordFrequencies();

    return 0;
}