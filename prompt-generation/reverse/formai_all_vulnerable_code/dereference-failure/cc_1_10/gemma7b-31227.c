//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: innovative
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

Book* insertBook(Book* head, Book* newBook);
Book* findBook(Book* head, char* title);
void updateBookQuantity(Book* head, char* title, int quantity);

int main() {
  Book* head = NULL;
  Book* newBook;

  // Inserting books into the library
  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "The Lord of the Flies");
  strcpy(newBook->author, "William Golding");
  newBook->quantity = 10;
  head = insertBook(head, newBook);

  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "To Kill a Mockingbird");
  strcpy(newBook->author, "Harper Lee");
  newBook->quantity = 15;
  insertBook(head, newBook);

  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "The Great Gatsby");
  strcpy(newBook->author, "F. Scott Fitzgerald");
  newBook->quantity = 20;
  insertBook(head, newBook);

  // Finding a book in the library
  Book* foundBook = findBook(head, "To Kill a Mockingbird");
  if (foundBook) {
    printf("Found book: %s by %s, quantity: %d\n", foundBook->title, foundBook->author, foundBook->quantity);
  } else {
    printf("Book not found.\n");
  }

  // Updating book quantity
  updateBookQuantity(head, "The Lord of the Flies", 12);
  foundBook = findBook(head, "The Lord of the Flies");
  if (foundBook) {
    printf("Updated book quantity: %d\n", foundBook->quantity);
  } else {
    printf("Book not found.\n");
  }

  return 0;
}

Book* insertBook(Book* head, Book* newBook) {
  if (head == NULL) {
    head = newBook;
  } else {
    newBook->next = head;
    head = newBook;
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

void updateBookQuantity(Book* head, char* title, int quantity) {
  Book* foundBook = findBook(head, title);
  if (foundBook) {
    foundBook->quantity = quantity;
  }
}