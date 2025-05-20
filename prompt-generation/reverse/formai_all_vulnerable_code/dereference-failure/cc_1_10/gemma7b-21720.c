//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 1024

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *word_insert(Word *head, char *word) {
  Word *new_word = malloc(sizeof(Word));
  new_word->word = strdup(word);
  new_word->next = NULL;

  if (head == NULL) {
    head = new_word;
  } else {
    head->next = new_word;
  }

  return head;
}

int word_count(Word *head) {
  int count = 0;
  Word *current = head;

  while (current) {
    count++;
    current = current->next;
  }

  return count;
}

int main() {
  Word *head = NULL;
  char *words[] = {"apple", "banana", "cherry", "orange", "peach"};

  for (int i = 0; i < 5; i++) {
    head = word_insert(head, words[i]);
  }

  int num_words = word_count(head);

  printf("Number of words: %d\n", num_words);

  return 0;
}