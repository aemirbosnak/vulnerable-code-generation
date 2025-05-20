//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: scalable
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

int detectSpam(char *text) {
  Word *words = insertWord(NULL, "spam");
  words = insertWord(words, "free");
  words = insertWord(words, "lottery");
  words = insertWord(words, "prize");

  for (Word *word = words; word; word = word->next) {
    if (strstr(text, word->word) != NULL) {
      return 1;
    }
  }

  return 0;
}

int main() {
  char *text = "I won a lottery!";
  int isSpam = detectSpam(text);

  if (isSpam) {
    printf("Text is spam!");
  } else {
    printf("Text is not spam!");
  }

  return 0;
}