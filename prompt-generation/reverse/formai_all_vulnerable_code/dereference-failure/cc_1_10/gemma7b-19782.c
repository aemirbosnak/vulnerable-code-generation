//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100

typedef struct ListEntry {
  char name[255];
  struct ListEntry* next;
} ListEntry;

typedef struct ListManager {
  ListEntry** lists;
  int numLists;
  int nextListIndex;
} ListManager;

ListManager* lm_init(int numLists) {
  ListManager* lm = malloc(sizeof(ListManager));
  lm->lists = malloc(numLists * sizeof(ListEntry*));
  lm->numLists = numLists;
  lm->nextListIndex = 0;

  return lm;
}

void lm_addEntry(ListManager* lm, char* name) {
  ListEntry* newEntry = malloc(sizeof(ListEntry));
  strcpy(newEntry->name, name);
  newEntry->next = lm->lists[lm->nextListIndex]->next;
  lm->lists[lm->nextListIndex]->next = newEntry;
  lm->nextListIndex++;
}

void lm_printLists(ListManager* lm) {
  for (int i = 0; i < lm->numLists; i++) {
    ListEntry* currentEntry = lm->lists[i]->next;
    printf("List %d:\n", i + 1);
    while (currentEntry) {
      printf("  %s\n", currentEntry->name);
      currentEntry = currentEntry->next;
    }
  }
}

int main() {
  ListManager* lm = lm_init(3);
  lm_addEntry(lm, "John Doe");
  lm_addEntry(lm, "Jane Doe");
  lm_addEntry(lm, "Peter Pan");
  lm_printLists(lm);

  free(lm->lists);
  free(lm);

  return 0;
}