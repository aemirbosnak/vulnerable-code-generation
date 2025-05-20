//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

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

int compareWords(Word *word1, Word *word2)
{
    return strcmp(word1->word, word2->word);
}

int detectSpam(char *text)
{
    Word *bannedWords = insertWord(NULL, "spam");
    bannedWords = insertWord(bannedWords, "junk");
    bannedWords = insertWord(bannedWords, "garbage");

    char *words = strtok(text, " ");

    for (char *word = words; word; word = strtok(NULL, " "))
    {
        if (compareWords(bannedWords, insertWord(NULL, word)) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    char *text = "This text contains spam and garbage.";

    if (detectSpam(text) == 1)
    {
        printf("Text contains spam.\n");
    }
    else
    {
        printf("Text does not contain spam.\n");
    }

    return 0;
}