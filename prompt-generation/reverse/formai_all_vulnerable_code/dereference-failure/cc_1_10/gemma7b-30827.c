//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

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
    head->next = insertWord(head->next, word);
  }

  return head;
}

int main() {
  Word *words = NULL;
  char *sentence = "This is a sample sentence with many words, some of which are spam.";

  // Insert words into the list
  words = insertWord(words, "sample");
  words = insertWord(words, "sentence");
  words = insertWord(words, "many");
  words = insertWord(words, "words");
  words = insertWord(words, "some");
  words = insertWord(words, "spam");

  // Check if the word "spam" is in the list
  if (searchWord(words, "spam")) {
    printf("The word 'spam' is in the list.\n");
  } else {
    printf("The word 'spam' is not in the list.\n");
  }

  return 0;
}

int searchWord(Word *head, char *word) {
  while (head) {
    if (strcmp(head->word, word) == 0) {
      return 1;
    } else {
      head = head->next;
    }
  }

  return 0;
}