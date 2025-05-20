//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_AUTHORS 50

struct book {
  char title[50];
  char author[50];
  int quantity;
  struct book* next;
};

struct author {
  char name[50];
  struct author* next;
  struct book** books;
};

void insertBook(struct book** head, char* title, char* author, int quantity) {
  struct book* newBook = malloc(sizeof(struct book));
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

void insertAuthor(struct author** head, char* name) {
  struct author* newAuthor = malloc(sizeof(struct author));
  strcpy(newAuthor->name, name);
  newAuthor->next = NULL;
  newAuthor->books = NULL;

  if (*head == NULL) {
    *head = newAuthor;
  } else {
    (*head)->next = newAuthor;
  }
}

void searchBook(struct book* head, char* title) {
  while (head) {
    if (strcmp(head->title, title) == 0) {
      printf("Title: %s\n", head->title);
      printf("Author: %s\n", head->author);
      printf("Quantity: %d\n", head->quantity);
      break;
    }
    head = head->next;
  }
  if (head == NULL) {
    printf("Book not found.\n");
  }
}

int main() {
  struct book* bookHead = NULL;
  struct author* authorHead = NULL;

  insertBook(&bookHead, "The Lord of the Flies", "William Golding", 5);
  insertBook(&bookHead, "The Great Gatsby", "F. Scott Fitzgerald", 3);
  insertBook(&bookHead, "The Catcher in the Rye", "J.D. Salinger", 2);
  insertBook(&bookHead, "To Kill a Mockingbird", "Harper Lee", 4);

  insertAuthor(&authorHead, "William Golding");
  insertAuthor(&authorHead, "F. Scott Fitzgerald");
  insertAuthor(&authorHead, "J.D. Salinger");
  insertAuthor(&authorHead, "Harper Lee");

  searchBook(bookHead, "The Lord of the Flies");
  searchBook(bookHead, "The Great Gatsby");

  return 0;
}