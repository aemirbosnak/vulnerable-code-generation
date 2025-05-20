//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

typedef struct Word {
  char *word;
  int frequency;
  struct Word *next;
} Word;

Word *createWord(char *word, int frequency) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->frequency = frequency;
  newWord->next = NULL;
  return newWord;
}

void addWord(Word *head, char *word, int frequency) {
  Word *newWord = createWord(word, frequency);
  if (head == NULL) {
    head = newWord;
  } else {
    Word *currentWord = head;
    while (currentWord->next) {
      currentWord = currentWord->next;
    }
    currentWord->next = newWord;
  }
}

void printWords(Word *head) {
  Word *currentWord = head;
  while (currentWord) {
    printf("%s (%d) ", currentWord->word, currentWord->frequency);
    currentWord = currentWord->next;
  }
  printf("\n");
}

int main() {
  Word *head = NULL;

  char sentence[] = "The quick brown fox jumps over the lazy dog.";

  // Tokenize the sentence
  char *words = strtok(sentence, " ");

  // Add each word to the dictionary
  while (words) {
    addWord(head, words, 1);
    words = strtok(NULL, " ");
  }

  // Print the words in the dictionary
  printWords(head);

  return 0;
}