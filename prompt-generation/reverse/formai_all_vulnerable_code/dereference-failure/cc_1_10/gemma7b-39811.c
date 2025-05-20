//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10

typedef struct AlienWord
{
    char word[20];
    struct AlienWord* next;
} AlienWord;

AlienWord* insertWord(AlienWord* head, char* word)
{
    AlienWord* newNode = malloc(sizeof(AlienWord));
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

void translateWord(AlienWord* head, char* source, char* translation)
{
    char* pSource = source;
    char* pTranslation = translation;

    while (*pSource)
    {
        int found = 0;

        AlienWord* currentWord = head;

        while (currentWord)
        {
            if (strcmp(currentWord->word, pSource) == 0)
            {
                found = 1;
                strcpy(pTranslation, currentWord->word);
                break;
            }

            currentWord = currentWord->next;
        }

        if (!found)
        {
            pTranslation[0] = '\0';
        }

        pSource++;
        pTranslation++;
    }
}

int main()
{
    AlienWord* head = NULL;

    insertWord(head, "Zorg");
    insertWord(head, "Barg");
    insertWord(head, "Quux");

    char source[] = "Zorg, Barg, Quux";
    char translation[MAX_WORDS][20] = { "" };

    translateWord(head, source, translation);

    for (int i = 0; translation[i][0] != '\0'; i++)
    {
        printf("%s ", translation[i]);
    }

    printf("\n");

    return 0;
}