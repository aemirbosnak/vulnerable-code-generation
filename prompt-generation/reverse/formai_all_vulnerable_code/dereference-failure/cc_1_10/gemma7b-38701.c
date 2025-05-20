//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ENTRIES 10

typedef struct Entry {
  char name[20];
  int age;
  struct Entry* next;
} Entry;

Entry* getRandomEntry(Entry* head) {
  if (head == NULL) {
    return NULL;
  }

  srand(time(NULL));
  int rand_index = rand() % NUM_ENTRIES;

  Entry* current = head;
  for (int i = 0; i < rand_index; i++) {
    current = current->next;
  }

  return current;
}

void printEntry(Entry* entry) {
  printf("Name: %s, Age: %d\n", entry->name, entry->age);
}

int main() {
  Entry* head = NULL;
  for (int i = 0; i < NUM_ENTRIES; i++) {
    Entry* newEntry = malloc(sizeof(Entry));
    strcpy(newEntry->name, "Entry #");
    newEntry->age = rand() % 100;

    if (head == NULL) {
      head = newEntry;
    } else {
      newEntry->next = head;
      head = newEntry;
    }
  }

  Entry* entry = getRandomEntry(head);
  printEntry(entry);

  return 0;
}