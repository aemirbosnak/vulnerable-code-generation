//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct Book {
  char title[50];
  char author[50];
  int year;
  struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook) {
  if (head == NULL) {
    head = newBook;
  } else {
    head->next = insertBook(head->next, newBook);
  }
  return head;
}

int searchBook(Book* head, char* title) {
  while (head) {
    if (strcmp(head->title, title) == 0) {
      return 1;
    }
    head = head->next;
  }
  return 0;
}

int main() {
  Book* head = NULL;
  Book* newBook = NULL;

  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "Pride and Prejudice");
  strcpy(newBook->author, "Jane Austen");
  newBook->year = 1816;

  insertBook(head, newBook);

  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "Sense and Sensibility");
  strcpy(newBook->author, "Jane Austen");
  newBook->year = 1811;

  insertBook(head, newBook);

  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "Oliver Twist");
  strcpy(newBook->author, "Charles Dickens");
  newBook->year = 1838;

  insertBook(head, newBook);

  if (searchBook(head, "Pride and Prejudice") == 1) {
    printf("Book found!\n");
  } else {
    printf("Book not found.\n");
  }

  return 0;
}