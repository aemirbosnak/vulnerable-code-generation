//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIENS_LANG_MAX_WORDS 1024

typedef struct AlienWord {
  char *word;
  struct AlienWord *next;
} AlienWord;

AlienWord *alienWord_create(char *word) {
  AlienWord *newWord = malloc(sizeof(AlienWord));
  newWord->word = strdup(word);
  newWord->next = NULL;
  return newWord;
}

void alienWord_add(AlienWord *head, char *word) {
  AlienWord *newWord = alienWord_create(word);
  if (head == NULL) {
    head = newWord;
  } else {
    head->next = newWord;
  }
  head = newWord;
}

void alienWord_translate(AlienWord *head, char **translatedWord) {
  *translatedWord = malloc( ALIENS_LANG_MAX_WORDS);
  int i = 0;
  for (AlienWord *word = head; word != NULL; word = word->next) {
    translatedWord[i++] = word->word;
  }
  translatedWord[i] = NULL;
}

int main() {
  AlienWord *head = NULL;
  alienWord_add(head, "Blork");
  alienWord_add(head, "Zork");
  alienWord_add(head, "Korb");
  alienWord_add(head, "Flork");

  char *translatedWord = NULL;
  alienWord_translate(head, &translatedWord);

  printf("Translated words:\n");
  for (int i = 0; translatedWord[i] != NULL; i++) {
    printf("%s ", translatedWord[i]);
  }

  return 0;
}