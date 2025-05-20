//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct AlienWord
{
    char *word;
    struct AlienWord *next;
} AlienWord;

AlienWord *createAlienWord(char *word)
{
    AlienWord *newWord = malloc(sizeof(AlienWord));
    newWord->word = strdup(word);
    newWord->next = NULL;
    return newWord;
}

int translateAlien(AlienWord *words, char *alienPhrase)
{
    char *phrase = strdup(alienPhrase);
    char *word = strtok(phrase, " ");
    int i = 0;

    while (word)
    {
        for (AlienWord *w = words; w; w = w->next)
        {
            if (strcmp(word, w->word) == 0)
            {
                printf("%s ", w->word);
                i++;
            }
        }

        word = strtok(NULL, " ");
    }

    printf("\n");

    return i;
}

int main()
{
    AlienWord *words = createAlienWord("zap");
    words = createAlienWord("quibble");
    words = createAlienWord("blork");

    translateAlien(words, "The zap is quick, the quibble is blue, and the blork is big.");

    return 0;
}