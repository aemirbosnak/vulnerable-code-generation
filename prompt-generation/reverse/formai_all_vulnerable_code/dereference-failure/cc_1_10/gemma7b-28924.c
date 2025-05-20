//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 20

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (head == NULL) {
    return newWord;
  }

  head->next = insertWord(head->next, word);
  return head;
}

void translate(Word *head) {
  char **words = malloc(MAX_WORDS * MAX_WORD_LENGTH);

  int i = 0;
  for (Word *word = head; word; word = word->next) {
    words[i++] = word->word;
  }

  for (i = 0; words[i]; i++) {
    printf("%s ", words[i]);
  }

  printf("\n");
  free(words);
}

int main() {
  Word *head = insertWord(NULL, "cat");
  insertWord(head, "hat");
  insertWord(head, "mat");
  insertWord(head, "sat");

  translate(head);

  return 0;
}