//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BOOKS 100

typedef struct Book {
  char title[256];
  char author[256];
  int pages;
  struct Book* next;
} Book;

Book* createBook(char* title, char* author, int pages) {
  Book* newBook = malloc(sizeof(Book));
  strcpy(newBook->title, title);
  strcpy(newBook->author, author);
  newBook->pages = pages;
  newBook->next = NULL;

  return newBook;
}

Book* addBook(Book* head, char* title, char* author, int pages) {
  Book* newBook = createBook(title, author, pages);

  if (head == NULL) {
    head = newBook;
  } else {
    Book* currentBook = head;
    while (currentBook->next) {
      currentBook = currentBook->next;
    }
    currentBook->next = newBook;
  }

  return head;
}

void displayBooks(Book* head) {
  Book* currentBook = head;
  while (currentBook) {
    printf("%s by %s (%d pages)\n", currentBook->title, currentBook->author, currentBook->pages);
    currentBook = currentBook->next;
  }
}

int main() {
  Book* head = NULL;
  head = addBook(head, "The Lord of the Flies", "William Golding", 200);
  head = addBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 180);
  head = addBook(head, "To Kill a Mockingbird", "Harper Lee", 220);

  displayBooks(head);

  return 0;
}