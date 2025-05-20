//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 256

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (head == NULL) {
    head = newWord;
  } else {
    Word *traverse = head;
    while (traverse->next) {
      traverse = traverse->next;
    }
    traverse->next = newWord;
  }

  return head;
}

int main() {
  Word *head = NULL;
  insertWord(head, "apple");
  insertWord(head, "banana");
  insertWord(head, "cherry");
  insertWord(head, "orange");

  char *wordToSearch = "apricot";

  Word *traverse = head;
  while (traverse) {
    if (strcmp(traverse->word, wordToSearch) == 0) {
      printf("Word found: %s\n", traverse->word);
      break;
    }
    traverse = traverse->next;
  }

  if (traverse == NULL) {
    printf("Word not found: %s\n", wordToSearch);
  }

  return 0;
}