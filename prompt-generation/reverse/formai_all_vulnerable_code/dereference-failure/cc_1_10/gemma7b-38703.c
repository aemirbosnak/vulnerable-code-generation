//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define WORDS_PER_PAGE 20

typedef struct Word {
  char word[20];
  struct Word* next;
} Word;

Word* insertWord(Word* head, char* word) {
  Word* newWord = (Word*)malloc(sizeof(Word));
  strcpy(newWord->word, word);
  newWord->next = head;
  return newWord;
}

void printWords(Word* head) {
  Word* currentWord = head;
  while (currentWord) {
    printf("%s ", currentWord->word);
    currentWord = currentWord->next;
  }
  printf("\n");
}

int main() {
  time_t start, end;
  Word* head = NULL;

  // Insert some words into the list
  insertWord(head, "Claude");
  insertWord(head, "Shannon");
  insertWord(head, "Information");
  insertWord(head, "Theory");
  insertWord(head, "Entropy");

  // Start the timer
  start = time(NULL);

  // Print the words
  printWords(head);

  // End the timer
  end = time(NULL);

  // Calculate the time taken
  int timeTaken = end - start;

  // Print the time taken
  printf("Time taken: %d seconds\n", timeTaken);

  return 0;
}