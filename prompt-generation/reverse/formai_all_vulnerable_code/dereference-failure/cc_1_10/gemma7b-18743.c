//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 20

typedef struct SpamWord {
  char word[20];
  struct SpamWord* next;
} SpamWord;

SpamWord* insertWord(SpamWord* head, char* word) {
  SpamWord* newNode = malloc(sizeof(SpamWord));
  strcpy(newNode->word, word);
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  head->next = newNode;
  return head;
}

int main() {
  SpamWord* head = NULL;
  insertWord(head, "Free!");
  insertWord(head, "Money!");
  insertWord(head, "Lottery!");
  insertWord(head, "Click Here!");
  insertWord(head, "You Won!");

  char* emailText = "You have won $10,000! Click here to claim your prize!";

  int isSpam = 0;
  for (SpamWord* currentWord = head; currentWord != NULL; currentWord) {
    if (strstr(emailText, currentWord->word) != NULL) {
      isSpam = 1;
    }
  }

  if (isSpam) {
    printf("Spam detected!\n");
  } else {
    printf("Not spam.\n");
  }

  return 0;
}