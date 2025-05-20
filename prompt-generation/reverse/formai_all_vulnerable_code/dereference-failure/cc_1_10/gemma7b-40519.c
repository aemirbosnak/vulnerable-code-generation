//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

int analyzeSentiment(Word *head)
{
    int sentiment = 0;
    char *positiveWords[] = {"happy", "joy", "love", "good", "excellent"};
    char *negativeWords[] = {"sad", "hate", "anger", "fear", "terrible"};

    for (Word *currWord = head; currWord; currWord = currWord->next)
    {
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(currWord->word, positiveWords[i]) == 0)
            {
                sentiment++;
            }
            else if (strcmp(currWord->word, negativeWords[i]) == 0)
            {
                sentiment--;
            }
        }
    }

    return sentiment;
}

int main()
{
    Word *head = NULL;
    insertWord(head, "I am happy");
    insertWord(head, "The weather is good");
    insertWord(head, "I hate this");
    insertWord(head, "This is terrible");

    int sentiment = analyzeSentiment(head);

    printf("Sentiment score: %d\n", sentiment);

    return 0;
}