//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
  char *title;
  char *author;
  int numPages;
  char *content;
};

struct Library {
  struct Book *books;
  int numBooks;
};

struct Library *createLibrary(int numBooks) {
  struct Library *library = malloc(sizeof(struct Library));
  library->books = malloc(sizeof(struct Book) * numBooks);
  library->numBooks = numBooks;
  return library;
}

void addBookToLibrary(struct Library *library, struct Book *book) {
  library->books[library->numBooks++] = *book;
}

struct Book *getBookFromLibrary(struct Library *library, char *title) {
  for (int i = 0; i < library->numBooks; i++) {
    if (strcmp(library->books[i].title, title) == 0) {
      return &library->books[i];
    }
  }
  return NULL;
}

void printBook(struct Book *book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Number of Pages: %d\n", book->numPages);
  printf("Content:\n%s", book->content);
}

int main() {
  // Create a library
  struct Library *library = createLibrary(3);

  // Add books to the library
  struct Book book1 = {"Book 1", "Author 1", 100, "This is the content of book 1."};
  addBookToLibrary(library, &book1);

  struct Book book2 = {"Book 2", "Author 2", 200, "This is the content of book 2."};
  addBookToLibrary(library, &book2);

  struct Book book3 = {"Book 3", "Author 3", 300, "This is the content of book 3."};
  addBookToLibrary(library, &book3);

  // Get a book from the library
  struct Book *book = getBookFromLibrary(library, "Book 2");

  // Print the book
  printBook(book);

  return 0;
}