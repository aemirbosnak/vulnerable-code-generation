//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ENTRIES 10

typedef struct Entry {
  char name[255];
  int age;
  double balance;
  struct Entry* next;
} Entry;

Entry* generateEntry() {
  Entry* newEntry = malloc(sizeof(Entry));
  newEntry->name[0] = '\0';
  newEntry->age = rand() % 100;
  newEntry->balance = rand() % 1000000;
  newEntry->next = NULL;
  return newEntry;
}

void addToHead(Entry** head, Entry* newEntry) {
  if (*head == NULL) {
    *head = newEntry;
  } else {
    ((*head)->next = newEntry);
    *head = newEntry;
  }
}

void printEntries(Entry* head) {
  while (head) {
    printf("%s, %d, %.2lf\n", head->name, head->age, head->balance);
    head = head->next;
  }
}

int main() {
  srand(time(NULL));

  Entry* head = NULL;

  for (int i = 0; i < NUM_ENTRIES; i++) {
    addToHead(&head, generateEntry());
  }

  printEntries(head);

  return 0;
}