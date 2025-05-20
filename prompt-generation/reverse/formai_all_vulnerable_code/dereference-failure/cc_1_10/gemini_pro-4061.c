//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entry {
  char *title;
  char *body;
  struct entry *next;
} entry_t;

entry_t *head = NULL;

void add_entry(char *title, char *body) {
  entry_t *new_entry = malloc(sizeof(entry_t));
  new_entry->title = strdup(title);
  new_entry->body = strdup(body);
  new_entry->next = head;
  head = new_entry;
}

void print_entry(entry_t *entry) {
  printf("** %s **\n", entry->title);
  printf("%s\n", entry->body);
  printf("\n");
}

void print_all_entries() {
  entry_t *current = head;
  while (current != NULL) {
    print_entry(current);
    current = current->next;
  }
}

void delete_entry(char *title) {
  entry_t *current = head;
  entry_t *previous = NULL;
  while (current != NULL) {
    if (strcmp(current->title, title) == 0) {
      if (previous == NULL) {
        head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current->title);
      free(current->body);
      free(current);
      break;
    }
    previous = current;
    current = current->next;
  }
}

int main() {
  add_entry("First Entry", "This is my first entry!");
  add_entry("Second Entry", "This is my second entry!");
  add_entry("Third Entry", "This is my third entry!");

  print_all_entries();

  delete_entry("Second Entry");

  print_all_entries();

  return 0;
}