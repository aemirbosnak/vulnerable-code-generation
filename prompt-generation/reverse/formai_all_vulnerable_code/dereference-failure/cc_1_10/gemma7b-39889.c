//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
  char *word;
  int count;
  struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->count = 1;
  newWord->next = NULL;

  if (head == NULL) {
    head = newWord;
  } else {
    Word *current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newWord;
  }

  return head;
}

void countWords(Word *head) {
  Word *current = head;
  while (current) {
    current->count++;
    current = current->next;
  }
}

int main() {
  Word *head = NULL;

  insertWord(head, "Knuth");
  insertWord(head, "Morris");
  insertWord(head, "Tezuka");
  insertWord(head, "Knuth");

  countWords(head);

  Word *current = head;
  while (current) {
    printf("%s: %d\n", current->word, current->count);
    current = current->next;
  }

  return 0;
}