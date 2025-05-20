//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: secure
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

Book* insertBook(Book* head, Book* newBook) {
  if (head == NULL) {
    head = newBook;
  } else {
    newBook->next = head;
    head = newBook;
  }
  return head;
}

Book* findBook(Book* head, char* title) {
  Book* currentBook = head;
  while (currentBook) {
    if (strcmp(currentBook->title, title) == 0) {
      return currentBook;
    }
    currentBook = currentBook->next;
  }
  return NULL;
}

void updateBookQuantity(Book* book, int quantity) {
  book->quantity = quantity;
}

void deleteBook(Book* head, char* title) {
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
      return;
    }
    previousBook = currentBook;
    currentBook = currentBook->next;
  }
  return;
}

int main() {
  Book* head = NULL;

  // Insert some books
  Book* newBook1 = malloc(sizeof(Book));
  strcpy(newBook1->title, "The Lord of the Flies");
  strcpy(newBook1->author, "William Golding");
  newBook1->quantity = 5;
  insertBook(head, newBook1);

  Book* newBook2 = malloc(sizeof(Book));
  strcpy(newBook2->title, "The Great Gatsby");
  strcpy(newBook2->author, "F. Scott Fitzgerald");
  newBook2->quantity = 3;
  insertBook(head, newBook2);

  // Find a book
  Book* foundBook = findBook(head, "The Lord of the Flies");
  if (foundBook) {
    printf("Title: %s\n", foundBook->title);
    printf("Author: %s\n", foundBook->author);
    printf("Quantity: %d\n", foundBook->quantity);
  } else {
    printf("Book not found.\n");
  }

  // Update book quantity
  updateBookQuantity(foundBook, 10);

  // Delete a book
  deleteBook(head, "The Great Gatsby");

  // Print updated list of books
  Book* currentBook = head;
  while (currentBook) {
    printf("Title: %s\n", currentBook->title);
    printf("Author: %s\n", currentBook->author);
    printf("Quantity: %d\n", currentBook->quantity);
    printf("\n");
    currentBook = currentBook->next;
  }

  return 0;
}