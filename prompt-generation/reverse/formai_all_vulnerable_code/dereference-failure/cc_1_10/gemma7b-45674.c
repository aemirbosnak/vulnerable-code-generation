//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
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

Book* insertBook(Book* head, Book* newBook);
Book* findBook(Book* head, char* title);
void updateQuantity(Book* head, char* title, int quantity);
void deleteBook(Book* head, char* title);

int main() {
  Book* head = NULL;

  // Insert some books
  Book* newBook1 = malloc(sizeof(Book));
  strcpy(newBook1->title, "The Lord of the Flies");
  strcpy(newBook1->author, "William Golding");
  newBook1->quantity = 5;
  head = insertBook(head, newBook1);

  Book* newBook2 = malloc(sizeof(Book));
  strcpy(newBook2->title, "To Kill a Mockingbird");
  strcpy(newBook2->author, "Harper Lee");
  newBook2->quantity = 3;
  head = insertBook(head, newBook2);

  Book* newBook3 = malloc(sizeof(Book));
  strcpy(newBook3->title, "The Great Gatsby");
  strcpy(newBook3->author, "F. Scott Fitzgerald");
  newBook3->quantity = 2;
  head = insertBook(head, newBook3);

  // Find a book
  Book* foundBook = findBook(head, "The Lord of the Flies");
  if (foundBook) {
    printf("Found book: %s by %s, quantity: %d\n", foundBook->title, foundBook->author, foundBook->quantity);
  } else {
    printf("Book not found.\n");
  }

  // Update quantity
  updateQuantity(head, "To Kill a Mockingbird", 5);
  foundBook = findBook(head, "To Kill a Mockingbird");
  if (foundBook) {
    printf("Updated quantity: %s by %s, quantity: %d\n", foundBook->title, foundBook->author, foundBook->quantity);
  } else {
    printf("Book not found.\n");
  }

  // Delete book
  deleteBook(head, "The Great Gatsby");
  foundBook = findBook(head, "The Great Gatsby");
  if (foundBook) {
    printf("Book deleted: %s by %s\n", foundBook->title, foundBook->author);
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

Book* findBook(Book* head, char* title) {
  while (head) {
    if (strcmp(head->title, title) == 0) {
      return head;
    }
    head = head->next;
  }
  return NULL;
}

void updateQuantity(Book* head, char* title, int quantity) {
  Book* foundBook = findBook(head, title);
  if (foundBook) {
    foundBook->quantity = quantity;
  }
}

void deleteBook(Book* head, char* title) {
  Book* prevBook = NULL;
  Book* currentBook = head;

  while (currentBook) {
    if (strcmp(currentBook->title, title) == 0) {
      if (prevBook) {
        prevBook->next = currentBook->next;
      } else {
        head = currentBook->next;
      }
      free(currentBook);
      currentBook = NULL;
    } else {
      prevBook = currentBook;
      currentBook = currentBook->next;
    }
  }
}