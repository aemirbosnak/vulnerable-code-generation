//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
  char title[50];
  char author[50];
  int quantity;
  struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook) {
  if (head == NULL) {
    head = newBook;
  } else {
    head->next = insertBook(head->next, newBook);
  }
  return head;
}

void printBooks(Book* head) {
  while (head) {
    printf("%s by %s, quantity: %d\n", head->title, head->author, head->quantity);
    head = head->next;
  }
}

int main() {
  Book* head = NULL;
  Book* newBook;

  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "The Lord of the Flies");
  strcpy(newBook->author, "William Golding");
  newBook->quantity = 10;

  insertBook(head, newBook);

  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "The Great Gatsby");
  strcpy(newBook->author, "F. Scott Fitzgerald");
  newBook->quantity = 5;

  insertBook(head, newBook);

  printBooks(head);

  return 0;
}