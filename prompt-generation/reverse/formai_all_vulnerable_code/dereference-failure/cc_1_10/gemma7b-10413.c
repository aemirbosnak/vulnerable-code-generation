//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10

typedef struct Word
{
    char *word;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    if (head == NULL)
    {
        head = newWord;
    }
    else
    {
        head->next = insertWord(head->next, word);
    }

    return head;
}

void translateCat(Word *head)
{
    Word *currentWord = head;

    while (currentWord)
    {
        printf("%s", currentWord->word);
        printf(" --> ");

        switch (rand() % 3)
        {
            case 0:
                printf("Meow!");
                break;
            case 1:
                printf("Purr!");
                break;
            case 2:
                printf("Meow-purr!");
                break;
        }

        printf("\n");

        currentWord = currentWord->next;
    }
}

int main()
{
    Word *head = NULL;

    insertWord(head, "Cat");
    insertWord(head, "Dog");
    insertWord(head, "Fish");
    insertWord(head, "Rabbit");

    translateCat(head);

    return 0;
}