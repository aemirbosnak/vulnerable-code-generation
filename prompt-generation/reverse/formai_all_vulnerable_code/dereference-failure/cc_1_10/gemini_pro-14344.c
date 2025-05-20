//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOK_SIZE 1000000

typedef struct {
  char *title;
  char *author;
  int num_pages;
  char *text;
} Book;

Book *create_book(char *title, char *author, int num_pages, char *text) {
  Book *book = malloc(sizeof(Book));
  book->title = malloc(strlen(title) + 1);
  strcpy(book->title, title);
  book->author = malloc(strlen(author) + 1);
  strcpy(book->author, author);
  book->num_pages = num_pages;
  book->text = malloc(strlen(text) + 1);
  strcpy(book->text, text);
  return book;
}

void free_book(Book *book) {
  free(book->title);
  free(book->author);
  free(book->text);
  free(book);
}

int main() {
  // Create a new book
  Book *book = create_book(
      "The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 183,
      "The Hitchhiker's Guide to the Galaxy is a comedy science fiction trilogy by Douglas Adams. Originally a radio comedy broadcast on BBC Radio 4 in 1978, it was later adapted into a series of five books. The novels have been translated into more than 30 languages and have sold more than 15 million copies worldwide.");

  // Print the book's title
  printf("Title: %s\n", book->title);

  // Print the book's author
  printf("Author: %s\n", book->author);

  // Print the book's number of pages
  printf("Number of pages: %d\n", book->num_pages);

  // Print the first page of the book
  printf("First page:\n%s\n", book->text);

  // Free the book
  free_book(book);

  return 0;
}