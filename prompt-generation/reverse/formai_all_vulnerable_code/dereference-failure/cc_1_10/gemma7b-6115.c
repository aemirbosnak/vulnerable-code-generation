//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct CatWord
{
    char word[20];
    int meaning;
    struct CatWord* next;
} CatWord;

CatWord* createWord(char* word, int meaning)
{
    CatWord* newWord = malloc(sizeof(CatWord));
    strcpy(newWord->word, word);
    newWord->meaning = meaning;
    newWord->next = NULL;

    return newWord;
}

void translate(CatWord* head)
{
    printf("Meow, my human. You have requested translation:\n");

    while (head)
    {
        printf("%s - ", head->word);
        switch (head->meaning)
        {
            case 0:
                printf("Hungry\n");
                break;
            case 1:
                printf("Sleepy\n");
                break;
            case 2:
                printf("Happy\n");
                break;
            case 3:
                printf("Angry\n");
                break;
            default:
                printf("Unknown\n");
                break;
        }
        head = head->next;
    }

    printf("Meow, I have finished translating.\n");
}

int main()
{
    CatWord* head = createWord("Meow", 0);
    createWord("Purr", 1);
    createWord("Happy", 2);
    createWord("Angry", 3);

    translate(head);

    return 0;
}