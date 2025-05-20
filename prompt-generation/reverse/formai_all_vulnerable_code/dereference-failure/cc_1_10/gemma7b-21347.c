//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_AUTHOR 50

struct Book {
  char title[50];
  char author[50];
  int quantity;
  struct Book* next;
};

struct Author {
  char name[50];
  struct Book* books;
  struct Author* next;
};

void insertBook(struct Book** head, char* title, char* author, int quantity) {
  struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
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
  struct Author* newAuthor = (struct Author*)malloc(sizeof(struct Author));
  strcpy(newAuthor->name, name);
  newAuthor->books = NULL;
  newAuthor->next = NULL;

  if (*head == NULL) {
    *head = newAuthor;
  } else {
    (*head)->next = newAuthor;
  }
}

void searchBook(struct Book* head, char* title) {
  while (head) {
    if (strcmp(head->title, title) == 0) {
      printf("Title: %s\n", head->title);
      printf("Author: %s\n", head->author);
      printf("Quantity: %d\n", head->quantity);
      return;
    }
    head = head->next;
  }
  printf("Book not found.\n");
}

void main() {
  struct Book* bookHead = NULL;
  struct Author* authorHead = NULL;

  insertBook(&bookHead, "The Lord of the Flies", "William Golding", 5);
  insertBook(&bookHead, "To Kill a Mockingbird", "Harper Lee", 10);
  insertBook(&bookHead, "The Great Gatsby", "F. Scott Fitzgerald", 7);

  insertAuthor(&authorHead, "William Golding");
  insertAuthor(&authorHead, "Harper Lee");
  insertAuthor(&authorHead, "F. Scott Fitzgerald");

  searchBook(bookHead, "The Lord of the Flies");
  searchBook(bookHead, "To Kill a Mockingbird");
  searchBook(bookHead, "The Great Gatsby");
  searchBook(bookHead, "Book not found");
}