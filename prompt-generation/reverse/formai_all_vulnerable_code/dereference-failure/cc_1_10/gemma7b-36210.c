//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024
#define MAX_WORD_LENGTH 256

typedef struct Word
{
    char *word;
    struct Word *next;
} Word;

Word *word_list = NULL;

void add_word(char *word)
{
    Word *new_word = malloc(sizeof(Word));
    new_word->word = strdup(word);
    new_word->next = NULL;

    if (word_list == NULL)
    {
        word_list = new_word;
    }
    else
    {
        word_list->next = new_word;
        word_list = new_word;
    }
}

char *translate(char *source)
{
    char *translated = malloc(MAX_WORD_LENGTH);
    translated[0] = '\0';

    for (Word *word = word_list; word; word = word->next)
    {
        if (strcmp(source, word->word) == 0)
        {
            strcat(translated, word->word);
            strcat(translated, " ");
        }
    }

    return translated;
}

int main()
{
    add_word("Greetings, traveler.");
    add_word("May the force be with you.");
    add_word("Welcome to Earth.");

    char *source = "Greetings, traveler. May the force be with you.";
    char *translated = translate(source);

    printf("%s", translated);

    free(translated);
    return 0;
}