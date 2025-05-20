//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WORDS 1000

typedef struct Word {
  char *word;
  int frequency;
  struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->frequency = 1;
  newWord->next = NULL;

  if (head == NULL) {
    head = newWord;
  } else {
    Word *currWord = head;
    while (currWord->next) {
      currWord = currWord->next;
    }
    currWord->next = newWord;
  }

  return head;
}

int calculateSentiment(Word *head) {
  int sentiment = 0;
  Word *currWord = head;
  while (currWord) {
    if (strcmp(currWord->word, "positive") == 0) {
      sentiment++;
    } else if (strcmp(currWord->word, "negative") == 0) {
      sentiment--;
    }
    currWord = currWord->next;
  }

  return sentiment;
}

int main() {
  char *text = "I am happy today. I am sad that I lost my dog.";
  Word *head = insertWord(NULL, text);
  int sentiment = calculateSentiment(head);

  printf("Sentiment: %d\n", sentiment);

  return 0;
}