//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct CAT_WORD {
  char *word;
  struct CAT_WORD *next;
} CatWord;

CatWord *insertWord(CatWord *head, char *word) {
  CatWord *newWord = malloc(sizeof(CatWord));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (head == NULL) {
    head = newWord;
  } else {
    head->next = insertWord(head->next, word);
  }

  return head;
}

int translateCcat(char *sentence) {
  CatWord *head = NULL;
  char *word = strtok(sentence, " ");

  while (word) {
    insertWord(head, word);
    word = strtok(NULL, " ");
  }

  int i = 0;
  int translatedWordCount = 0;
  for (CatWord *wordIter = head; wordIter; wordIter++) {
    switch (wordIter->word[0]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        translatedWordCount++;
    }
  }

  return translatedWordCount;
}

int main() {
  char *sentence = "The quick brown fox jumps over the lazy dog.";
  int translatedWordCount = translateCcat(sentence);

  printf("Number of translated words: %d\n", translatedWordCount);

  return 0;
}