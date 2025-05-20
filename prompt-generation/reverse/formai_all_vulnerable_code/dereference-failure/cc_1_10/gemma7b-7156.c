//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct AlienWord
{
    char **words;
    int count;
} AlienWord;

AlienWord *createAlienWord(int size)
{
    AlienWord *word = malloc(sizeof(AlienWord));
    word->words = malloc(sizeof(char *) * size);
    word->count = 0;
    return word;
}

void addAlienWord(AlienWord *word, char *newWord)
{
    word->words[word->count++] = newWord;
}

int translateAlien(AlienWord *word, char *phrase)
{
    int i = 0;
    for (i = 0; phrase[i] != '\0'; i++)
    {
        char alienWord[MAX_WORDS];
        int j = 0;
        for (j = 0; word->words[j] != NULL; j++)
        {
            if (strcmp(phrase + i, word->words[j]) == 0)
            {
                printf("%s ", word->words[j + 1]);
                i += strlen(word->words[j]) - 1;
                break;
            }
        }
    }
    printf("\n");
    return 0;
}

int main()
{
    AlienWord *alienWords = createAlienWord(MAX_WORDS);
    addAlienWord(alienWords, "Zork");
    addAlienWord(alienWords, "Flubba");
    addAlienWord(alienWords, "Quux");
    addAlienWord(alienWords, "Bargle");

    translateAlien(alienWords, "The quick brown fox jumps over the sleeping Zork.");

    translateAlien(alienWords, "The Flubba is the best alien in the galaxy.");

    translateAlien(alienWords, "Quux and Bargle are friends forever.");

    return 0;
}