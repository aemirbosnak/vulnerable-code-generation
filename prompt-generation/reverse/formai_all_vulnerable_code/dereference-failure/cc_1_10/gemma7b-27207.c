//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
  Word *newNode = malloc(sizeof(Word));
  newNode->word = strdup(word);
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  head->next = insertWord(head->next, word);
  return head;
}

int detectSpam(Word *words) {
  char *suspiciousWords[] = {"free", "lottery", "miracle", "prize", "miracle"};
  int i;

  for (i = 0; i < MAX_WORDS; i++) {
    if (words->word != NULL && strstr(words->word, suspiciousWords[i]) != NULL) {
      return 1;
    }
    words = words->next;
  }

  return 0;
}

int main() {
  Word *words = NULL;
  insertWord(words, "This email is spam!");
  insertWord(words, "Free lottery!");
  insertWord(words, "Miracle prize!");
  insertWord(words, "This email is not spam!");

  if (detectSpam(words) == 1) {
    printf("Email is spam.\n");
  } else {
    printf("Email is not spam.\n");
  }

  return 0;
}