//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct book {
  char title[50];
  char author[50];
  int quantity;
  float price;
  struct book* next;
};

struct book* insertBook(struct book* head, char* title, char* author, int quantity, float price) {
  struct book* newNode = (struct book*)malloc(sizeof(struct book));
  strcpy(newNode->title, title);
  strcpy(newNode->author, author);
  newNode->quantity = quantity;
  newNode->price = price;
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  } else {
    head->next = newNode;
    return head;
  }
}

void searchBook(struct book* head, char* title) {
  struct book* currentBook = head;

  while (currentBook) {
    if (strcmp(currentBook->title, title) == 0) {
      printf("Title: %s\n", currentBook->title);
      printf("Author: %s\n", currentBook->author);
      printf("Quantity: %d\n", currentBook->quantity);
      printf("Price: %.2f\n", currentBook->price);
    }
    currentBook = currentBook->next;
  }
}

int main() {
  struct book* head = NULL;

  insertBook(head, "The Lord of the Flies", "William Golding", 50, 10.0);
  insertBook(head, "To Kill a Mockingbird", "Harper Lee", 20, 12.0);
  insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 30, 15.0);

  searchBook(head, "To Kill a Mockingbird");

  return 0;
}