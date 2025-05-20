//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1024

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
    return newWord;
  }

  Word *currWord = head;
  while (currWord->next) {
    currWord = currWord->next;
  }

  currWord->next = newWord;
  return head;
}

int analyzeSentiment(Word *head) {
  int positiveWords = 0;
  int negativeWords = 0;
  int neutralWords = 0;

  for (Word *currWord = head; currWord; currWord = currWord->next) {
    char *word = currWord->word;

    if (strcmp(word, "good") == 0 || strcmp(word, "nice") == 0 || strcmp(word, "excellent") == 0) {
      positiveWords++;
    } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "awful") == 0) {
      negativeWords++;
    } else {
      neutralWords++;
    }
  }

  return (positiveWords - negativeWords) * neutralWords;
}

int main() {
  Word *head = insertWord(NULL, "The");
  insertWord(head, "best");
  insertWord(head, "software");
  insertWord(head, "ever");
  insertWord(head, "written");
  insertWord(head, "bad");
  insertWord(head, "code");
  insertWord(head, "terrible");

  int sentimentScore = analyzeSentiment(head);
  printf("Sentiment score: %d\n", sentimentScore);

  return 0;
}