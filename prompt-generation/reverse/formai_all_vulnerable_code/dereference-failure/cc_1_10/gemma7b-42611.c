//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
  char title[256];
  char author[256];
  char genre[256];
  int pages;
  int rating;
};

struct Node {
  struct Book book;
  struct Node* next;
};

void insertBook(struct Node** head, struct Book book) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->book = book;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void searchBook(struct Node* head, char* title) {
  while (head) {
    if (strcmp(head->book.title, title) == 0) {
      printf("Book title: %s\n", head->book.title);
      printf("Book author: %s\n", head->book.author);
      printf("Book genre: %s\n", head->book.genre);
      printf("Number of pages: %d\n", head->book.pages);
      printf("Book rating: %d\n", head->book.rating);
      return;
    }
    head = head->next;
  }

  printf("Book not found.\n");
}

int main() {
  struct Node* head = NULL;

  struct Book book1 = {"The Lord of the Flies", "William Golding", "Classic", 200, 9};
  insertBook(&head, book1);

  struct Book book2 = {"The Great Gatsby", "F. Scott Fitzgerald", "Classic", 180, 8};
  insertBook(&head, book2);

  struct Book book3 = {"To Kill a Mockingbird", "Harper Lee", "Classic", 220, 10};
  insertBook(&head, book3);

  searchBook(head, "The Lord of the Flies");

  return 0;
}