//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 20

typedef struct Word
{
    char *word;
    struct Word *next;
} Word;

Word *createWord(char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    return newWord;
}

void translate(Word *wordList)
{
    char **translations = malloc(MAX_WORDS * sizeof(char *));
    translations[0] = "Meow";
    translations[1] = "Purr";
    translations[2] = "Meow-Meow";
    translations[3] = "Rrrr";
    translations[4] = "Meow-Purr";
    translations[5] = "Meow-Meow-Meow";

    for (Word *word = wordList; word; word = word->next)
    {
        for (int i = 0; translations[i]; i++)
        {
            if (strcmp(word->word, translations[i]) == 0)
            {
                printf("%s ", translations[i+1]);
            }
        }
    }

    free(translations);
}

int main()
{
    Word *wordList = createWord("Meow");
    wordList = createWord("Purr");
    wordList = createWord("Meow-Meow");

    translate(wordList);

    return 0;
}