//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_AUTHORS 10

struct Book {
  char title[50];
  char author[50];
  int quantity;
  struct Book* next;
};

struct Author {
  char name[50];
  struct Author* next;
  struct Book** books;
};

void insertBook(struct Book** head, char* title, char* author, int quantity) {
  struct Book* newBook = malloc(sizeof(struct Book));
  strcpy(newBook->title, title);
  strcpy(newBook->author, author);
  newBook->quantity = quantity;
  newBook->next = NULL;

  if (*head == NULL) {
    *head = newBook;
  } else {
    (*head)->next = newBook;
  }
}

void insertAuthor(struct Author** head, char* name) {
  struct Author* newAuthor = malloc(sizeof(struct Author));
  strcpy(newAuthor->name, name);
  newAuthor->next = NULL;
  newAuthor->books = NULL;

  if (*head == NULL) {
    *head = newAuthor;
  } else {
    (*head)->next = newAuthor;
  }
}

void searchBook(struct Book* head, char* title) {
  while (head) {
    if (strcmp(head->title, title) == 0) {
      printf("Book: %s, Author: %s, Quantity: %d\n", head->title, head->author, head->quantity);
    }
    head = head->next;
  }
}

int main() {
  struct Book* books = NULL;
  struct Author* authors = NULL;

  insertBook(&books, "The Lord of the Flies", "William Golding", 10);
  insertBook(&books, "The Great Gatsby", "F. Scott Fitzgerald", 5);
  insertBook(&books, "To Kill a Mockingbird", "Harper Lee", 7);

  insertAuthor(&authors, "William Golding");
  insertAuthor(&authors, "F. Scott Fitzgerald");
  insertAuthor(&authors, "Harper Lee");

  searchBook(books, "The Lord of the Flies");

  return 0;
}