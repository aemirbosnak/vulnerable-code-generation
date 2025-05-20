//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_CHAR 20

char **wordList;

void initializeWordList()
{
    wordList = (char**)malloc(MAX_WORDS * sizeof(char*));
    for (int i = 0; i < MAX_WORDS; i++)
    {
        wordList[i] = (char*)malloc(MAX_CHAR * sizeof(char));
    }
}

void addWordToWordList(char* word)
{
    for (int i = 0; i < MAX_WORDS; i++)
    {
        if (wordList[i] == NULL)
        {
            strcpy(wordList[i], word);
            return;
        }
    }

    printf("Error: Word list is full.\n");
}

char* translateCat(char* word)
{
    for (int i = 0; i < MAX_WORDS; i++)
    {
        if (strcmp(wordList[i], word) == 0)
        {
            return wordList[i];
        }
    }

    return NULL;
}

int main()
{
    initializeWordList();

    addWordToWordList("Meow");
    addWordToWordList("Purr");
    addWordToWordList("Meow");

    char* translatedWord = translateCat("Meow");

    if (translatedWord)
    {
        printf("%s\n", translatedWord);
    }
    else
    {
        printf("Word not found.\n");
    }

    return 0;
}