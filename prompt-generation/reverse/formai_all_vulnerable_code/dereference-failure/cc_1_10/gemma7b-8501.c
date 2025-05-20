//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 25

typedef struct Word {
  char *word;
  int length;
  struct Word *next;
} Word;

Word *insertWord(Word *head, char *word, int length) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = malloc(length * sizeof(char));
  newWord->length = length;
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

int main() {
  Word *head = NULL;

  char *word = "Hello";
  insertWord(head, word, strlen(word));

  word = "World";
  insertWord(head, word, strlen(word));

  word = "This";
  insertWord(head, word, strlen(word));

  word = "Is";
  insertWord(head, word, strlen(word));

  word = "A";
  insertWord(head, word, strlen(word));

  word = "Sentence";
  insertWord(head, word, strlen(word));

  Word *iterator = head;
  while (iterator) {
    printf("%s ", iterator->word);
  }

  printf("\n");

  return 0;
}