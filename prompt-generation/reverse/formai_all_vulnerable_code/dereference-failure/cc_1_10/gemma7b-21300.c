//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: optimized
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
void displayBooks(Book* head);
void searchBooks(Book* head, char* title);

int main() {
  Book* head = NULL;
  Book* newBook = NULL;

  // Inserting some books
  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "The Lord of the Flies");
  strcpy(newBook->author, "William Golding");
  newBook->quantity = 5;
  insertBook(head, newBook);

  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "To Kill a Mockingbird");
  strcpy(newBook->author, "Harper Lee");
  newBook->quantity = 3;
  insertBook(head, newBook);

  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "The Great Gatsby");
  strcpy(newBook->author, "F. Scott Fitzgerald");
  newBook->quantity = 2;
  insertBook(head, newBook);

  // Displaying all books
  displayBooks(head);

  // Searching for a book
  searchBooks(head, "The Lord of the Flies");

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

void displayBooks(Book* head) {
  while (head) {
    printf("%s by %s (Quantity: %d)\n", head->title, head->author, head->quantity);
    head = head->next;
  }
}

void searchBooks(Book* head, char* title) {
  while (head) {
    if (strcmp(head->title, title) == 0) {
      printf("Book found: %s by %s (Quantity: %d)\n", head->title, head->author, head->quantity);
    }
    head = head->next;
  }
  printf("Book not found.\n");
}