//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: puzzling
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

void searchBook(Book* head, char* title) {
  while (head) {
    if (strcmp(head->title, title) == 0) {
      printf("Book: %s, Author: %s, Quantity: %d\n", head->title, head->author, head->quantity);
    }
    head = head->next;
  }
}

int main() {
  Book* head = NULL;
  Book* newBook = NULL;

  newBook = (Book*)malloc(sizeof(Book));
  strcpy(newBook->title, "The Lord of the Flies");
  strcpy(newBook->author, "William Golding");
  newBook->quantity = 5;

  insertBook(head, newBook);

  newBook = (Book*)malloc(sizeof(Book));
  strcpy(newBook->title, "To Kill a Mockingbird");
  strcpy(newBook->author, "Harper Lee");
  newBook->quantity = 10;

  insertBook(head, newBook);

  searchBook(head, "To Kill a Mockingbird");

  return 0;
}