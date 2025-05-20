//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct AlienWord
{
    char word[MAX_WORDS];
    int frequency;
    struct AlienWord* next;
} AlienWord;

AlienWord* alienWordInsert(AlienWord* head, char* word)
{
    AlienWord* newWord = malloc(sizeof(AlienWord));
    strcpy(newWord->word, word);
    newWord->frequency = 1;
    newWord->next = NULL;

    if (head == NULL)
    {
        return newWord;
    }

    AlienWord* currentWord = head;
    AlienWord* previousWord = NULL;

    while (currentWord)
    {
        if (strcmp(currentWord->word, word) == 0)
        {
            currentWord->frequency++;
            return head;
        }

        previousWord = currentWord;
        currentWord = currentWord->next;
    }

    previousWord->next = newWord;
    return head;
}

int alienWordTranslate(AlienWord* head, char* sentence)
{
    char* words = strtok(sentence, " ");
    int i = 0;

    while (words[i] != NULL)
    {
        alienWordInsert(head, words[i]);
        i++;
    }

    return 0;
}

int main()
{
    AlienWord* head = NULL;
    alienWordTranslate(head, "The quick brown fox jumps over the lazy dog.");

    char* sentence = "Do you have any questions about this alien language translator?";

    alienWordTranslate(head, sentence);

    return 0;
}