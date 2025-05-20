//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
  char *name;
  char *number;
  struct contact *next;
} contact;

contact *create_contact(char *name, char *number) {
  contact *new_contact = malloc(sizeof(contact));
  new_contact->name = strdup(name);
  new_contact->number = strdup(number);
  new_contact->next = NULL;
  return new_contact;
}

void print_contact(contact *contact) {
  printf("%s: %s\n", contact->name, contact->number);
}

void print_phone_book(contact *phone_book) {
  if (phone_book == NULL) {
    printf("Phone book is empty.\n");
    return;
  }

  print_contact(phone_book);
  print_phone_book(phone_book->next);
}

void add_contact(contact **phone_book, char *name, char *number) {
  if (*phone_book == NULL) {
    *phone_book = create_contact(name, number);
    return;
  }

  add_contact(&(*phone_book)->next, name, number);
}

void delete_contact(contact **phone_book, char *name) {
  if (*phone_book == NULL) {
    return;
  }

  if (strcmp((*phone_book)->name, name) == 0) {
    contact *next_contact = (*phone_book)->next;
    free((*phone_book)->name);
    free((*phone_book)->number);
    free(*phone_book);
    *phone_book = next_contact;
    return;
  }

  delete_contact(&(*phone_book)->next, name);
}

int main() {
  contact *phone_book = NULL;

  add_contact(&phone_book, "John Doe", "555-1234");
  add_contact(&phone_book, "Jane Smith", "555-5678");
  add_contact(&phone_book, "Bob Jones", "555-9876");

  print_phone_book(phone_book);

  delete_contact(&phone_book, "Jane Smith");

  print_phone_book(phone_book);

  return 0;
}