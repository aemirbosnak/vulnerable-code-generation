//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ENTRIES 20
#define MAX_WORD_LENGTH 25

typedef struct Entry {
  char **words;
  int num_words;
  struct Entry *next;
} Entry;

Entry *head = NULL;

void addEntry(char **words, int num_words) {
  Entry *newEntry = malloc(sizeof(Entry));
  newEntry->words = malloc(sizeof(char *) * num_words);
  newEntry->num_words = num_words;
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    Entry *currEntry = head;
    while (currEntry->next) {
      currEntry = currEntry->next;
    }
    currEntry->next = newEntry;
  }
}

void generateConspiracyTheory() {
  char **keywords = malloc(sizeof(char *) * MAX_WORD_LENGTH);
  keywords[0] = "secret";
  keywords[1] = "hidden";
  keywords[2] = "forbidden";
  keywords[3] = "suspicious";
  keywords[4] = "manipulated";

  int numKeywords = 5;

  for (int i = 0; i < NUM_ENTRIES; i++) {
    addEntry(keywords, numKeywords);
  }

  time_t t = time(NULL);
  srand(t);

  Entry *currEntry = head;
  int entryIndex = rand() % NUM_ENTRIES;
  Entry *targetEntry = currEntry->words[entryIndex];

  printf("Conspiracy Theory:**\n\n");
  printf("The keyword '%s' is hidden in the following entry:\n\n", targetEntry->words[0]);
  printf("Title: %s\n", targetEntry->words[1]);
  printf("Content: %s\n\n", targetEntry->words[2]);
  printf("This entry was added to the database on: %s", targetEntry->words[3]);
}

int main() {
  generateConspiracyTheory();

  return 0;
}