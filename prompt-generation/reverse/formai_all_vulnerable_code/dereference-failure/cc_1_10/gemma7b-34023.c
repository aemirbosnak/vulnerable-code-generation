//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 255

typedef struct CatWord {
  char word[MAX_WORD_LENGTH];
  struct CatWord* next;
} CatWord;

CatWord* insertWord(CatWord* head, char* word) {
  CatWord* newNode = malloc(sizeof(CatWord));
  strcpy(newNode->word, word);
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  head->next = insertWord(head->next, word);
  return head;
}

int translateCat(CatWord* head, char* query) {
  char* words = strtok(query, " ");
  int i = 0;

  while (words[i] != NULL) {
    char* word = words[i];

    for (CatWord* currentWord = head; currentWord != NULL; currentWord = currentWord->next) {
      if (strcmp(word, currentWord->word) == 0) {
        printf("%s ", currentWord->word);
      }
    }

    i++;
  }

  return 0;
}

int main() {
  CatWord* head = NULL;

  insertWord(head, "Meow");
  insertWord(head, "Purr");
  insertWord(head, "Meow");
  insertWord(head, "Meow");
  insertWord(head, "Snuggle");

  translateCat(head, "Can you tell me where the meow is?");

  return 0;
}