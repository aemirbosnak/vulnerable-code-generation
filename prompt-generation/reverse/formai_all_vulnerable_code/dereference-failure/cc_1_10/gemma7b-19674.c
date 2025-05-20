//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

typedef struct Word
{
    char *word;
    struct Word *next;
} Word;

Word *head = NULL;

void insertWord(char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    if (head == NULL)
    {
        head = newWord;
    }
    else
    {
        head->next = newWord;
        head = newWord;
    }
}

char *translate(char * alienLanguage)
{
    char *translated = malloc(MAX_WORD_LENGTH);

    Word *currWord = head;

    while (currWord)
    {
        if (strcmp(alienLanguage, currWord->word) == 0)
        {
            strcpy(translated, currWord->word);
            break;
        }

        currWord = currWord->next;
    }

    return translated;
}

int main()
{
    insertWord("Greetings, human.");
    insertWord("May the force be with you.");
    insertWord("Welcome to the galaxy.");

    char *alienLanguage = "Greetings, alien.";

    char *translated = translate(alienLanguage);

    printf("%s", translated);

    return 0;
}