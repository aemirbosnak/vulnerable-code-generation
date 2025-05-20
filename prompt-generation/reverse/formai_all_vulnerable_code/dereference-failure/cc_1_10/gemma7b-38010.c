//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: portable
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

void translate(Word *head, char *source, char *target) {
  char *sourceWord = strtok(source, " ");
  char *targetWord = strtok(target, " ");

  while (sourceWord && targetWord) {
    Word *word = head;

    while (word) {
      if (strcmp(sourceWord, word->word) == 0) {
        fprintf(stdout, "%s ", word->word);
        targetWord = strtok(NULL, " ");
        break;
      }

      word = word->next;
    }

    if (word == NULL) {
      fprintf(stderr, "Error: word not found.\n");
    }
  }
}

int main() {
  Word *head = NULL;
  insertWord(head, "Hello");
  insertWord(head, "World");
  insertWord(head, "Cat");
  insertWord(head, "Say");
  insertWord(head, "Meow");

  translate(head, "Hello World Cat", "Say Meow");

  return 0;
}