//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: paranoid
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

struct Book* insertBook(struct Book* head, char* title, char* author, int quantity) {
  struct Book* newNode = (struct Book*)malloc(sizeof(struct Book));
  newNode->quantity = quantity;
  strcpy(newNode->title, title);
  strcpy(newNode->author, author);

  if (head == NULL) {
    head = newNode;
  } else {
    struct Book* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
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

  insertBook(head, "The Lord of the Flies", "William Golding", 10);
  insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 5);
  insertBook(head, "To Kill a Mockingbird", "Harper Lee", 7);

  struct Book* book = searchBook(head, "The Great Gatsby");
  if (book) {
    printf("Book title: %s\n", book->title);
    printf("Book author: %s\n", book->author);
    printf("Book quantity: %d\n", book->quantity);
  } else {
    printf("Book not found.\n");
  }

  return 0;
}