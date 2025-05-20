//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: scalable
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

Book* findBook(Book* head, char* title) {
  Book* currentBook = head;
  while (currentBook) {
    if (strcmp(currentBook->title, title) == 0) {
      return currentBook;
    }
    currentBook = currentBook->next;
  }
  return NULL;
}

void updateQuantity(Book* book, int quantity) {
  book->quantity = quantity;
}

void printBooks(Book* head) {
  Book* currentBook = head;
  while (currentBook) {
    printf("%s by %s, quantity: %d\n", currentBook->title, currentBook->author, currentBook->quantity);
    currentBook = currentBook->next;
  }
}

int main() {
  Book* head = NULL;
  Book* newBook = malloc(sizeof(Book));

  strcpy(newBook->title, "The Lord of the Flies");
  strcpy(newBook->author, "William Golding");
  newBook->quantity = 5;

  head = insertBook(head, newBook);

  newBook = malloc(sizeof(Book));

  strcpy(newBook->title, "To Kill a Mockingbird");
  strcpy(newBook->author, "Harper Lee");
  newBook->quantity = 10;

  head = insertBook(head, newBook);

  printBooks(head);

  newBook = findBook(head, "The Lord of the Flies");

  if (newBook) {
    updateQuantity(newBook, 10);
  }

  printBooks(head);

  return 0;
}