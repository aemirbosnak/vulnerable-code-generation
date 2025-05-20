//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void translate(Word *head)
{
    printf("Meow, human. I am a translator of C Cat Language!\n");

    while (head)
    {
        printf("%s is translated to ", head->word);

        switch (head->word[0])
        {
            case 'a':
                printf("Meow\n");
                break;
            case 'b':
                printf("Bark\n");
                break;
            case 'c':
                printf("Claw\n");
                break;
            default:
                printf("Unknown\n");
                break;
        }

        head = head->next;
    }
}

int main()
{
    Word *head = NULL;

    insertWord(head, "Meow");
    insertWord(head, "Bark");
    insertWord(head, "Claw");

    translate(head);

    return 0;
}