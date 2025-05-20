//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (head == NULL) {
    head = newWord;
  } else {
    head->next = insertWord(head->next, word);
  }

  return head;
}

int isSpam(char *text) {
  Word *head = insertWord(NULL, "free");
  insertWord(head, "lottery");
  insertWord(head, "miracle");
  insertWord(head, "prize");
  insertWord(head, "sweepstakes");

  char *words = strtok(text, " ");

  while (words) {
    if (strcmp(words, head->word) == 0) {
      return 1;
    }
    words = strtok(NULL, " ");
  }

  return 0;
}

int main() {
  char *text = "You have won a lottery! Free prize!";

  if (isSpam(text)) {
    printf("Text is spam!");
  } else {
    printf("Text is not spam!");
  }

  return 0;
}