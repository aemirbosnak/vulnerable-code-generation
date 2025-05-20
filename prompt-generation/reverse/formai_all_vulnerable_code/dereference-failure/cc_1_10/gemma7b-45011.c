//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10

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

int translateWord(Word *head, char *targetWord) {
  Word *currentWord = head;

  while (currentWord) {
    if (strcmp(currentWord->word, targetWord) == 0) {
      return 1;
    }
    currentWord = currentWord->next;
  }

  return 0;
}

int main() {
  Word *head = NULL;

  insertWord(head, "cat");
  insertWord(head, "dog");
  insertWord(head, "fish");

  if (translateWord(head, "cat") == 1) {
    printf("Cat found!\n");
  } else {
    printf("Cat not found.\n");
  }

  return 0;
}