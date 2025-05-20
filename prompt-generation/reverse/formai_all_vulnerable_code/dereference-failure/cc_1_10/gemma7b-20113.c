//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (head == NULL) {
    return newWord;
  }

  head->next = insertWord(head->next, word);

  return head;
}

void translate(Word *head, char *source) {
  char *translated = malloc(MAX_WORD_LENGTH * 2);
  char *word = strtok(source, " ");

  while (word) {
    Word *searchWord = head;
    char *translatedWord = NULL;

    while (searchWord) {
      if (strcmp(word, searchWord->word) == 0) {
        translatedWord = searchWord->word;
        break;
      }
      searchWord = searchWord->next;
    }

    if (translatedWord) {
      strcat(translated, translatedWord);
      strcat(translated, " ");
    } else {
      strcat(translated, "UNKNOWN ");
    }

    word = strtok(NULL, " ");
  }

  printf("%s\n", translated);
  free(translated);
}

int main() {
  Word *head = insertWord(NULL, "cat");
  insertWord(head, "dog");
  insertWord(head, "fish");

  translate(head, "The cat sat on the mat.");

  return 0;
}