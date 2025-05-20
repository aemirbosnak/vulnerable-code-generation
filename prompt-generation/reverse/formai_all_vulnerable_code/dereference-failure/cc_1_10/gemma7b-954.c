//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

struct book {
  char title[50];
  char author[50];
  int quantity;
  struct book* next;
};

struct book* createBook(char* title, char* author, int quantity) {
  struct book* newBook = (struct book*)malloc(sizeof(struct book));
  strcpy(newBook->title, title);
  strcpy(newBook->author, author);
  newBook->quantity = quantity;
  newBook->next = NULL;
  return newBook;
}

void addBook(struct book* head, char* title, char* author, int quantity) {
  struct book* newBook = createBook(title, author, quantity);
  if (head == NULL) {
    head = newBook;
  } else {
    struct book* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newBook;
  }
}

void searchBook(struct book* head, char* title) {
  struct book* temp = head;
  while (temp) {
    if (strcmp(temp->title, title) == 0) {
      printf("Title: %s\n", temp->title);
      printf("Author: %s\n", temp->author);
      printf("Quantity: %d\n", temp->quantity);
      break;
    }
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Book not found.\n");
  }
}

int main() {
  struct book* head = NULL;

  addBook(head, "The Lord of the Flies", "William Golding", 5);
  addBook(head, "To Kill a Mockingbird", "Harper Lee", 10);
  addBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 7);

  searchBook(head, "The Lord of the Flies");

  return 0;
}