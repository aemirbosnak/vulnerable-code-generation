//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 255

typedef struct AlienWord {
  char *word;
  struct AlienWord *next;
} AlienWord;

AlienWord *alienWordCreate(char *word) {
  AlienWord *newWord = malloc(sizeof(AlienWord));
  newWord->word = strdup(word);
  newWord->next = NULL;
  return newWord;
}

void alienWordAppend(AlienWord *head, char *word) {
  AlienWord *newWord = alienWordCreate(word);
  if (head == NULL) {
    head = newWord;
  } else {
    head->next = newWord;
  }
}

char *alienWordTranslate(AlienWord *head, char *language) {
  char *translatedWord = malloc(MAX_WORD_LENGTH);
  sprintf(translatedWord, "Unknown");

  if (head != NULL) {
    for (AlienWord *word = head; word->next != NULL; word = word->next) {
      if (strcmp(word->word, language) == 0) {
        sprintf(translatedWord, "%s", word->word);
      }
    }
  }

  return translatedWord;
}

int main() {
  AlienWord *head = NULL;
  alienWordAppend(head, "Zaphod");
  alienWordAppend(head, "Beeb");
  alienWordAppend(head, "Tricia");

  char *translatedWord = alienWordTranslate(head, "Beeb");

  printf("%s", translatedWord);

  free(translatedWord);
  return 0;
}