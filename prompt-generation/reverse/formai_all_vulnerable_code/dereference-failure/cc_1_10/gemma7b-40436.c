//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1024

typedef struct Word
{
    char *word;
    int frequency;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word)
{
    Word *newNode = malloc(sizeof(Word));
    newNode->word = strdup(word);
    newNode->frequency = 1;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Word *iter = head;
        while (iter->next)
        {
            iter = iter->next;
        }
        iter->next = newNode;
    }

    return head;
}

int analyzeSentiment(Word *head)
{
    int sentiment = 0;
    Word *iter = head;
    while (iter)
    {
        char *word = iter->word;
        if (strcmp(word, "happy") == 0 || strcmp(word, "joy") == 0)
        {
            sentiment++;
        }
        else if (strcmp(word, "sad") == 0 || strcmp(word, "sorry") == 0)
        {
            sentiment--;
        }
        else if (strcmp(word, "angry") == 0 || strcmp(word, "hate") == 0)
        {
            sentiment -= 2;
        }
        iter = iter->next;
    }

    return sentiment;
}

int main()
{
    Word *head = NULL;
    head = insertWord(head, "happy");
    head = insertWord(head, "sad");
    head = insertWord(head, "angry");
    head = insertWord(head, "joy");
    head = insertWord(head, "hate");

    int sentiment = analyzeSentiment(head);
    printf("Sentiment score: %d\n", sentiment);

    return 0;
}