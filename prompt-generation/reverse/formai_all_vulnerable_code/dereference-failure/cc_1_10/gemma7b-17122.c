//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10

struct Book {
  char title[50];
  char author[50];
  char genre[50];
  int pages;
  struct Book* next;
};

struct Book* createBook(char* title, char* author, char* genre, int pages) {
  struct Book* book = malloc(sizeof(struct Book));
  strcpy(book->title, title);
  strcpy(book->author, author);
  strcpy(book->genre, genre);
  book->pages = pages;
  book->next = NULL;
  return book;
}

void addBook(struct Book* head, char* title, char* author, char* genre, int pages) {
  struct Book* newBook = createBook(title, author, genre, pages);
  if (head == NULL) {
    head = newBook;
  } else {
    struct Book* currentBook = head;
    while (currentBook->next) {
      currentBook = currentBook->next;
    }
    currentBook->next = newBook;
  }
}

void printBooks(struct Book* head) {
  struct Book* currentBook = head;
  while (currentBook) {
    printf("Title: %s\n", currentBook->title);
    printf("Author: %s\n", currentBook->author);
    printf("Genre: %s\n", currentBook->genre);
    printf("Pages: %d\n", currentBook->pages);
    printf("\n");
    currentBook = currentBook->next;
  }
}

int main() {
  struct Book* head = NULL;
  addBook(head, "The Lord of the Flies", "William Golding", "Coming-of-Age", 200);
  addBook(head, "To Kill a Mockingbird", "Harper Lee", "Classic Fiction", 320);
  addBook(head, "The Great Gatsby", "F. Scott Fitzgerald", "Jazz", 250);

  printBooks(head);

  return 0;
}