//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: mind-bending
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *createWord(char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;
  return newWord;
}

void insertWord(Word *head, char *word) {
  Word *newWord = createWord(word);
  if (head == NULL) {
    head = newWord;
  } else {
    head->next = newWord;
  }
  head = newWord;
}

int spellCheck(Word *head, char *word) {
  Word *currentWord = head;
  while (currentWord) {
    if (strcmp(currentWord->word, word) == 0) {
      return 1;
    }
    currentWord = currentWord->next;
  }
  return 0;
}

int main() {
  Word *head = NULL;
  insertWord(head, "apple");
  insertWord(head, "banana");
  insertWord(head, "orange");

  char *wordToSearch = "banana";

  if (spellCheck(head, wordToSearch)) {
    printf("Word found: %s\n", wordToSearch);
  } else {
    printf("Word not found: %s\n", wordToSearch);
  }

  return 0;
}