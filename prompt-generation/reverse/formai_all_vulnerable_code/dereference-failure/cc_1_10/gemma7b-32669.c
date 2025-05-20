//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Book {
  char title[20];
  char author[20];
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

Book* searchBook(Book* head, char* title) {
  while (head) {
    if (strcmp(head->title, title) == 0) {
      return head;
    }
    head = head->next;
  }
  return NULL;
}

int main() {
  Book* head = NULL;
  Book* newBook;

  // Insert some books
  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "The Lord of the Flies");
  strcpy(newBook->author, "William Golding");
  newBook->year = 1954;
  insertBook(head, newBook);

  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "To Kill a Mockingbird");
  strcpy(newBook->author, "Harper Lee");
  newBook->year = 1960;
  insertBook(head, newBook);

  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "The Great Gatsby");
  strcpy(newBook->author, "F. Scott Fitzgerald");
  newBook->year = 1925;
  insertBook(head, newBook);

  // Search for a book
  newBook = searchBook(head, "To Kill a Mockingbird");
  if (newBook) {
    printf("Title: %s\n", newBook->title);
    printf("Author: %s\n", newBook->author);
    printf("Year: %d\n", newBook->year);
  } else {
    printf("Book not found.\n");
  }

  return 0;
}