//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct AlienWord
{
    char *word;
    int translation;
} AlienWord;

AlienWord alien_words[MAX_WORDS];

int main()
{
    int i = 0;
    alien_words[i].word = "Blorgnak";
    alien_words[i].translation = 42;
    i++;

    alien_words[i].word = "Flork";
    alien_words[i].translation = 66;
    i++;

    alien_words[i].word = "Zork";
    alien_words[i].translation = 99;
    i++;

    char alien_text[MAX_WORD_LENGTH];

    printf("Enter alien text: ");
    fgets(alien_text, MAX_WORD_LENGTH, stdin);

    char *words = strtok(alien_text, " ");

    while (words)
    {
        int word_translation = 0;

        for (int j = 0; j < MAX_WORDS; j++)
        {
            if (strcmp(words, alien_words[j].word) == 0)
            {
                word_translation = alien_words[j].translation;
            }
        }

        printf("Translation: %d\n", word_translation);
        words = strtok(NULL, " ");
    }

    return 0;
}