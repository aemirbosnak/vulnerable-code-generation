//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

typedef struct AlienWord
{
    char **words;
    int numWords;
    int maxWords;
} AlienWord;

AlienWord *alienWordCreate(int numWords)
{
    AlienWord *aw = malloc(sizeof(AlienWord));
    aw->words = malloc(sizeof(char *) * numWords);
    aw->numWords = 0;
    aw->maxWords = numWords;

    return aw;
}

void alienWordAdd(AlienWord *aw, char *word)
{
    if (aw->numWords >= aw->maxWords)
    {
        return;
    }

    aw->words[aw->numWords++] = strdup(word);
}

char **alienWordTranslate(AlienWord *aw, char *phrase)
{
    char **translatedPhrase = malloc(sizeof(char *) * MAX_WORDS);

    int i = 0;
    char *word = strtok(phrase, " ");

    while (word)
    {
        int found = 0;

        for (int j = 0; j < aw->numWords; j++)
        {
            if (strcmp(word, aw->words[j]) == 0)
            {
                translatedPhrase[i++] = aw->words[j];
                found = 1;
                break;
            }
        }

        if (!found)
        {
            translatedPhrase[i++] = word;
        }

        word = strtok(NULL, " ");
    }

    translatedPhrase[i] = NULL;

    return translatedPhrase;
}

int main()
{
    AlienWord *aw = alienWordCreate(MAX_WORDS);

    alienWordAdd(aw, "Blorg");
    alienWordAdd(aw, "Flork");
    alienWordAdd(aw, "Zorch");

    char *phrase = "Hello, Blorg. How are you today?";

    char **translatedPhrase = alienWordTranslate(aw, phrase);

    printf("%s\n", translatedPhrase[0]);
    printf("%s\n", translatedPhrase[1]);
    printf("%s\n", translatedPhrase[2]);

    return 0;
}