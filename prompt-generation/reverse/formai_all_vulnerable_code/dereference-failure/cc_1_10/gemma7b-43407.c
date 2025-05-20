//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: medieval
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
    char **translations = malloc(MAX_WORDS * sizeof(char *));
    translations[0] = "Nay";
    translations[1] = "Sure";
    translations[2] = "Much Ado About Nothing";
    translations[3] = "Good Day";
    translations[4] = "Mayhap";
    translations[5] = "Greetings";
    translations[6] = "Toil and Trouble";
    translations[7] = "Thyself";
    translations[8] = "The Way";
    translations[9] = "Go Away";

    printf("Translation: ");
    for (Word *current = head; current; current = current->next)
    {
        printf("%s ", translations[searchWord(translations, current->word)]);
    }

    printf("\n");
}

int searchWord(char **translations, char *word)
{
    for (int i = 0; translations[i] != NULL; i++)
    {
        if (strcmp(translations[i], word) == 0)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    Word *head = NULL;

    insertWord(head, "Greetings");
    insertWord(head, "Toil and Trouble");
    insertWord(head, "Good Day");
    insertWord(head, "Nay");

    translate(head);

    return 0;
}