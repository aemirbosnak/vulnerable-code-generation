//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: grateful
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

struct Book* insertBook(struct Book* head, struct Book* newBook) {
  if (head == NULL) {
    head = newBook;
  } else {
    struct Book* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newBook;
  }
  return head;
}

struct Book* searchBook(struct Book* head, char* title) {
  struct Book* temp = head;
  while (temp) {
    if (strcmp(temp->title, title) == 0) {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

int main() {
  struct Book* head = NULL;
  struct Book* newBook;

  // Inserting books
  newBook = malloc(sizeof(struct Book));
  strcpy(newBook->title, "The Lord of the Flies");
  strcpy(newBook->author, "William Golding");
  newBook->quantity = 10;
  newBook->price = 12.50;
  insertBook(head, newBook);

  newBook = malloc(sizeof(struct Book));
  strcpy(newBook->title, "To Kill a Mockingbird");
  strcpy(newBook->author, "Harper Lee");
  newBook->quantity = 8;
  newBook->price = 10.00;
  insertBook(head, newBook);

  // Searching for a book
  newBook = searchBook(head, "To Kill a Mockingbird");
  if (newBook) {
    printf("Title: %s\n", newBook->title);
    printf("Author: %s\n", newBook->author);
    printf("Quantity: %d\n", newBook->quantity);
    printf("Price: %.2f\n", newBook->price);
  } else {
    printf("Book not found.\n");
  }

  return 0;
}