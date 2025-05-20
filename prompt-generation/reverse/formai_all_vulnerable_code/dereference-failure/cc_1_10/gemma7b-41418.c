//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
  char title[50];
  char author[50];
  int quantity;
  struct Book* next;
};

struct Book* createBook(char* title, char* author, int quantity) {
  struct Book* book = (struct Book*)malloc(sizeof(struct Book));
  strcpy(book->title, title);
  strcpy(book->author, author);
  book->quantity = quantity;
  book->next = NULL;
  return book;
}

void displayBooks(struct Book* head) {
  while (head) {
    printf("%s by %s, Quantity: %d\n", head->title, head->author, head->quantity);
    head = head->next;
  }
}

void searchBooks(struct Book* head, char* title) {
  while (head) {
    if (strcmp(head->title, title) == 0) {
      printf("%s by %s, Quantity: %d\n", head->title, head->author, head->quantity);
    }
    head = head->next;
  }
}

int main() {
  struct Book* head = NULL;
  head = createBook("The Lord of the Flies", "William Golding", 5);
  head = createBook("To Kill a Mockingbird", "Harper Lee", 10);
  head = createBook("The Great Gatsby", "F. Scott Fitzgerald", 7);

  displayBooks(head);

  searchBooks(head, "To Kill a Mockingbird");

  return 0;
}