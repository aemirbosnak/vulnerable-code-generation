//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10

typedef struct AlienWord {
  char alienWord[20];
  char englishWord[20];
  struct AlienWord* next;
} AlienWord;

AlienWord* insertWord(AlienWord* head, char* alienWord, char* englishWord) {
  AlienWord* newNode = malloc(sizeof(AlienWord));
  strcpy(newNode->alienWord, alienWord);
  strcpy(newNode->englishWord, englishWord);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int translateWord(AlienWord* head, char* alienWord) {
  AlienWord* currentWord = head;

  while (currentWord) {
    if (strcmp(currentWord->alienWord, alienWord) == 0) {
      return currentWord->englishWord;
    }
    currentWord = currentWord->next;
  }

  return "Not found";
}

int main() {
  AlienWord* head = NULL;

  insertWord(head, "Xylotron", "Rocket");
  insertWord(head, "Zaphod", "Airplane");
  insertWord(head, "Thrumbo", "Car");

  char* alienWord = "Xylotron";
  char* translation = translateWord(head, alienWord);

  printf("%s translates to %s\n", alienWord, translation);

  return 0;
}