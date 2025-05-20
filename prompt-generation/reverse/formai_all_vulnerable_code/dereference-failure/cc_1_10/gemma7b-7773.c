//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

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
  Book* newBook;

  // Inserting books
  newBook = (Book*)malloc(sizeof(Book));
  strcpy(newBook->title, "The Lord of the Flies");
  strcpy(newBook->author, "William Golding");
  newBook->quantity = 5;
  head = insertBook(head, newBook);

  newBook = (Book*)malloc(sizeof(Book));
  strcpy(newBook->title, "To Kill a Mockingbird");
  strcpy(newBook->author, "Harper Lee");
  newBook->quantity = 7;
  insertBook(head, newBook);

  newBook = (Book*)malloc(sizeof(Book));
  strcpy(newBook->title, "The Great Gatsby");
  strcpy(newBook->author, "F. Scott Fitzgerald");
  newBook->quantity = 3;
  insertBook(head, newBook);

  // Displaying books
  displayBooks(head);

  // Searching books
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
  Book* currentBook = head;

  while (currentBook) {
    printf("%s by %s, Quantity: %d\n", currentBook->title, currentBook->author, currentBook->quantity);
    currentBook = currentBook->next;
  }
}

void searchBooks(Book* head, char* title) {
  Book* currentBook = head;

  while (currentBook) {
    if (strcmp(currentBook->title, title) == 0) {
      printf("%s by %s, Quantity: %d\n", currentBook->title, currentBook->author, currentBook->quantity);
    }
    currentBook = currentBook->next;
  }
}