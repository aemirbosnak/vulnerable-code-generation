//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1024

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *addWord(Word *head, char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (head) {
    head->next = newWord;
  } else {
    head = newWord;
  }

  return head;
}

int isSpam(char *text) {
  Word *head = NULL;
  char *words = strtok(text, " ");

  while (words) {
    addWord(head, words);
    words = strtok(NULL, " ");
  }

  for (Word *word = head; word; word = word->next) {
    if (strcmp(word->word, "lottery") == 0 ||
        strcmp(word->word, "miracle") == 0 ||
        strcmp(word->word, "prize") == 0) {
      return 1;
    }
  }

  return 0;
}

int main() {
  char *text = "You have won $10 million!";
  int isSpamResult = isSpam(text);

  if (isSpamResult) {
    printf("Spam detected!\n");
  } else {
    printf("No spam detected.\n");
  }

  return 0;
}