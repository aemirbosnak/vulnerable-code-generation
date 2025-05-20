//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *addWord(Word *head, char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (head == NULL) {
    head = newWord;
  } else {
    head->next = addWord(head->next, word);
  }

  return head;
}

int translateC(Word *head, char **translated) {
  int i = 0;
  char *tWord = malloc(MAX_WORDS);

  for (Word *currWord = head; currWord; currWord = currWord->next) {
    tWord[i++] = '\0';
    char *sWord = currWord->word;
    int l = strlen(sWord);
    for (int j = 0; j < l; j++) {
      if (sWord[j] == 'a') {
        tWord[i++] = 'a';
      } else if (sWord[j] == 'e') {
        tWord[i++] = 'e';
      } else if (sWord[j] == 'i') {
        tWord[i++] = 'i';
      } else if (sWord[j] == 'o') {
        tWord[i++] = 'o';
      } else if (sWord[j] == 'u') {
        tWord[i++] = 'u';
      } else {
        tWord[i++] = sWord[j];
      }
    }
  }

  *translated = tWord;
  return i;
}

int main() {
  Word *head = addWord(NULL, "Hello, world!");
  head = addWord(head, "This is a sentence.");
  head = addWord(head, "The quick brown fox jumps over the lazy dog.");

  char *translated = NULL;
  int translatedLength = translateC(head, &translated);

  printf("%s", translated);
  free(translated);

  return 0;
}