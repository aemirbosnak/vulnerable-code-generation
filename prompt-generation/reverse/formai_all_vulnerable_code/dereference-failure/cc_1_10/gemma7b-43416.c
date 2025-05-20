//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct CatWord
{
    char word[20];
    struct CatWord* next;
} CatWord;

CatWord* insertWord(CatWord* head, char* word)
{
    CatWord* newWord = (CatWord*)malloc(sizeof(CatWord));
    strcpy(newWord->word, word);
    newWord->next = NULL;

    if (head == NULL)
    {
        return newWord;
    }

    head->next = insertWord(head->next, word);
    return head;
}

void translate(CatWord* head)
{
    printf("Meow!\n");

    while (head)
    {
        printf("%s, ", head->word);
        head = head->next;
    }

    printf("\n");
}

int main()
{
    CatWord* head = NULL;

    insertWord(head, "Meow");
    insertWord(head, "Woof");
    insertWord(head, "Chirp");
    insertWord(head, "Buzz");

    translate(head);

    return 0;
}