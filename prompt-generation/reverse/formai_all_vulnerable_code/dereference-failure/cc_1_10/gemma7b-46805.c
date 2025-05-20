//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: complex
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word
{
    char *word;
    int count;
} Word;

Word words[MAX_WORDS];

void addWord(char *word)
{
    int i = 0;
    for (; words[i].word && words[i].count; i++) {}

    words[i].word = malloc(strlen(word) + 1);
    strcpy(words[i].word, word);
    words[i].count = 1;
}

void incrementWord(char *word)
{
    int i = 0;
    for (; words[i].word && words[i].count; i++)
    {
        if (strcmp(words[i].word, word) == 0)
        {
            words[i].count++;
            return;
        }
    }

    addWord(word);
}

int main()
{
    addWord("apple");
    addWord("banana");
    addWord("orange");
    incrementWord("apple");
    incrementWord("banana");

    for (int i = 0; words[i].word; i++)
    {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}