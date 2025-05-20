//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct WordCount
{
    char **words;
    int wordCount;
} WordCount;

WordCount *wordCount_init(int capacity)
{
    WordCount *wordCount = malloc(sizeof(WordCount));
    wordCount->words = malloc(sizeof(char *) * capacity);
    wordCount->wordCount = 0;

    return wordCount;
}

void wordCount_addWord(WordCount *wordCount, char *word)
{
    wordCount->words[wordCount->wordCount++] = word;
}

void wordCount_printWords(WordCount *wordCount)
{
    for (int i = 0; i < wordCount->wordCount; i++)
    {
        printf("%s ", wordCount->words[i]);
    }

    printf("\n");
}

int main()
{
    WordCount *wordCountA = wordCount_init(MAX_WORDS);
    WordCount *wordCountB = wordCount_init(MAX_WORDS);

    // Multiplayer interaction
    char *wordA = "Hello";
    char *wordB = "World";

    wordCount_addWord(wordCountA, wordA);
    wordCount_addWord(wordCountB, wordB);

    wordCount_printWords(wordCountA);
    wordCount_printWords(wordCountB);

    return 0;
}