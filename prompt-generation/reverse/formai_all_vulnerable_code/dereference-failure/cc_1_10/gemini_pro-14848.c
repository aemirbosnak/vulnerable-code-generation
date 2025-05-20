//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Cryptic
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char *name;
  char *number;
  struct Node *next;
} Node;

typedef struct Phonebook {
  struct Node *head;
  struct Node *tail;
  int size;
} Phonebook;

Phonebook *init() {
  Phonebook *pb = malloc(sizeof(Phonebook));
  pb->head = NULL;
  pb->tail = NULL;
  pb->size = 0;
  return pb;
}

void add(Phonebook *pb, char *name, char *number) {
  Node *new = malloc(sizeof(Node));
  new->name = strdup(name);
  new->number = strdup(number);
  new->next = NULL;
  if (pb->size == 0) {
    pb->head = new;
    pb->tail = new;
  } else {
    pb->tail->next = new;
    pb->tail = new;
  }
  pb->size++;
}

Node *find(Phonebook *pb, char *name) {
  Node *current = pb->head;
  while (current != NULL) {
    if (strcmp(current->name, name) == 0) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void print_phonebook(Phonebook *pb) {
  Node *current = pb->head;
  while (current != NULL) {
    printf("%s: %s\n", current->name, current->number);
    current = current->next;
  }
}

void destroy_phonebook(Phonebook *pb) {
  Node *current = pb->head;
  while (current != NULL) {
    Node *next = current->next;
    free(current->name);
    free(current->number);
    free(current);
    current = next;
  }
  free(pb);
}

int main() {
  Phonebook *pb = init();
  add(pb, "Alice", "555-1212");
  add(pb, "Bob", "555-1213");
  add(pb, "Carol", "555-1214");
  print_phonebook(pb);
  Node *found = find(pb, "Bob");
  if (found != NULL) {
    printf("Found Bob: %s\n", found->number);
  }
  destroy_phonebook(pb);
  return 0;
}