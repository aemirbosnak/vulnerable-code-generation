//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: decentralized
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

Book* searchBook(Book* head, char* title) {
  while (head) {
    if (strcmp(head->title, title) == 0) {
      return head;
    }
    head = head->next;
  }
  return NULL;
}

Book* deleteBook(Book* head, char* title) {
  Book* previous = NULL;
  Book* current = head;

  while (current) {
    if (strcmp(current->title, title) == 0) {
      if (previous) {
        previous->next = current->next;
      } else {
        head = current->next;
      }
      free(current);
      return head;
    }
    previous = current;
    current = current->next;
  }

  return NULL;
}

int main() {
  Book* head = NULL;

  // Insert books
  Book* newBook1 = malloc(sizeof(Book));
  strcpy(newBook1->title, "The Lord of the Flies");
  strcpy(newBook1->author, "William Golding");
  newBook1->quantity = 5;
  insertBook(head, newBook1);

  Book* newBook2 = malloc(sizeof(Book));
  strcpy(newBook2->title, "To Kill a Mockingbird");
  strcpy(newBook2->author, "Harper Lee");
  newBook2->quantity = 3;
  insertBook(head, newBook2);

  // Search for book
  Book* foundBook = searchBook(head, "The Lord of the Flies");
  if (foundBook) {
    printf("Found book: %s by %s\n", foundBook->title, foundBook->author);
  }

  // Delete book
  deleteBook(head, "To Kill a Mockingbird");
  foundBook = searchBook(head, "To Kill a Mockingbird");
  if (foundBook) {
    printf("Book deleted: %s by %s\n", foundBook->title, foundBook->author);
  }

  return 0;
}