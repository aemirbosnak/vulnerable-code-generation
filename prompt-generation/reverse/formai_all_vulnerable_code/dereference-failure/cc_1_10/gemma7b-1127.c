//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
  char title[50];
  char author[50];
  int quantity;
  struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook);
Book* searchBook(Book* head, char* title);
Book* deleteBook(Book* head, char* title);

int main() {
  Book* head = NULL;
  Book* newBook = NULL;

  // Insert some books
  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "The Lord of the Flies");
  strcpy(newBook->author, "William Golding");
  newBook->quantity = 5;
  insertBook(head, newBook);

  newBook = malloc(sizeof(Book));
  strcpy(newBook->title, "The Great Gatsby");
  strcpy(newBook->author, "F. Scott Fitzgerald");
  newBook->quantity = 3;
  insertBook(head, newBook);

  // Search for a book
  newBook = searchBook(head, "The Lord of the Flies");
  if (newBook) {
    printf("Book found: %s by %s\n", newBook->title, newBook->author);
  } else {
    printf("Book not found.\n");
  }

  // Delete a book
  deleteBook(head, "The Great Gatsby");
  newBook = searchBook(head, "The Great Gatsby");
  if (newBook) {
    printf("Book found: %s by %s\n", newBook->title, newBook->author);
  } else {
    printf("Book not found.\n");
  }

  return 0;
}

Book* insertBook(Book* head, Book* newBook) {
  if (head == NULL) {
    head = newBook;
  } else {
    newBook->next = head;
    head = newBook;
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

Book* deleteBook(Book* head, char* title) {
  Book* previousBook = NULL;
  Book* currentBook = head;

  while (currentBook) {
    if (strcmp(currentBook->title, title) == 0) {
      if (previousBook) {
        previousBook->next = currentBook->next;
      } else {
        head = currentBook->next;
      }
      free(currentBook);
      return head;
    }
    previousBook = currentBook;
    currentBook = currentBook->next;
  }
  return NULL;
}