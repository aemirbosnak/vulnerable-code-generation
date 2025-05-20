//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024
#define MAX_WORD_LENGTH 256

typedef struct AlienWord
{
    char **word;
    int length;
    struct AlienWord *next;
} AlienWord;

AlienWord *alienWord_create()
{
    AlienWord *newWord = malloc(sizeof(AlienWord));
    newWord->word = malloc(sizeof(char *) * MAX_WORDS);
    newWord->length = 0;
    newWord->next = NULL;

    return newWord;
}

void alienWord_addWord(AlienWord *wordList, char *word)
{
    wordList->word[wordList->length++] = word;
    if (wordList->length >= MAX_WORDS)
    {
        wordList->next = alienWord_create();
        wordList = wordList->next;
    }
}

void alienWord_translate(AlienWord *wordList, char *source)
{
    char *translated = malloc(sizeof(char) * MAX_WORD_LENGTH);
    int i = 0;
    for (i = 0; source[i] != '\0'; i++)
    {
        switch (source[i])
        {
            case 'a':
                translated[i] = 'z';
                break;
            case 'A':
                translated[i] = 'Z';
                break;
            default:
                translated[i] = source[i];
                break;
        }
    }
    translated[i] = '\0';

    printf("%s\n", translated);
}

int main()
{
    AlienWord *wordList = alienWord_create();
    alienWord_addWord(wordList, "Greetings, traveler.");
    alienWord_addWord(wordList, "May the Force be with you.");

    alienWord_translate(wordList, "Hello, world!");

    return 0;
}