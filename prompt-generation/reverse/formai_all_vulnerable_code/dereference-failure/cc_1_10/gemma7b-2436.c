//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct CCatWord
{
    char word[20];
    struct CCatWord* next;
} CCatWord;

CCatWord* createWord(char* word)
{
    CCatWord* newWord = malloc(sizeof(CCatWord));
    strcpy(newWord->word, word);
    newWord->next = NULL;
    return newWord;
}

void translateCat(CCatWord* words)
{
    printf("Meow-meow! Here is your translation:\n");
    for (CCatWord* currentWord = words; currentWord; currentWord = currentWord->next)
    {
        printf("%s translates to ", currentWord->word);
        switch (currentWord->word[0])
        {
            case 'a':
                printf("Meow-meow!\n");
                break;
            case 'b':
                printf("Boo hoo!\n");
                break;
            case 'c':
                printf("Crazy cat!\n");
                break;
            default:
                printf("I am not able to translate that word.\n");
                break;
        }
    }
}

int main()
{
    CCatWord* words = createWord("Meow");
    words = createWord("Boo");
    words = createWord("Crazy cat");

    translateCat(words);

    return 0;
}