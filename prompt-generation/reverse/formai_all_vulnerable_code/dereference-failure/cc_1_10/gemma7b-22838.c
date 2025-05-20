//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
  char title[50];
  char author[50];
  int quantity;
  float price;
  struct Book* next;
};

struct Library {
  struct Book* head;
  int numBooks;
  struct Library* next;
};

void insertBook(struct Library* lib, char* title, char* author, int quantity, float price) {
  struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
  strcpy(newBook->title, title);
  strcpy(newBook->author, author);
  newBook->quantity = quantity;
  newBook->price = price;
  newBook->next = NULL;

  if (lib->head == NULL) {
    lib->head = newBook;
  } else {
    struct Book* tempBook = lib->head;
    while (tempBook->next) {
      tempBook = tempBook->next;
    }
    tempBook->next = newBook;
  }
  lib->numBooks++;
}

void searchBook(struct Library* lib, char* title) {
  struct Book* currentBook = lib->head;
  while (currentBook) {
    if (strcmp(currentBook->title, title) == 0) {
      printf("Title: %s\n", currentBook->title);
      printf("Author: %s\n", currentBook->author);
      printf("Quantity: %d\n", currentBook->quantity);
      printf("Price: %.2f\n", currentBook->price);
      break;
    }
    currentBook = currentBook->next;
  }
  if (currentBook == NULL) {
    printf("Book not found.\n");
  }
}

int main() {
  struct Library* library = (struct Library*)malloc(sizeof(struct Library));
  library->head = NULL;
  library->numBooks = 0;
  library->next = NULL;

  insertBook(library, "The Lord of the Flies", "William Golding", 50, 12.50);
  insertBook(library, "To Kill a Mockingbird", "Harper Lee", 20, 15.00);
  insertBook(library, "The Great Gatsby", "F. Scott Fitzgerald", 30, 18.00);

  searchBook(library, "The Lord of the Flies");

  return 0;
}