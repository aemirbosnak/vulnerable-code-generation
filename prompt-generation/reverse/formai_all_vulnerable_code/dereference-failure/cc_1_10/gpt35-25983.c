//FormAI DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
// Donald Knuth style C Phone Book Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Entry {
  char *first_name;
  char *last_name;
  char *phone_number;
  struct Entry *next;
};

struct PhoneBook {
  struct Entry *head;
};

void add_entry(struct PhoneBook *book, char *first, char *last, char *phone) {
  struct Entry *new_entry = malloc(sizeof(struct Entry));
  new_entry->first_name = malloc(strlen(first) + 1);
  new_entry->last_name = malloc(strlen(last) + 1);
  new_entry->phone_number = malloc(strlen(phone) + 1);

  strcpy(new_entry->first_name, first);
  strcpy(new_entry->last_name, last);
  strcpy(new_entry->phone_number, phone);

  new_entry->next = book->head;
  book->head = new_entry;
}

void print_phone_book(struct PhoneBook *book) {
  printf("Phone Book:\n");
  struct Entry *current = book->head;
  while (current != NULL) {
    printf("%s %s: %s\n", current->first_name, current->last_name, current->phone_number);
    current = current->next;
  }
}

int main() {
  struct PhoneBook mainBook = {NULL};
  printf("Adding entries to phone book...\n");

  add_entry(&mainBook, "Donald", "Knuth", "555-1234");
  add_entry(&mainBook, "Ada", "Lovelace", "555-5678");
  add_entry(&mainBook, "Grace", "Hopper", "555-9876");

  print_phone_book(&mainBook);
  
  return 0;
}