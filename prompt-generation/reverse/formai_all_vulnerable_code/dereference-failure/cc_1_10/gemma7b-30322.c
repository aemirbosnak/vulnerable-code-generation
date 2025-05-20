//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

typedef struct Word
{
    char word[20];
    struct Word* next;
} Word;

Word* insertWord(Word* head, char* word)
{
    Word* newWord = malloc(sizeof(Word));
    strcpy(newWord->word, word);
    newWord->next = NULL;

    if (head == NULL)
    {
        head = newWord;
    }
    else
    {
        head->next = newWord;
    }

    return head;
}

int main()
{
    Word* head = NULL;

    // Multiplayer code
    printf("Welcome to the spell checker!\n");
    printf("Please enter a word: ");
    char word[20];
    scanf("%s", word);

    insertWord(head, word);

    printf("Here is a list of words in the dictionary:\n");
    Word* currentWord = head;
    while (currentWord)
    {
        printf("%s\n", currentWord->word);
        currentWord = currentWord->next;
    }

    return 0;
}