//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: brave
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
    Word *prevWord = head;
    while (prevWord->next)
    {
      prevWord = prevWord->next;
    }
    prevWord->next = newWord;
  }

  return head;
}

void analyzeSentiment(Word *head)
{
  int positiveWords = 0;
  int negativeWords = 0;
  int neutralWords = 0;

  for (Word *word = head; word; word = word->next)
  {
    if (strcmp(word->word, "positive") == 0)
    {
      positiveWords++;
    }
    else if (strcmp(word->word, "negative") == 0)
    {
      negativeWords++;
    }
    else if (strcmp(word->word, "neutral") == 0)
    {
      neutralWords++;
    }
  }

  printf("Positive words: %d\n", positiveWords);
  printf("Negative words: %d\n", negativeWords);
  printf("Neutral words: %d\n", neutralWords);
}

int main()
{
  Word *head = NULL;

  insertWord(head, "happy");
  insertWord(head, "sad");
  insertWord(head, "neutral");
  insertWord(head, "positive");
  insertWord(head, "negative");

  analyzeSentiment(head);

  return 0;
}