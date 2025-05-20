//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 20

typedef struct CatWord
{
    char word[MAX_WORD_LEN];
    struct CatWord* next;
} CatWord;

CatWord* insertWord(CatWord* head, char* word)
{
    CatWord* newNode = malloc(sizeof(CatWord));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }

    return head;
}

void translateCat(CatWord* head)
{
    while (head)
    {
        printf("%s is translated to ", head->word);

        switch (head->word[0])
        {
            case 'a':
                printf("Meow\n");
                break;
            case 'e':
                printf("Purr\n");
                break;
            case 'i':
                printf("Meow-meow\n");
                break;
            case 'o':
                printf("Meow-purr\n");
                break;
            default:
                printf("Unknown sound\n");
                break;
        }
        head = head->next;
    }
}

int main()
{
    CatWord* head = NULL;

    insertWord(head, "apple");
    insertWord(head, "eat");
    insertWord(head, "idea");
    insertWord(head, "orange");

    translateCat(head);

    return 0;
}