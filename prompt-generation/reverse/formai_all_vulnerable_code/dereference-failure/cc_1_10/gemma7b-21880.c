//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WORDS 1000

typedef struct Word
{
    char *word;
    int frequency;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->frequency = 1;
    newWord->next = NULL;

    if (head == NULL)
    {
        head = newWord;
    }
    else
    {
        Word *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newWord;
    }

    return head;
}

int analyzeSentiment(Word *head)
{
    int sentiment = 0;
    Word *temp = head;
    while (temp)
    {
        char *word = temp->word;
        if (strcmp(word, "happy") == 0)
        {
            sentiment++;
        }
        else if (strcmp(word, "sad") == 0)
        {
            sentiment--;
        }
        else if (strcmp(word, "angry") == 0)
        {
            sentiment -= 2;
        }
        temp = temp->next;
    }

    return sentiment;
}

int main()
{
    Word *head = NULL;
    insertWord(head, "happy");
    insertWord(head, "sad");
    insertWord(head, "angry");
    insertWord(head, "happy");
    insertWord(head, "sad");

    int sentiment = analyzeSentiment(head);
    printf("Sentiment: %d\n", sentiment);

    return 0;
}