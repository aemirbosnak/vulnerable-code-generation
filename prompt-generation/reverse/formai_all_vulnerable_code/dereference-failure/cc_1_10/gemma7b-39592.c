//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: mind-bending
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

struct Library {
  struct Book* head;
  struct Book* tail;
  int numBooks;
  int searchIndex;
};

void insertBook(struct Library* lib, char* title, char* author, int quantity) {
  struct Book* newBook = malloc(sizeof(struct Book));
  strcpy(newBook->title, title);
  strcpy(newBook->author, author);
  newBook->quantity = quantity;
  newBook->next = NULL;

  if (lib->head == NULL) {
    lib->head = newBook;
    lib->tail = newBook;
  } else {
    lib->tail->next = newBook;
    lib->tail = newBook;
  }

  lib->numBooks++;
}

void searchBook(struct Library* lib, char* title) {
  lib->searchIndex = -1;
  struct Book* currentBook = lib->head;

  while (currentBook) {
    if (strcmp(currentBook->title, title) == 0) {
      lib->searchIndex = currentBook - lib->head;
      break;
    }
    currentBook = currentBook->next;
  }
}

int main() {
  struct Library library;
  library.head = NULL;
  library.tail = NULL;
  library.numBooks = 0;
  library.searchIndex = -1;

  insertBook(&library, "The Lord of the Flies", "William Golding", 5);
  insertBook(&library, "The Great Gatsby", "F. Scott Fitzgerald", 10);
  insertBook(&library, "To Kill a Mockingbird", "Harper Lee", 7);

  searchBook(&library, "The Great Gatsby");

  if (library.searchIndex != -1) {
    printf("Book found at index: %d\n", library.searchIndex);
  } else {
    printf("Book not found.\n");
  }

  return 0;
}