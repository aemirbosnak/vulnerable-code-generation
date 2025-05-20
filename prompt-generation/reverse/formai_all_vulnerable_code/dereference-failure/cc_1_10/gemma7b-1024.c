//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

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
  Word *head = NULL;

  // Insert words into the list
  insertWord(head, "The");
  insertWord(head, "quick");
  insertWord(head, "brown");
  insertWord(head, "fox");
  insertWord(head, "jumps");
  insertWord(head, "over");
  insertWord(head, "the");
  insertWord(head, "lazy");

  // Spam detection
  char *suspectText = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

  int wordsFound = 0;
  Word *currentWord = head;

  while (currentWord) {
    if (strstr(suspectText, currentWord->word) != NULL) {
      wordsFound++;
    }
    currentWord = currentWord->next;
  }

  // Print the number of words found
  printf("Number of words found: %d", wordsFound);

  return 0;
}