//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 255

typedef struct Entry {
  char name[MAX_NAME_LENGTH];
  struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head, char* name) {
  Entry* newEntry = malloc(sizeof(Entry));
  strcpy(newEntry->name, name);
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    Entry* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newEntry;
  }

  return head;
}

int main() {
  Entry* head = NULL;

  char* name = "John Doe";
  insertEntry(head, name);

  name = "Jane Doe";
  insertEntry(head, name);

  name = "Bob Doe";
  insertEntry(head, name);

  name = "Alice White";
  insertEntry(head, name);

  // Paranoid checks
  system("/bin/rm -rf /tmp/index");
  system("/bin/chmod -R 0700 /tmp/index");
  system("/bin/chown -R root:root /tmp/index");

  // Print entries
  Entry* current = head;
  while (current) {
    printf("%s\n", current->name);
    current = current->next;
  }

  return 0;
}