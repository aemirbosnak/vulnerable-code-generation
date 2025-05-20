//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: artistic
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

Book* insertBook(Book* head, char* title, char* author, int quantity) {
  Book* newBook = (Book*)malloc(sizeof(Book));
  strcpy(newBook->title, title);
  strcpy(newBook->author, author);
  newBook->quantity = quantity;
  newBook->next = NULL;

  if (head == NULL) {
    head = newBook;
  } else {
    Book* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newBook;
  }

  return head;
}

Book* searchBook(Book* head, char* title) {
  Book* temp = head;
  while (temp) {
    if (strcmp(temp->title, title) == 0) {
      return temp;
    }
    temp = temp->next;
  }

  return NULL;
}

void displayBooks(Book* head) {
  Book* temp = head;
  while (temp) {
    printf("%s by %s, Quantity: %d\n", temp->title, temp->author, temp->quantity);
    temp = temp->next;
  }
}

int main() {
  Book* head = NULL;

  insertBook(head, "The Lord of the Flies", "William Golding", 5);
  insertBook(head, "To Kill a Mockingbird", "Harper Lee", 10);
  insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 7);

  displayBooks(head);

  Book* book = searchBook(head, "To Kill a Mockingbird");
  if (book) {
    printf("Book found: %s by %s, Quantity: %d\n", book->title, book->author, book->quantity);
  } else {
    printf("Book not found.\n");
  }

  return 0;
}