//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10

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
    for (Word *word = wordList; word; word = word->next)
    {
        printf("%s translates to ", word->word);

        switch (word->word[0])
        {
            case 'a':
                printf("apple\n");
                break;
            case 'b':
                printf("banana\n");
                break;
            case 'c':
                printf("cherry\n");
                break;
            default:
                printf("Unknown fruit\n");
                break;
        }
    }
}

int main()
{
    Word *wordList = createWord("apple");
    wordList = createWord("banana");
    wordList = createWord("cherry");

    translate(wordList);

    return 0;
}