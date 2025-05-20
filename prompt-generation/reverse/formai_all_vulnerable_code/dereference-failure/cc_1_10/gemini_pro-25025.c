//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _phone_entry {
  char *name;
  char *number;
  struct _phone_entry *next;
} phone_entry;

typedef struct _phone_book {
  phone_entry *head;
  phone_entry *tail;
  int size;
} phone_book;

phone_book *create_phone_book() {
  phone_book *book = malloc(sizeof(phone_book));
  if (book == NULL) {
    return NULL;
  }
  book->head = NULL;
  book->tail = NULL;
  book->size = 0;
  return book;
}

bool add_entry(phone_book *book, char *name, char *number) {
  phone_entry *entry = malloc(sizeof(phone_entry));
  if (entry == NULL) {
    return false;
  }
  entry->name = strdup(name);
  entry->number = strdup(number);
  entry->next = NULL;
  if (book->head == NULL) {
    book->head = entry;
    book->tail = entry;
  } else {
    book->tail->next = entry;
    book->tail = entry;
  }
  book->size++;
  return true;
}

char *get_number(phone_book *book, char *name) {
  phone_entry *entry = book->head;
  while (entry != NULL) {
    if (strcmp(entry->name, name) == 0) {
      return entry->number;
    }
    entry = entry->next;
  }
  return NULL;
}

void print_phone_book(phone_book *book) {
  phone_entry *entry = book->head;
  while (entry != NULL) {
    printf("%s: %s\n", entry->name, entry->number);
    entry = entry->next;
  }
}

void free_phone_book(phone_book *book) {
  phone_entry *entry = book->head;
  while (entry != NULL) {
    phone_entry *next = entry->next;
    free(entry->name);
    free(entry->number);
    free(entry);
    entry = next;
  }
  free(book);
}

int main() {
  phone_book *book = create_phone_book();
  add_entry(book, "Alice", "555-1212");
  add_entry(book, "Bob", "555-1213");
  add_entry(book, "Carol", "555-1214");
  print_phone_book(book);
  char *number = get_number(book, "Bob");
  printf("Bob's number: %s\n", number);
  free_phone_book(book);
  return 0;
}