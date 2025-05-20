//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10

struct Book {
  char title[50];
  char author[50];
  int quantity;
  struct Book* next;
};

struct Book* insertBook(struct Book* head, char* title, char* author, int quantity) {
  struct Book* newBook = malloc(sizeof(struct Book));
  strcpy(newBook->title, title);
  strcpy(newBook->author, author);
  newBook->quantity = quantity;
  newBook->next = NULL;

  if (head == NULL) {
    return newBook;
  } else {
    head->next = newBook;
  }

  return head;
}

struct Book* findBook(struct Book* head, char* title) {
  struct Book* currentBook = head;

  while (currentBook) {
    if (strcmp(currentBook->title, title) == 0) {
      return currentBook;
    }
    currentBook = currentBook->next;
  }

  return NULL;
}

int main() {
  struct Book* library = NULL;
  library = insertBook(library, "The Lord of the Flies", "William Golding", 5);
  library = insertBook(library, "The Great Gatsby", "F. Scott Fitzgerald", 10);
  library = insertBook(library, "To Kill a Mockingbird", "Harper Lee", 7);

  struct Book* foundBook = findBook(library, "The Great Gatsby");

  if (foundBook) {
    printf("Found book: %s by %s, quantity: %d\n", foundBook->title, foundBook->author, foundBook->quantity);
  } else {
    printf("Book not found\n");
  }

  return 0;
}