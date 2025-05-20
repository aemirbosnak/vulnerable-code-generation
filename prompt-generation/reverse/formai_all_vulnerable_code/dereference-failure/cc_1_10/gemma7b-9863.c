//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_ENTRIES 100

typedef struct Entry {
  char name[50];
  struct Entry* next;
} Entry;

Entry* head = NULL;

pthread_mutex_t mutex;

void insertEntry(char* name) {
  pthread_mutex_lock(&mutex);

  Entry* newEntry = (Entry*)malloc(sizeof(Entry));
  strcpy(newEntry->name, name);

  if (head == NULL) {
    head = newEntry;
  } else {
    Entry* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newEntry;
  }

  pthread_mutex_unlock(&mutex);
}

int main() {
  pthread_mutex_init(&mutex, NULL);

  insertEntry("John Doe");
  insertEntry("Jane Doe");
  insertEntry("Bill Smith");

  Entry* current = head;
  while (current) {
    printf("%s\n", current->name);
    current = current->next;
  }

  pthread_mutex_destroy(&mutex);

  return 0;
}