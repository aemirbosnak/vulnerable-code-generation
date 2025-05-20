//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *head = NULL;

void addWord(char *word)
{
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (head == NULL) {
    head = newWord;
  } else {
    head->next = newWord;
  }
}

int translateWord(char *word)
{
  Word *currentWord = head;
  while (currentWord) {
    if (strcmp(currentWord->word, word) == 0) {
      return currentWord->next->word;
    }
    currentWord = currentWord->next;
  }

  return NULL;
}

int main()
{
  addWord("cat");
  addWord("dog");
  addWord("fish");
  addWord("bird");

  char *translatedWord = translateWord("cat");
  if (translatedWord) {
    printf("%s\n", translatedWord);
  } else {
    printf("Word not found.\n");
  }

  return 0;
}