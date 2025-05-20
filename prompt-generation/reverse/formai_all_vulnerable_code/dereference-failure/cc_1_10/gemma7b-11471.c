//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: intelligent
#include <stdio.h>
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

  Book* newBook3 = malloc(sizeof(Book));
  strcpy(newBook3->title, "The Catcher in the Rye");
  strcpy(newBook3->author, "J.D. Salinger");
  newBook3->quantity = 2;
  insertBook(head, newBook3);

  // Search for a book
  Book* foundBook = searchBook(head, "The Lord of the Flies");

  if (foundBook) {
    printf("Book found: %s by %s\n", foundBook->title, foundBook->author);
  } else {
    printf("Book not found.\n");
  }

  return 0;
}