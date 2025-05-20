//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

int main() {
  Word *head = NULL;
  char **words = NULL;
  int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

  words = malloc(MAX_WORDS * sizeof(char *));

  for (i = 0; i < MAX_WORDS; i++) {
    words[i] = NULL;
  }

  // Insert words into the list
  insertWord(head, "spam");
  insertWord(head, "eggs");
  insertWord(head, "bacon");
  insertWord(head, "ham");
  insertWord(head, "toast");
  insertWord(head, "butter");
  insertWord(head, "jam");
  insertWord(head, "jelly");
  insertWord(head, "bread");

  // Detect spam
  for (i = 0; i < MAX_WORDS; i++) {
    if (words[i] != NULL && strcmp(words[i], "spam") == 0) {
      printf("Word: %s is spam\n", words[i]);
    }
  }

  return 0;
}