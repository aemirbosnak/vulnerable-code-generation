//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
  char *name;
  char *email;
  struct list *next;
};

struct list *head = NULL;

void add(char *name, char *email) {
  struct list *new = malloc(sizeof(struct list));
  new->name = malloc(strlen(name) + 1);
  strcpy(new->name, name);
  new->email = malloc(strlen(email) + 1);
  strcpy(new->email, email);
  new->next = head;
  head = new;
}

void delete(char *name) {
  struct list *prev = NULL;
  struct list *curr = head;
  while (curr != NULL) {
    if (strcmp(curr->name, name) == 0) {
      if (prev == NULL) {
        head = curr->next;
      } else {
        prev->next = curr->next;
      }
      free(curr->name);
      free(curr->email);
      free(curr);
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}

void print() {
  struct list *curr = head;
  while (curr != NULL) {
    printf("%s <%s>\n", curr->name, curr->email);
    curr = curr->next;
  }
}

int main() {
  add("John", "john@example.com");
  add("Mary", "mary@example.com");
  add("Tom", "tom@example.com");
  print();
  delete("John");
  print();
  return 0;
}