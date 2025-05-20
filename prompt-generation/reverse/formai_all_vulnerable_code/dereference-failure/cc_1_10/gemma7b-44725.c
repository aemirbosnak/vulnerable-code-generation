//Gemma-7B DATASET v1.0 Category: Checksum Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 101

typedef struct HashEntry {
  char *key;
  int value;
  struct HashEntry *next;
} HashEntry;

HashEntry *insert(HashEntry *head, char *key, int value) {
  HashEntry *newEntry = malloc(sizeof(HashEntry));
  newEntry->key = strdup(key);
  newEntry->value = value;
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    HashEntry *prev = head;
    HashEntry *curr = head->next;
    while (curr) {
      if (strcmp(key, curr->key) == 0) {
        curr->value = value;
        return head;
      } else if (strcmp(key, prev->key) > 0) {
        prev->next = newEntry;
        return head;
      }
      prev = curr;
      curr = curr->next;
    }
    prev->next = newEntry;
  }

  return head;
}

int calculateChecksum(char *str) {
  HashEntry *head = NULL;
  char *p = str;
  int checksum = 0;

  while (*p) {
    insert(head, p, (*p) * HASH_SIZE);
    p++;
  }

  for (HashEntry *curr = head; curr; curr = curr->next) {
    checksum += curr->value;
  }

  return checksum;
}

int main() {
  char *str = "Donald Knuth is a brilliant computer scientist.";
  int checksum = calculateChecksum(str);

  printf("Checksum: %d\n", checksum);

  return 0;
}