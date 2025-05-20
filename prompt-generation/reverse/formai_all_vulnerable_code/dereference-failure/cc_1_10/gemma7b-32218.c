//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_AUTHOR 50

struct Book {
  char title[50];
  char author[50];
  int quantity;
  int available;
  struct Book* next;
};

struct Author {
  char name[50];
  struct Author* next;
  struct Book** books;
};

struct Library {
  struct Author** authors;
  int numAuthors;
  int numBooks;
  struct Book** books;
};

void insertBook(struct Library* lib, char* title, char* author, int quantity) {
  struct Book* newBook = malloc(sizeof(struct Book));
  strcpy(newBook->title, title);
  strcpy(newBook->author, author);
  newBook->quantity = quantity;
  newBook->available = 1;
  newBook->next = NULL;

  if (lib->numBooks == 0) {
    lib->books = malloc(sizeof(struct Book*));
    lib->books[0] = newBook;
  } else {
    lib->books[lib->numBooks++] = newBook;
  }
}

void insertAuthor(struct Library* lib, char* name) {
  struct Author* newAuthor = malloc(sizeof(struct Author));
  strcpy(newAuthor->name, name);
  newAuthor->next = NULL;
  newAuthor->books = NULL;

  if (lib->numAuthors == 0) {
    lib->authors = malloc(sizeof(struct Author*));
    lib->authors[0] = newAuthor;
  } else {
    lib->authors[lib->numAuthors++] = newAuthor;
  }
}

void searchBook(struct Library* lib, char* title) {
  for (struct Book* book = lib->books; book; book = book->next) {
    if (strcmp(book->title, title) == 0) {
      printf("Title: %s\n", book->title);
      printf("Author: %s\n", book->author);
      printf("Quantity: %d\n", book->quantity);
      printf("Available: %d\n", book->available);
      break;
    }
  }
}

int main() {
  struct Library* lib = malloc(sizeof(struct Library));
  lib->numAuthors = 0;
  lib->numBooks = 0;
  lib->authors = NULL;
  lib->books = NULL;

  insertBook(lib, "The Lord of the Flies", "William Golding", 5);
  insertBook(lib, "The Great Gatsby", "F. Scott Fitzgerald", 3);
  insertBook(lib, "To Kill a Mockingbird", "Harper Lee", 4);

  insertAuthor(lib, "William Golding");
  insertAuthor(lib, "F. Scott Fitzgerald");
  insertAuthor(lib, "Harper Lee");

  searchBook(lib, "The Lord of the Flies");

  return 0;
}