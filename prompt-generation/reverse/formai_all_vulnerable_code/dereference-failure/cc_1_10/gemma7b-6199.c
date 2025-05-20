//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: innovative
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
        return newWord;
    }

    Word *currWord = head;
    while (currWord->next)
    {
        currWord = currWord->next;
    }

    currWord->next = newWord;

    return head;
}

void analyzeSentiment(Word *head)
{
    int totalWords = 0;
    int positiveWords = 0;
    int negativeWords = 0;

    Word *currWord = head;
    while (currWord)
    {
        totalWords++;
        if (strcmp(currWord->word, "good") == 0 || strcmp(currWord->word, "happy") == 0)
        {
            positiveWords++;
        }
        else if (strcmp(currWord->word, "bad") == 0 || strcmp(currWord->word, "sad") == 0)
        {
            negativeWords++;
        }
        currWord = currWord->next;
    }

    printf("Total words: %d\n", totalWords);
    printf("Positive words: %d\n", positiveWords);
    printf("Negative words: %d\n", negativeWords);
    printf("Sentiment score: %.2f\n", (float)(positiveWords - negativeWords) / totalWords);
}

int main()
{
    Word *head = NULL;

    insertWord(head, "good");
    insertWord(head, "bad");
    insertWord(head, "happy");
    insertWord(head, "sad");
    insertWord(head, "wonderful");
    insertWord(head, "terrible");

    analyzeSentiment(head);

    return 0;
}